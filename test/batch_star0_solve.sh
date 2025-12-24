#!/usr/bin/env bash

# If invoked with "sh script.sh", the shebang is ignored and we may run under dash,
# which doesn't support "set -o pipefail" and other bash features. Re-exec in bash.
if [ -z "${BASH_VERSION:-}" ]; then
  exec /usr/bin/env bash "$0" "$@"
fi

set -euo pipefail

# Batch solve-field runner for ~/Downloads/star0/*
# - Runs solve-field for each input image
# - Captures per-file logs
# - Produces timing report (CSV + Markdown) including success/failure
#
# Default settings mirror test/test1.sh.

export PATH="/usr/local/astrometry/bin/:$PATH"

STAR_DIR="${1:-/home/q/Downloads/star0}"
INDEX_DIR="${INDEX_DIR:-/usr/share/astrometry}"
CPU_LIMIT="${CPU_LIMIT:-5}"
SCALE_LOW="${SCALE_LOW:-2.5}"
SCALE_HIGH="${SCALE_HIGH:-3}"
SCALE_UNITS="${SCALE_UNITS:-degwidth}"
NSIGMA="${NSIGMA:-8}"
OBJS="${OBJS:-40}"
UNIFORMIZE="${UNIFORMIZE:-0}"
TEMP_ROOT="${TEMP_ROOT:-/dev/shm}"
MAX_FILES="${MAX_FILES:-0}"   # 0 means no limit; otherwise stop after N input files.
ALL_FILES="${ALL_FILES:-0}"   # 1 means attempt to run solve-field on every regular file in STAR_DIR.

if ! command -v solve-field >/dev/null 2>&1; then
  echo "ERROR: solve-field not found in PATH. Current PATH=$PATH" >&2
  exit 127
fi

if [[ ! -d "$STAR_DIR" ]]; then
  echo "ERROR: STAR_DIR does not exist: $STAR_DIR" >&2
  exit 2
fi

ts_now="$(date +%Y%m%d_%H%M%S)"
OUT_ROOT="${OUT_ROOT:-$STAR_DIR/_batch_solve_$ts_now}"
mkdir -p "$OUT_ROOT"

REPORT_CSV="$OUT_ROOT/report.csv"
REPORT_MD="$OUT_ROOT/report.md"
FAIL_LIST_TXT="$OUT_ROOT/failed.txt"

cat >"$REPORT_CSV" <<'CSV'
file,stem,status,exit_code,wall_ms,ts_max_s,t_read_s,t_extract_s,t_simplexy_s,t_solving_s,t_solved_s,extract_s,solve_s
CSV
: >"$FAIL_LIST_TXT"

stem_from_filename() {
  local b="$1"
  # Drop common compression suffixes first
  b="${b%.gz}"
  b="${b%.bz2}"
  b="${b%.xz}"
  b="${b%.fz}"
  # Then drop FITS-ish extensions
  b="${b%.fits}"
  b="${b%.fit}"
  b="${b%.fts}"
  echo "$b"
}

parse_timestamps_to_csv_fields() {
  # Prints:
  # ts_max,t_read,t_extract,t_simplexy,t_solving,t_solved,extract_s,solve_s
  # Empty fields if not found.
  local log_file="$1"
  awk '
    BEGIN { esc = sprintf("%c", 27) }
    function strip_ansi(s) {
      # Remove common ANSI color sequences: ESC[...m or ESC[...K
      gsub(esc "\\[[0-9;]*[mK]", "", s)
      return s
    }
    function getts(s, seg) {
      # POSIX awk: avoid match(..., ..., array) which is not supported by some awks (eg, mawk/busybox).
      if (match(s, /\[[0-9]+: *[0-9.]+\]/)) {
        seg = substr(s, RSTART, RLENGTH)
        sub(/^\[[0-9]+: */, "", seg)
        sub(/\]$/, "", seg)
        return seg
      }
      return ""
    }
    {
      $0 = strip_ansi($0)
      ts = getts($0)
      if (ts != "") {
        if (tmax == "" || ts+0 > tmax+0) tmax = ts
      }
      if (t_read == "" && $0 ~ /Reading input file/) t_read = ts
      if (t_extract == "" && $0 ~ /Extracting sources/) t_extract = ts
      if (t_simplexy == "" && $0 ~ /simplexy: found/) t_simplexy = ts
      if (t_solving == "" && $0 ~ /Solving\.\.\./) t_solving = ts
      if (t_solved == "" && $0 ~ /Field 1: solved/) t_solved = ts
    }
    END {
      extract_s = ""
      solve_s = ""
      if (t_extract != "" && t_simplexy != "") extract_s = (t_simplexy+0) - (t_extract+0)
      if (t_solving != "" && t_solved != "") solve_s = (t_solved+0) - (t_solving+0)
      printf "%s,%s,%s,%s,%s,%s,%s,%s\n", tmax, t_read, t_extract, t_simplexy, t_solving, t_solved, extract_s, solve_s
    }
  ' "$log_file"
}

is_input_file() {
  # Filter to likely image inputs; avoids re-solving generated outputs like .axy/.wcs/.new.
  # You can relax this filter if you really want "all files".
  local f="$1"
  if [[ "$ALL_FILES" == "1" ]]; then
    return 0
  fi
  case "${f,,}" in
    *.fits|*.fit|*.fts|*.fits.gz|*.fit.gz|*.fts.gz|*.fits.fz|*.fit.fz|*.fts.fz) return 0 ;;
    *) return 1 ;;
  esac
}

echo "STAR_DIR=$STAR_DIR"
echo "OUT_ROOT=$OUT_ROOT"
echo "INDEX_DIR=$INDEX_DIR"
echo "CPU_LIMIT=$CPU_LIMIT"

mapfile -d '' files < <(find "$STAR_DIR" -maxdepth 1 -type f -print0 | sort -z)

total=0
solved=0
failed=0

for f in "${files[@]}"; do
  if ! is_input_file "$f"; then
    continue
  fi
  if [[ "$MAX_FILES" != "0" && "$total" -ge "$MAX_FILES" ]]; then
    break
  fi
  total=$((total + 1))

  base="$(basename "$f")"
  stem="$(stem_from_filename "$base")"
  outdir="$OUT_ROOT/$stem"
  mkdir -p "$outdir"

  log="$outdir/solve-field.log"
  tempdir="$TEMP_ROOT/astrometry-batch-$ts_now-$stem-$$"
  mkdir -p "$tempdir"

  echo "[$total] Solving: $base"
  start_ns="$(date +%s%N)"
  set +e
  solve-field "$f" \
    --dir "$outdir" \
    --out "$stem" \
    --index-dir "$INDEX_DIR" \
    --overwrite \
    --cpulimit "$CPU_LIMIT" \
    --scale-units "$SCALE_UNITS" \
    --scale-low "$SCALE_LOW" \
    --scale-high "$SCALE_HIGH" \
    --nsigma "$NSIGMA" \
    --objs "$OBJS" \
    --no-plots \
    --no-remove-lines \
    --uniformize "$UNIFORMIZE" \
    --temp-dir "$tempdir" \
    --timestamp \
    >"$log" 2>&1
  exit_code="$?"
  set -e
  end_ns="$(date +%s%N)"
  wall_ms="$(( (end_ns - start_ns) / 1000000 ))"

  # Cleanup temp files unless user wants to keep them for debugging.
  if [[ "${KEEP_TEMP:-0}" != "1" ]]; then
    rm -rf "$tempdir" || true
  else
    echo "KEEP_TEMP=1 -> preserved tempdir: $tempdir"
  fi

  solved_marker="$outdir/$stem.solved"
  status="failed"
  if [[ "$exit_code" == "0" && -f "$solved_marker" ]]; then
    status="solved"
    solved=$((solved + 1))
  else
    failed=$((failed + 1))
    echo "$f" >>"$FAIL_LIST_TXT"
  fi

  # Per-file summary for realtime monitoring
  wall_s="$(awk -v ms="$wall_ms" 'BEGIN{printf "%.3f", ms/1000.0}')"
  echo "[$total] Result: $base status=$status exit_code=$exit_code wall_ms=$wall_ms wall_s=${wall_s}s"

  timing_csv="$(parse_timestamps_to_csv_fields "$log" 2>/dev/null || true)"
  if [[ -z "$timing_csv" ]]; then
    timing_csv=",,,,,,,"
  fi
  IFS=',' read -r ts_max t_read t_extract t_simplexy t_solving t_solved extract_s solve_s <<<"$timing_csv"

  # CSV row
  printf '%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n' \
    "$f" "$stem" "$status" "$exit_code" "$wall_ms" \
    "$ts_max" "$t_read" "$t_extract" "$t_simplexy" "$t_solving" "$t_solved" \
    "$extract_s" "$solve_s" \
    >>"$REPORT_CSV"
done

{
  echo "### solve-field 批处理耗时报告"
  echo
  echo "- **STAR_DIR**: \`$STAR_DIR\`"
  echo "- **OUT_ROOT**: \`$OUT_ROOT\`"
  echo "- **INDEX_DIR**: \`$INDEX_DIR\`"
  echo "- **总文件数**: $total"
  echo "- **成功**: $solved"
  echo "- **失败**: $failed"
  echo
  echo "#### 产物"
  echo
  echo "- **汇总 CSV**: \`$REPORT_CSV\`"
  echo "- **汇总 Markdown**: \`$REPORT_MD\`"
  echo "- **失败列表**: \`$FAIL_LIST_TXT\`"
  echo
  echo "#### 说明"
  echo
  echo "- **wall_ms**: 每个文件 solve-field 的实际墙钟耗时（毫秒）"
  echo "- **ts_max_s**: solve-field \`--timestamp\` 打印的最大相对秒数（近似该次内部流水线耗时）"
  echo "- **extract_s**: 从 \"Extracting sources\" 到 \"simplexy: found\" 的耗时（若能解析到）"
  echo "- **solve_s**: 从 \"Solving...\" 到 \"Field 1: solved\" 的耗时（若能解析到）"
  echo
  echo "#### 失败文件"
  echo
  if [[ -s "$FAIL_LIST_TXT" ]]; then
    sed 's/^/- /' "$FAIL_LIST_TXT"
  else
    echo "- (无)"
  fi
} >"$REPORT_MD"

echo
echo "Done."
echo "Report: $REPORT_MD"
echo "CSV:    $REPORT_CSV"

