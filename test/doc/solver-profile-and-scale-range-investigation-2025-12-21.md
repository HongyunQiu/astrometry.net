# solve-field / astrometry-engine 时间戳断档与 solver 卡点排查记录（profile + scale 收敛）

## 背景

现象：运行 `solve-field --timestamp -v` 时，日志在 `Running:` 之后（`astrometry-engine` 阶段）不再出现时间戳；同时 solver 阶段存在明显卡点（`object N ... matched ...` 逐步变慢）。

目标：

- 让 `Running:` 之后的 `astrometry-engine` 输出也能带时间戳，便于完整时间线分析。
- 在日志较多的情况下，用“可过滤”的方式输出性能分析信息。
- 定位 solver 阶段的主要耗时点，并通过参数（scale range）验证提速手段。

## 1) 时间戳为何在 `Running:` 之后断档？

结论：`solve-field --timestamp` 只会让 **当前进程** 的 `logmsg/logverb` 增加时间戳前缀；`solve-field` 通过 `system()` 启动 `astrometry-engine`，子进程输出不会被外层自动加前缀，因此出现“断档”。

关键代码：

- `solve-field` 运行外部命令使用 `system()`（子进程输出直接写到终端）：

```122:143:solver/solve-field.c
static int run_command(const char* cmd, anbool* ctrlc) {
    int rtn;
    logverb("Running: %s\n", cmd);
    fflush(NULL);
    rtn = system(cmd);
    fflush(NULL);
    // ...
}
```

- 时间戳前缀由 `util/log.c` 决定，仅对当前进程的 logger 生效：

```109:118:util/log.c
        if (logger->timestamp) {
            fprintf(logger->f, "[%6i: %.3f] ",
                    (int)getpid(), timenow() - logger->t0);
        }
```

## 2) 修复：让 `astrometry-engine` 也支持时间戳，并由 `solve-field` 透传

实现：

- `astrometry-engine` 新增 `-T/--timestamp`，内部调用 `log_set_timestamp(TRUE)`。
- `solve-field --timestamp` 自动追加 `--timestamp` 到 `astrometry-engine` 参数列表。

效果：

- `Running:` 后的引擎输出也带时间戳，且 PID 会变（父/子进程分别计时，时间轴不能直接对比）。

## 3) 新增可过滤的性能分析开关：`--profile-solver`

诉求：默认日志已经很多，新增性能日志必须“默认关闭、显式开启、且能 grep 过滤”。

实现：

- `astrometry-engine` 新增 `-P/--profile-solver`
- `solve-field` 新增 `--profile-solver` 并透传到引擎
- profiling 日志统一前缀：`[SOLVER_PROFILE]`，可用 `grep` 精准过滤

常用过滤命令：

```bash
# 只看 profiling
... 2>&1 | grep '\[SOLVER_PROFILE\]'

# 屏蔽 profiling，只看原始日志
... 2>&1 | grep -v '\[SOLVER_PROFILE\]'
```

## 4) 关键发现：solver 的主要耗时在 `verify_hit()`（不是 KD-tree 查询）

profiling 采样输出包含每轮（`object N/M`）增量统计：

- `+tries`：本轮新增尝试的 quad 数
- `+matches`：本轮 KD-tree 命中候选累计数（近似“候选数量”）
- `+verified`：本轮进入验证/打分的次数
- `KD(...)`：KD-tree 查询耗时/调用次数/返回结果数
- `verify(...)`：`verify_hit()` 总耗时/调用次数

观察规律：

- 多数情况下 `KD(dt)` 非常小；
- 当 `+matches` 暴涨时，`+verified` 同步暴涨，`verify(dt)` 占据了绝大多数 `dt`。

对应热点路径：

- 候选检索（KD-tree range search）：
  - `solver/solver.c` → `try_permutations()` → `kdtree_rangesearch_options_reuse(...)`
- 候选验证/打分（主要耗时）：
  - `solver/solver.c` → `solver_handle_hit()` → `verify_hit(...)`

## 5) 定位“最慢的 run”：`index-tycho2-11` 候选爆炸

通过 profile header（每个 run 打印 params+index），在 `test/log_solver_profile.txt` 中可定位最慢 run：

- 最慢 run：`run 4`
- 对应 index：
  - `/usr/share/astrometry/index-tycho2-11.littleendian.fits`（`indexid=4111`）

同时 `run 4` 的末段出现：

- `+matches` 达到数千级
- `+verified` 与 `+matches` 近似同量级
- `verify(dt)` 几乎等于 `dt`（证明主要耗时在验证阶段）

## 6) 实验验证：缩小 `--scale-low/--scale-high` → 候选数量下降 → 速度显著提升

实验操作：

- 调小 `solve-field` 的 `--scale-low` / `--scale-high` 范围（更精确的图像尺度先验）

观察结果：

- 总耗时从 **0.x 秒** 降到 **0.0x 秒**（同图同机环境）
- profiling 侧的解释：缩小 scale range 会减少参与的 index/候选空间，直接降低 `+matches` 与 `+verified`，从而减少 `verify_hit()` 的累计耗时。

> 经验结论：在“能稳定 solve”的前提下，scale range 是最有效、最安全的提速杠杆之一。

## 7) 复现实验的参考命令

示例脚本（见 `test/test1.sh`）核心参数：

- `--timestamp`：统一时间戳
- `--profile-solver`：只在排查时开启
- `--scale-low/--scale-high`：调参观察性能变化

示例：

```bash
./solver/solve-field ~/Downloads/star2/3.fits \
  --index-dir /usr/share/astrometry \
  --overwrite --cpulimit 5 \
  --scale-units degwidth --scale-low 1 --scale-high 1.9 \
  --nsigma 8 --objs 40 --no-plots --no-remove-lines --uniformize 0 \
  --temp-dir /dev/shm \
  --timestamp --profile-solver -v 2>&1 | grep '\[SOLVER_PROFILE\]'
```

## 8) 涉及改动摘要

- `solver/engine-main.c`
  - 新增 `--timestamp`
  - 新增 `--profile-solver`
- `solver/solve-field.c`
  - `--timestamp` 透传到 `astrometry-engine`
  - 新增 `--profile-solver` 并透传
- `solver/solver.c`
  - profiling：按 `object N` 输出增量计时/计数
  - profiling：拆分 KD-tree 查询耗时与 `verify_hit()` 累计耗时
  - profiling：run header 打印 params 与 index 文件名
- `include/astrometry/solver.h`
  - 暴露 profiling 开关 API（内部用于引擎控制）


