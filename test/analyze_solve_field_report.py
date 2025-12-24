#!/usr/bin/env python3
"""
Analyze batch solve-field report.csv and print histogram stats.

Designed to work with:
  test/batch_star0_solve.py  -> report.csv
  test/batch_star0_solve.sh  -> report.csv (compatible columns)

默认只依赖标准库；如需生成图片（--plot）则需要额外安装 matplotlib。

## 使用说明

该脚本用于分析批处理输出的 `report.csv`（每行对应一个输入文件），并对指定耗时字段做：
- 汇总统计（min / P50 / P90 / P99 / mean / max）
- 直方图分布（按 `--bin-sec` 指定的“每个桶的秒数”）
- 可选：生成柱状图 PNG（以及可选叠加累计百分比 CDF 折线）

## 字段(metric) 说明（典型用途）

- `wall_s`：每个文件一次 `solve-field` 的**整体墙钟耗时（秒）**（默认，最贴近“整个 solve-field 花了多久”）
- `ts_max_s`：从 `--timestamp` 日志解析到的最大相对秒数（更接近内部流水线耗时，可能略小于 wall）
- `extract_s`：从 “Extracting sources” 到 “simplexy: found” 的耗时（提取源阶段）
- `solve_s`：从 “Solving...” 到 “Field 1: solved” 的耗时（求解阶段；失败样本通常为空）
- `wall_ms`：整体墙钟耗时（毫秒）；此时 `--bin-sec` 仍按“秒”输入，脚本会自动换算成毫秒桶宽

## 典型范例

1) **统计整体耗时直方图（按 1 秒分桶）**

    python3 test/analyze_solve_field_report.py /path/to/report.csv --metric wall_s --bin-sec 1

2) **只统计成功样本的求解阶段耗时（按 0.5 秒分桶）**

    python3 test/analyze_solve_field_report.py /path/to/report.csv --metric solve_s --status solved --bin-sec 0.5

3) **生成直方图图片（并叠加累计百分比 CDF）**

    # 先安装依赖
    python3 -m pip install matplotlib

    # 生成图片（默认输出到 report.csv 同目录）
    python3 test/analyze_solve_field_report.py /path/to/report.csv --metric wall_s --bin-sec 1 --plot --plot-cdf

4) **指定图片输出路径与标题**

    python3 test/analyze_solve_field_report.py /path/to/report.csv --metric ts_max_s --bin-sec 1 \\
      --plot --plot-out /tmp/hist.png --title "solve-field timing histogram"

"""

from __future__ import annotations

import argparse
import csv
import math
import statistics
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Tuple


@dataclass(frozen=True)
class Row:
    file: str
    stem: str
    status: str
    exit_code: Optional[int]
    wall_ms: Optional[float]
    ts_max_s: Optional[float]
    t_read_s: Optional[float]
    t_extract_s: Optional[float]
    t_simplexy_s: Optional[float]
    t_solving_s: Optional[float]
    t_solved_s: Optional[float]
    extract_s: Optional[float]
    solve_s: Optional[float]


def _to_float(v: Optional[str]) -> Optional[float]:
    if v is None:
        return None
    s = v.strip()
    if s == "" or s.lower() == "none":
        return None
    try:
        return float(s)
    except ValueError:
        return None


def _to_int(v: Optional[str]) -> Optional[int]:
    f = _to_float(v)
    if f is None:
        return None
    return int(f)


def read_rows(csv_path: Path) -> List[Row]:
    with csv_path.open("r", encoding="utf-8", errors="replace", newline="") as f:
        r = csv.DictReader(f)
        rows: List[Row] = []
        for d in r:
            rows.append(
                Row(
                    file=d.get("file", ""),
                    stem=d.get("stem", ""),
                    status=(d.get("status") or "").strip(),
                    exit_code=_to_int(d.get("exit_code")),
                    wall_ms=_to_float(d.get("wall_ms")),
                    ts_max_s=_to_float(d.get("ts_max_s")),
                    t_read_s=_to_float(d.get("t_read_s")),
                    t_extract_s=_to_float(d.get("t_extract_s")),
                    t_simplexy_s=_to_float(d.get("t_simplexy_s")),
                    t_solving_s=_to_float(d.get("t_solving_s")),
                    t_solved_s=_to_float(d.get("t_solved_s")),
                    extract_s=_to_float(d.get("extract_s")),
                    solve_s=_to_float(d.get("solve_s")),
                )
            )
    return rows


def percentile(xs: Sequence[float], p: float) -> float:
    """
    Linear interpolation percentile.
    p in [0, 100].
    """
    if not xs:
        raise ValueError("empty data")
    if p <= 0:
        return min(xs)
    if p >= 100:
        return max(xs)
    s = sorted(xs)
    k = (len(s) - 1) * (p / 100.0)
    f = math.floor(k)
    c = math.ceil(k)
    if f == c:
        return s[int(k)]
    d0 = s[f] * (c - k)
    d1 = s[c] * (k - f)
    return d0 + d1


def get_metric_seconds(row: Row, metric: str) -> Optional[float]:
    if metric == "wall_s":
        return (row.wall_ms / 1000.0) if row.wall_ms is not None else None
    if metric == "wall_ms":
        return row.wall_ms
    if metric == "ts_max_s":
        return row.ts_max_s
    if metric == "extract_s":
        return row.extract_s
    if metric == "solve_s":
        return row.solve_s
    raise ValueError(f"unknown metric: {metric}")


def iter_values(rows: Iterable[Row], metric: str, status_filter: str) -> List[float]:
    out: List[float] = []
    for row in rows:
        if status_filter != "all" and row.status != status_filter:
            continue
        v = get_metric_seconds(row, metric)
        if v is None:
            continue
        if math.isfinite(v):
            out.append(v)
    return out


def histogram(values: Sequence[float], bin_sec: float) -> Tuple[List[Tuple[float, float, int]], int]:
    """
    Returns list of bins: (start, end, count), and total count.
    Bin definition: [k*bin_sec, (k+1)*bin_sec)
    """
    if bin_sec <= 0:
        raise ValueError("bin_sec must be > 0")
    if not values:
        return [], 0
    vmax = max(values)
    nbins = max(1, int(math.ceil(vmax / bin_sec)))
    counts = [0] * nbins
    for v in values:
        idx = int(v // bin_sec)
        if idx >= nbins:
            idx = nbins - 1
        counts[idx] += 1
    bins: List[Tuple[float, float, int]] = []
    for i, c in enumerate(counts):
        start = i * bin_sec
        end = (i + 1) * bin_sec
        bins.append((start, end, c))
    return bins, len(values)


def print_summary(values: Sequence[float], unit: str) -> None:
    if not values:
        print("无可用数据（该字段可能为空，或被过滤掉了）。")
        return
    mean = statistics.fmean(values)
    mn = min(values)
    mx = max(values)
    p50 = percentile(values, 50)
    p90 = percentile(values, 90)
    p99 = percentile(values, 99)
    print(f"- **样本数**: {len(values)}")
    print(f"- **最小值**: {mn:.3f} {unit}")
    print(f"- **P50**: {p50:.3f} {unit}")
    print(f"- **P90**: {p90:.3f} {unit}")
    print(f"- **P99**: {p99:.3f} {unit}")
    print(f"- **最大值**: {mx:.3f} {unit}")
    print(f"- **均值**: {mean:.3f} {unit}")


def print_hist_table(bins: Sequence[Tuple[float, float, int]], total: int, unit: str) -> None:
    if total <= 0 or not bins:
        print("直方图为空。")
        return
    print("")
    print("bin_start,bin_end,count,percent,cum_percent")
    cum = 0
    for start, end, c in bins:
        cum += c
        pct = (c / total) * 100.0
        cpct = (cum / total) * 100.0
        print(f"{start:.3f}{unit},{end:.3f}{unit},{c},{pct:.2f},{cpct:.2f}")


def save_hist_plot(
    bins: Sequence[Tuple[float, float, int]],
    total: int,
    unit: str,
    metric: str,
    status: str,
    bin_size: float,
    out_path: Path,
    with_cdf: bool,
    title: str,
) -> None:
    if total <= 0 or not bins:
        raise ValueError("empty histogram")

    try:
        import matplotlib.pyplot as plt  # type: ignore
    except Exception as e:  # pragma: no cover
        raise RuntimeError(
            "当前环境未安装 matplotlib，无法生成图。\n"
            "你可以先安装：python3 -m pip install matplotlib\n"
            f"原始错误: {e}"
        )

    starts = [b[0] for b in bins]
    counts = [b[2] for b in bins]
    xs = [s + bin_size / 2.0 for s in starts]  # bar centers

    fig, ax = plt.subplots(figsize=(10, 5.2), dpi=140)
    ax.bar(xs, counts, width=bin_size * 0.95, align="center", color="#4C78A8", edgecolor="#2F4B7C")
    ax.set_xlabel(f"{metric} ({unit})")
    ax.set_ylabel("count")
    ax.grid(True, axis="y", linestyle="--", alpha=0.35)

    if title:
        ax.set_title(title)
    else:
        ax.set_title(f"Histogram: {metric}, status={status}, bin={bin_size:g}{unit}")

    # nicer x-ticks for second-scale bins
    if unit == "s" and bin_size >= 1:
        ax.set_xlim(0, max(starts) + bin_size)

    if with_cdf:
        ax2 = ax.twinx()
        cum = 0
        cdf = []
        for c in counts:
            cum += c
            cdf.append((cum / total) * 100.0)
        ax2.plot(xs, cdf, color="#F58518", linewidth=2.0, marker="o", markersize=3.2)
        ax2.set_ylabel("cum_percent (%)")
        ax2.set_ylim(0, 100)

    out_path.parent.mkdir(parents=True, exist_ok=True)
    fig.tight_layout()
    fig.savefig(out_path)
    plt.close(fig)


def main(argv: List[str]) -> int:
    ap = argparse.ArgumentParser(
        description="Analyze report.csv histogram",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=(
            "典型范例：\n"
            "  # 整体耗时（按 1 秒桶宽）\n"
            "  python3 test/analyze_solve_field_report.py /path/to/report.csv --metric wall_s --bin-sec 1\n"
            "\n"
            "  # 只看成功样本的 solve 阶段\n"
            "  python3 test/analyze_solve_field_report.py /path/to/report.csv --metric solve_s --status solved --bin-sec 0.5\n"
            "\n"
            "  # 生成图片（需要 matplotlib）\n"
            "  python3 -m pip install matplotlib\n"
            "  python3 test/analyze_solve_field_report.py /path/to/report.csv --metric wall_s --bin-sec 1 --plot --plot-cdf\n"
        ),
    )
    ap.add_argument("report_csv", help="batch_star0_solve 生成的 report.csv 路径")
    ap.add_argument("--metric", default="wall_s", choices=["wall_s", "wall_ms", "ts_max_s", "extract_s", "solve_s"])
    ap.add_argument("--status", default="all", choices=["all", "solved", "failed"], help="只统计成功/失败/全部")
    ap.add_argument("--bin-sec", type=float, default=1.0, help="直方图分块大小（秒）。例如 1 表示按 1 秒区间统计")
    ap.add_argument("--plot", action="store_true", help="生成直方图可视化图片（需要 matplotlib）")
    ap.add_argument("--plot-out", default="", help="图片输出路径（默认与 report.csv 同目录）")
    ap.add_argument("--plot-cdf", action="store_true", help="在图上叠加累计百分比折线（CDF）")
    ap.add_argument("--title", default="", help="自定义图标题")
    args = ap.parse_args(argv)

    csv_path = Path(args.report_csv).expanduser().resolve()
    if not csv_path.is_file():
        print(f"ERROR: report.csv 不存在: {csv_path}", file=sys.stderr)
        return 2

    rows = read_rows(csv_path)

    metric = args.metric
    unit = "s" if metric != "wall_ms" else "ms"
    bin_size = args.bin_sec if unit == "s" else args.bin_sec * 1000.0

    values = iter_values(rows, metric=metric, status_filter=args.status)

    print("### report.csv 直方图统计")
    print("")
    print(f"- **输入**: `{csv_path}`")
    print(f"- **字段(metric)**: `{metric}`")
    print(f"- **状态过滤(status)**: `{args.status}`")
    if unit == "s":
        print(f"- **分块(bin)**: {args.bin_sec:g} 秒")
    else:
        print(f"- **分块(bin)**: {args.bin_sec:g} 秒（即 {bin_size:g} ms）")
    print("")
    print("#### 汇总统计")
    print("")
    print_summary(values, unit=unit)

    bins, total = histogram(values, bin_sec=bin_size)
    print("")
    print("#### 直方图（表格）")
    print_hist_table(bins, total=total, unit=unit)

    if args.plot:
        # choose default output path
        if args.plot_out:
            out_path = Path(args.plot_out).expanduser().resolve()
        else:
            # keep it simple & spreadsheet-friendly
            safe_metric = metric.replace("/", "_")
            out_path = csv_path.parent / f"hist_{safe_metric}_{args.status}_bin{args.bin_sec:g}s.png"
        try:
            save_hist_plot(
                bins=bins,
                total=total,
                unit=unit,
                metric=metric,
                status=args.status,
                bin_size=bin_size,
                out_path=out_path,
                with_cdf=args.plot_cdf,
                title=args.title,
            )
        except Exception as e:
            print("")
            print("#### 可视化生成失败")
            print("")
            print(str(e), file=sys.stderr)
            return 3
        print("")
        print("#### 可视化输出")
        print("")
        print(f"- **图片**: `{out_path}`")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))


