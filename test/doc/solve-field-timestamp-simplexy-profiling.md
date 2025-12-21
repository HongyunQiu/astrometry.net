# solve-field `--timestamp` 相关耗时评估与 simplexy 优化记录

## 背景与目标

在使用 `solve-field --timestamp -v` 运行时，希望更准确评估 `image2xy/simplexy` 的计算耗时，并定位瓶颈；随后对瓶颈进行优化，同时保留与旧算法的**可对比性**（A/B）。

## `--timestamp` 的实现机制（结论）

`solve-field` 的 `--timestamp` 不是单独的“计时代码”，而是开启统一日志系统的时间戳前缀：

- `solver/solve-field.c` 解析 `--timestamp`，随后调用 `log_set_timestamp(TRUE)`。
- `util/log.c` 在 `logger->timestamp` 为真时，为每条 log 输出添加前缀：
  - 形式：`[pid: seconds_since_start] ...`
  - `seconds_since_start` 来自 `timenow() - logger->t0`

因此，只要在关键路径插入 `logverb()/logmsg()`，就能自动获得带时间戳的日志。

## 为 simplexy 增加关键阶段耗时日志

### 变更点

在 `util/simplexy.c` 中，对以下阶段增加 `timenow()` 计时并通过 `logverb()` 输出：

- 背景扣除（median smoothing / background subtract）
- PSF 平滑（dsmooth2 / dsmooth2_i16）
- sigma 测量（dsigma / dsigma_u8）
- dmask、connected-components（dfind2_u8）
- 可选：写出调试 FITS（bg/bgsub/smooth/mask）时的写文件耗时
- `simplexy` 总耗时

> 说明：这些日志默认受 `-v` 控制；配合 `--timestamp` 能直接得到“绝对时间线”和“阶段耗时”两种视角。

### `dmedsmooth` 拆分计时

为更精确定位瓶颈，在 `util/dmedsmooth.c` 的 `dmedsmooth()` 内部增加拆分日志：

- `grid`：计算网格点的窗口中值（主要耗时）
- `interp`：将网格结果插值回整图（通常较小）

示例输出（用户实测）：

```
dmedsmooth: halfbox=100, nxgrid=8, nygrid=6; grid=0.131 s, interp=0.006 s, total=0.137 s
```

结论：瓶颈明确在 **grid**（中值选择/排序）阶段。

## 性能瓶颈与优化：`dselip()` 从 qsort 改为 quickselect（保持精确结果）

### 问题定位

`dmedsmooth_grid()` 在每个网格点都会构造窗口数组 `arr[]` 并调用 `dselip()` 取中值（第 k 个 order statistic）。

旧实现（`util/dselip.c`）在 `dselip()` 内部对整段数组进行 `qsort()` 后取第 k 个：

- 复杂度：每次 \(O(n \log n)\)
- 当 `halfbox` 较大（如 100）时，窗口大小 \((2*halfbox+1)^2 \approx 40401\)，即使网格点不多，排序代价仍然很高。

### 优化方案

将 `dselip()` 的实现改为 **quickselect（选择第 k 小元素）**：

- 平均复杂度：\(O(n)\)
- 仍然返回**精确的第 k 小值**（与排序取第 k 一致）

用户实测效果：**约 0.12s 降至 0.02s**（针对 median smoothing 相关瓶颈）。

## 为同等比较新增开关：`--dselip-qsort`

为便于和旧算法做**同等对比**（A/B），新增 `solve-field` 开关：

- **默认**：使用 quickselect（新实现）
- **`--dselip-qsort`**：强制使用旧版 qsort 全排序路径（legacy）

### 实现方式

新增一个运行时开关 API：

- `include/astrometry/dimage.h`：声明
  - `void dselip_set_use_qsort(anbool use_qsort);`
- `util/dselip.c`：实现全局开关 `g_dselip_use_qsort`
- `solver/solve-field.c`：解析 `--dselip-qsort`，在 `log_init()` 后调用 `dselip_set_use_qsort(...)`
- `man/solve-field.1`：补充文档条目

## 如何复现实验 / 对比

### 开启时间戳与详细日志

建议加：`--timestamp -v`（或更高 `-vv`）。

### A/B 对比命令

- 新实现（默认 quickselect）：
  - `solve-field ... --timestamp -v`
- 旧实现（强制 qsort）：
  - `solve-field ... --timestamp -v --dselip-qsort`

关注日志：

- `dmedsmooth: ... grid=... interp=... total=...`
- `simplexy: median smoothing ...`
- `simplexy: background subtraction total took ...`
- `simplexy: total time ...`

## 涉及文件清单

- `solver/solve-field.c`
  - 新增：`--dselip-qsort` 参数，调用 `dselip_set_use_qsort()`
- `man/solve-field.1`
  - 文档新增：`--dselip-qsort`
- `util/simplexy.c`
  - 新增：关键阶段耗时日志（`timenow()` + `logverb()`）
- `util/dmedsmooth.c`
  - 新增：`grid/interp/total` 拆分计时日志
- `util/dselip.c`
  - 优化：quickselect 实现
  - 新增：运行时切换（legacy qsort vs quickselect）
- `include/astrometry/dimage.h`
  - 新增：`dselip_set_use_qsort()` 声明


