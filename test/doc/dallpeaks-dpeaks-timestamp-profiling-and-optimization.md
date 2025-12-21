## dallpeaks/dpeaks 时间戳剖析与性能优化记录（QHYCCD 场景）

### 背景

现场日志显示在：

- `QHYCCD | dallpeaks`
- `Failed to find (5x5) centroid ...`

两行之间耗时显著（约 0.7s），需要定位并优化。

本次采用 `solve-field --timestamp` 的方式进行时间线定位：**`--timestamp` 只是给每条 log 加前缀**（`[pid: seconds_since_start]`），因此“中间没有时间戳输出”并不代表没执行代码，只代表中间没有 log 输出。

### 目标

- 在 `GLUE(dallpeaks, SUFFIX)` 内增加关键路径耗时拆分，定位瓶颈。
- 将耗时最大的子步骤进行优化，并保留 A/B 对比能力。
- 在问题解决后，降低日志噪声，只保留低噪声回归信息。

### 定位：dallpeaks 分段计时

对 `util/dallpeaks.inc` 中的 `GLUE(dallpeaks, SUFFIX)` 增加 `timenow()` 计时并用 `logverb()` 输出（配合 `--timestamp` 自动带前缀）：

- `permuted_sort(object, ...)`：连通域像素按 object id 分组的索引排序
- 每个 object 的 bbox 扫描（统计）
- cutout 拷贝（统计）
- `dsmooth2()`（统计）
- `dpeaks()`（统计）
- `max_gaussian()`（仅在 centroid 失败时统计）
- 结束时输出汇总 `timing summary`（包含失败计数）

补充：为避免刷屏，增加了阈值（默认 0.05s）——单次 `dsmooth2/dpeaks` 超过阈值才输出该 object 的耗时行。

### 结论：瓶颈在 dpeaks(checkpeaks->dfind2)

通过在 `util/dpeaks.c` 内部分段计时，将 `dpeaks` 拆成：

- `smooth/copy`
- `findpeaks`（3x3 局部极值扫描）
- `sort`（peaks 排序）
- `checkpeaks`：mask 生成 / `dfind2` 连通域 / join 判断
- `close`（距离剔除）

实测输出（示例）表明：

- `check(dfind2)` 占绝大多数时间（~0.713s / 0.786s）
- `check(mask)` 次之（~0.070s）

这说明旧实现为 **“对每个 peak 重新整图做一次 mask + dfind2”**，复杂度近似 \(O(npeaks \times nx \times ny)\)。

### 优化：将 checkpeaks 从 per-peak dfind2 改为一次性 Union-Find

`dfind2()` 的连通性规则是 **8 邻域**（包含对角线连接，见 `util/dfind2.c` / `util/dfind.c` 注释）。

因此将 `dpeaks(checkpeaks)` 优化为：

- 预先计算每个 peak 的阈值 `level = peak_value - saddle*sigma`（并按旧逻辑 clamp 到 `[sigma, 0.99*peak]`）
- 将像素按 `smooth[pix]` 从大到小排序
- 按阈值 `level` 从大到小依次“激活”所有 `smooth > level` 的像素，并用 **Union-Find** 以 **8 邻域**做连通合并
- 对每个 peak，仅需查询其像素所在连通分量中是否包含“更亮的 peak”（用分量内 `bestpeak` 最小索引判断）

该优化将主要耗时从 ~0.7s 降到 ~0.035s（用户实测）。

### A/B 对比开关（运行时 API）

为便于回归验证，新增运行时 API：

- `include/astrometry/dimage.h`
  - `void dpeaks_set_use_dfind2(anbool use_dfind2);`

行为：

- 默认：`use_dfind2 = FALSE`，使用 **Union-Find 快速路径**
- 当设置 `TRUE`：强制回退到旧的 **per-peak dfind2** 路径

> 注：当前为 API 级开关（可用于测试/基准），未新增命令行参数。

### 日志收敛（减少刷屏）

问题解决后，对 `util/dallpeaks.inc` 做了降噪：

- 删除定位期新增的高频 `logverb()`（每次 centroid 失败都打印的 breakdown/subpeak timing 等）
- 将以下高频失败信息降级为 `debug()`（默认 `-v` 不再输出）：
  - `Failed to find (5x5) centroid ...`
  - `Failed to find (3x3) centroid ... too close to edge ...`
- 保留低噪声回归信息：
  - object 级别 `dsmooth2/dpeaks` 超阈值日志（0.05s）
  - `dallpeaks: timing summary` 汇总（含 `centroid5_fail` 与 `centroid3_fail_edge` 计数）

### 如何复现/验证

- 建议运行参数：
  - `solve-field --timestamp -v ...`
- 关注关键日志：
  - `dpeaks: timing ... check(uf ...) ...`（新路径）
  - `dallpeaks: object <id> dpeaks(WxH) ... took ...`（阈值触发）
  - `dallpeaks: timing summary ...`（总览）

验证建议：

- 对同一输入，比较优化前后：
  - `nc`（peaks 数）
  - 输出星点数量/坐标（允许浮点微小差异，但整体应一致）
  - 运行时间（`dpeaks` 应显著下降）

### 涉及文件

- `util/dallpeaks.c`：加入 `tic.h`（`timenow()`）
- `util/dallpeaks.inc`：分段计时 + 低噪声日志 + 汇总（并后续降噪）
- `util/dpeaks.c`：`dpeaks` 内部计时；`checkpeaks` Union-Find 优化；新增 A/B API 实现
- `include/astrometry/dimage.h`：声明 `dpeaks_set_use_dfind2()`


