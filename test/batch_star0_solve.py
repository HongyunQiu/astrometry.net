#!/usr/bin/env python3
"""
Batch solve-field runner for ~/Downloads/star0/*

- Runs solve-field per input file (defaults mirror test/test1.sh)
- Captures per-file logs
- Produces timing report (CSV + Markdown) including success/failure

No external dependencies (stdlib only).
"""

from __future__ import annotations

import argparse
import csv
import datetime as dt
import os
import re
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, Optional, Tuple


ANSI_RE = re.compile(r"\x1b\[[0-9;]*[mK]")
TS_RE = re.compile(r"\[(\d+):\s*([0-9.]+)\]")

# ANSI colors (only enable when stdout is a TTY and NO_COLOR is not set)
ANSI_RESET = "\x1b[0m"
ANSI_RED = "\x1b[31m"
ANSI_GREEN = "\x1b[32m"
ANSI_YELLOW = "\x1b[33m"


@dataclass
class Timing:
    ts_max_s: Optional[float] = None
    t_read_s: Optional[float] = None
    t_extract_s: Optional[float] = None
    t_simplexy_s: Optional[float] = None
    t_solving_s: Optional[float] = None
    t_solved_s: Optional[float] = None
    extract_s: Optional[float] = None
    solve_s: Optional[float] = None


def strip_ansi(s: str) -> str:
    return ANSI_RE.sub("", s)


def safe_float(x: Optional[str]) -> Optional[float]:
    if x is None or x == "":
        return None
    try:
        return float(x)
    except ValueError:
        return None


def parse_timing_from_log(log_path: Path) -> Timing:
    """
    Parses solve-field --timestamp output to extract stage timestamps.
    Works even when logs contain ANSI color codes.
    """
    timing = Timing()
    tmax: Optional[float] = None

    def get_ts(line: str) -> Optional[float]:
        m = TS_RE.search(line)
        if not m:
            return None
        return safe_float(m.group(2))

    try:
        with log_path.open("r", errors="replace") as f:
            for raw in f:
                line = strip_ansi(raw.rstrip("\n"))
                ts = get_ts(line)
                if ts is not None:
                    if tmax is None or ts > tmax:
                        tmax = ts

                if timing.t_read_s is None and "Reading input file" in line:
                    timing.t_read_s = ts
                if timing.t_extract_s is None and "Extracting sources" in line:
                    timing.t_extract_s = ts
                if timing.t_simplexy_s is None and "simplexy: found" in line:
                    timing.t_simplexy_s = ts
                if timing.t_solving_s is None and "Solving..." in line:
                    timing.t_solving_s = ts
                if timing.t_solved_s is None and "Field 1: solved" in line:
                    timing.t_solved_s = ts
    except FileNotFoundError:
        pass

    timing.ts_max_s = tmax
    if timing.t_extract_s is not None and timing.t_simplexy_s is not None:
        timing.extract_s = timing.t_simplexy_s - timing.t_extract_s
    if timing.t_solving_s is not None and timing.t_solved_s is not None:
        timing.solve_s = timing.t_solved_s - timing.t_solving_s
    return timing


def stem_from_filename(name: str) -> str:
    # Drop common compression suffixes first
    for suf in (".gz", ".bz2", ".xz", ".fz"):
        if name.lower().endswith(suf):
            name = name[: -len(suf)]
            break
    # Then drop FITS-ish extensions
    for suf in (".fits", ".fit", ".fts"):
        if name.lower().endswith(suf):
            name = name[: -len(suf)]
            break
    return name


def iter_input_files(star_dir: Path, all_files: bool) -> Iterable[Path]:
    files = sorted([p for p in star_dir.iterdir() if p.is_file()])
    if all_files:
        yield from files
        return
    allowed = (".fits", ".fit", ".fts", ".fits.gz", ".fit.gz", ".fts.gz", ".fits.fz", ".fit.fz", ".fts.fz")
    for p in files:
        if p.name.lower().endswith(allowed):
            yield p


def which(cmd: str, env: dict) -> Optional[str]:
    return shutil.which(cmd, path=env.get("PATH"))

def colorize(s: str, color: str, enable: bool) -> str:
    if not enable:
        return s
    return f"{color}{s}{ANSI_RESET}"


def run_solve_field(
    solve_field: str,
    f: Path,
    outdir: Path,
    stem: str,
    index_dir: Path,
    cpu_limit: int,
    scale_units: str,
    scale_low: float,
    scale_high: float,
    nsigma: float,
    objs: int,
    uniformize: int,
    temp_root: Path,
    keep_temp: bool,
    env: dict,
) -> Tuple[int, int, Path]:
    outdir.mkdir(parents=True, exist_ok=True)
    log_path = outdir / "solve-field.log"

    tempdir = Path(
        tempfile.mkdtemp(
            dir=str(temp_root),
            prefix=f"astrometry-batch-{dt.datetime.now().strftime('%Y%m%d_%H%M%S')}-{stem}-",
        )
    )

    args = [
        solve_field,
        str(f),
        "--dir",
        str(outdir),
        "--out",
        stem,
        "--index-dir",
        str(index_dir),
        "--overwrite",
        "--cpulimit",
        str(cpu_limit),
        "--scale-units",
        scale_units,
        "--scale-low",
        str(scale_low),
        "--scale-high",
        str(scale_high),
        "--nsigma",
        str(nsigma),
        "--objs",
        str(objs),
        "--no-plots",
        "--no-remove-lines",
        "--uniformize",
        str(uniformize),
        "--temp-dir",
        str(tempdir),
        "--timestamp",
    ]

    start = dt.datetime.now(dt.timezone.utc)
    try:
        with log_path.open("wb") as logf:
            p = subprocess.run(args, stdout=logf, stderr=subprocess.STDOUT, env=env)
            exit_code = int(p.returncode)
    finally:
        end = dt.datetime.now(dt.timezone.utc)
        wall_ms = int((end - start).total_seconds() * 1000)
        if (not keep_temp) and tempdir.exists():
            shutil.rmtree(tempdir, ignore_errors=True)

    return exit_code, wall_ms, log_path


def write_markdown_report(
    report_md: Path,
    star_dir: Path,
    out_root: Path,
    index_dir: Path,
    total: int,
    solved: int,
    failed: int,
    report_csv: Path,
    failed_txt: Path,
) -> None:
    lines = []
    lines.append("### solve-field 批处理耗时报告")
    lines.append("")
    lines.append(f"- **STAR_DIR**: `{star_dir}`")
    lines.append(f"- **OUT_ROOT**: `{out_root}`")
    lines.append(f"- **INDEX_DIR**: `{index_dir}`")
    lines.append(f"- **总文件数**: {total}")
    lines.append(f"- **成功**: {solved}")
    lines.append(f"- **失败**: {failed}")
    lines.append("")
    lines.append("#### 产物")
    lines.append("")
    lines.append(f"- **汇总 CSV**: `{report_csv}`")
    lines.append(f"- **汇总 Markdown**: `{report_md}`")
    lines.append(f"- **失败列表**: `{failed_txt}`")
    lines.append("")
    lines.append("#### 说明")
    lines.append("")
    lines.append("- **wall_ms**: 每个文件 solve-field 的实际墙钟耗时（毫秒）")
    lines.append("- **ts_max_s**: solve-field `--timestamp` 打印的最大相对秒数（近似该次内部流水线耗时）")
    lines.append("- **extract_s**: 从 \"Extracting sources\" 到 \"simplexy: found\" 的耗时（若能解析到）")
    lines.append("- **solve_s**: 从 \"Solving...\" 到 \"Field 1: solved\" 的耗时（若能解析到）")
    lines.append("")
    lines.append("#### 失败文件")
    lines.append("")
    if failed_txt.exists() and failed_txt.stat().st_size > 0:
        for line in failed_txt.read_text(errors="replace").splitlines():
            if line.strip():
                lines.append(f"- {line.strip()}")
    else:
        lines.append("- (无)")
    lines.append("")
    report_md.write_text("\n".join(lines), encoding="utf-8")


def main(argv: list[str]) -> int:
    ap = argparse.ArgumentParser(description="Batch solve-field runner + timing report")
    ap.add_argument("star_dir", nargs="?", default=str(Path.home() / "Downloads" / "star0"))
    ap.add_argument("--index-dir", default="/usr/share/astrometry")
    ap.add_argument("--cpu-limit", type=int, default=5)
    ap.add_argument("--scale-units", default="degwidth")
    ap.add_argument("--scale-low", type=float, default=2.5)
    ap.add_argument("--scale-high", type=float, default=3.0)
    ap.add_argument("--nsigma", type=float, default=8.0)
    ap.add_argument("--objs", type=int, default=40)
    ap.add_argument("--uniformize", type=int, default=0)
    ap.add_argument("--temp-root", default="/dev/shm")
    ap.add_argument("--keep-temp", action="store_true")
    ap.add_argument("--all-files", action="store_true", help="尝试对目录下所有普通文件运行 solve-field（默认只跑 FITS/FITS 压缩）")
    ap.add_argument("--max-files", type=int, default=0, help="仅跑前 N 个文件（0=不限制）")
    ap.add_argument("--out-root", default="", help="自定义输出根目录（默认在 star_dir 下创建 _batch_solve_时间戳）")
    ap.add_argument("--solve-field", default="solve-field", help="solve-field 可执行文件名或路径")
    args = ap.parse_args(argv)

    star_dir = Path(args.star_dir).expanduser().resolve()
    index_dir = Path(args.index_dir).expanduser().resolve()
    temp_root = Path(args.temp_root).expanduser().resolve()

    if not star_dir.is_dir():
        print(f"ERROR: STAR_DIR 不存在: {star_dir}", file=sys.stderr)
        return 2

    color_enabled = bool(sys.stdout.isatty()) and ("NO_COLOR" not in os.environ)

    # Ensure solve-field in PATH (mirror test1.sh behavior)
    env = os.environ.copy()
    env["PATH"] = f"/usr/local/astrometry/bin/:" + env.get("PATH", "")
    solve_field_path = args.solve_field
    if os.sep not in solve_field_path:
        found = which(solve_field_path, env)
        if not found:
            print(f"ERROR: solve-field 不在 PATH 中。当前 PATH={env['PATH']}", file=sys.stderr)
            return 127
        solve_field_path = found

    ts_now = dt.datetime.now().strftime("%Y%m%d_%H%M%S")
    out_root = Path(args.out_root).expanduser().resolve() if args.out_root else (star_dir / f"_batch_solve_{ts_now}")
    out_root.mkdir(parents=True, exist_ok=True)

    report_csv = out_root / "report.csv"
    report_md = out_root / "report.md"
    failed_txt = out_root / "failed.txt"
    failed_txt.write_text("", encoding="utf-8")

    print(f"STAR_DIR={star_dir}")
    print(f"OUT_ROOT={out_root}")
    print(f"INDEX_DIR={index_dir}")
    print(f"CPU_LIMIT={args.cpu_limit}")

    rows = []
    total = solved = failed = 0
    for f in iter_input_files(star_dir, all_files=args.all_files):
        if args.max_files and total >= args.max_files:
            break
        total += 1

        stem = stem_from_filename(f.name)
        outdir = out_root / stem
        print(f"[{total}] Solving: {f.name}", flush=True)

        exit_code, wall_ms, log_path = run_solve_field(
            solve_field=solve_field_path,
            f=f,
            outdir=outdir,
            stem=stem,
            index_dir=index_dir,
            cpu_limit=args.cpu_limit,
            scale_units=args.scale_units,
            scale_low=args.scale_low,
            scale_high=args.scale_high,
            nsigma=args.nsigma,
            objs=args.objs,
            uniformize=args.uniformize,
            temp_root=temp_root,
            keep_temp=args.keep_temp,
            env=env,
        )

        solved_marker = outdir / f"{stem}.solved"
        status = "failed"
        if exit_code == 0 and solved_marker.exists():
            status = "solved"
            solved += 1
        else:
            failed += 1
            with failed_txt.open("a", encoding="utf-8") as ff:
                ff.write(str(f) + "\n")

        timing = parse_timing_from_log(log_path)

        # Per-file summary for realtime monitoring (match bash runner style)
        wall_s = (wall_ms / 1000.0) if wall_ms is not None else None
        result_line = (
            f"[{total}] Result: {f.name} status={status} exit_code={exit_code} wall_ms={wall_ms}"
            if wall_s is None
            else f"[{total}] Result: {f.name} status={status} exit_code={exit_code} wall_ms={wall_ms} wall_s={wall_s:.3f}s"
        )
        # Color rules:
        # - failed: red
        # - solved and > 1s: yellow
        # - solved and 0.5-1s: green
        # (solved < 0.5s: no color by default)
        if status != "solved":
            result_line = colorize(result_line, ANSI_RED, color_enabled)
        elif wall_s is not None and wall_s > 1.0:
            result_line = colorize(result_line, ANSI_YELLOW, color_enabled)
        elif wall_s is not None and 0.5 <= wall_s <= 1.0:
            result_line = colorize(result_line, ANSI_GREEN, color_enabled)

        print(result_line, flush=True)

        rows.append(
            {
                "file": str(f),
                "stem": stem,
                "status": status,
                "exit_code": exit_code,
                "wall_ms": wall_ms,
                "ts_max_s": timing.ts_max_s,
                "t_read_s": timing.t_read_s,
                "t_extract_s": timing.t_extract_s,
                "t_simplexy_s": timing.t_simplexy_s,
                "t_solving_s": timing.t_solving_s,
                "t_solved_s": timing.t_solved_s,
                "extract_s": timing.extract_s,
                "solve_s": timing.solve_s,
            }
        )

    # Write CSV
    fieldnames = [
        "file",
        "stem",
        "status",
        "exit_code",
        "wall_ms",
        "ts_max_s",
        "t_read_s",
        "t_extract_s",
        "t_simplexy_s",
        "t_solving_s",
        "t_solved_s",
        "extract_s",
        "solve_s",
    ]
    with report_csv.open("w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        for r in rows:
            w.writerow(r)

    write_markdown_report(
        report_md=report_md,
        star_dir=star_dir,
        out_root=out_root,
        index_dir=index_dir,
        total=total,
        solved=solved,
        failed=failed,
        report_csv=report_csv,
        failed_txt=failed_txt,
    )

    print("")
    print("Done.")
    print(f"Report: {report_md}")
    print(f"CSV:    {report_csv}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))


