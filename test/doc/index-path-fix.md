# Astrometry.net：解决 index 星表（索引）路径问题总结

## 现象
运行 `solve-field`（或脚本调用它）时出现类似报错：

- `You must list at least one index in the config file (.../etc/astrometry.cfg)`
- `astrometry-engine ... engine failed`

这表示 **astrometry-engine 没有在配置的目录里找到任何 index 索引文件**。

## 关键点（本次环境）
- `astrometry-engine` 默认读取配置：`/usr/local/astrometry/etc/astrometry.cfg`
- 该配置里有一行（示例）：`add_path /usr/local/astrometry/data`
- 但系统里实际安装的 tycho2 索引在：`/usr/share/astrometry/`
  - 例如：`/usr/share/astrometry/index-tycho2-07.littleendian.fits` 等

因此需要让引擎能“看见” `/usr/share/astrometry/` 下的索引。

## 如何确认索引文件在哪里
常用方式：

```bash
# 直接看目录（如果你系统把索引放这里）
ls /usr/share/astrometry/

# 查找有哪些 index 文件（示例）
python3 - <<'PY'
import glob
print('\n'.join(sorted(glob.glob('/usr/share/astrometry/index-*.fits'))))
PY
```

如果你是通过 Debian/Ubuntu 包安装的，也可以：

```bash
dpkg -L astrometry-data-tycho2
```

注意：有些发行版/包可能只放文档，索引文件会在其他 `astrometry-data-xxx` 包里；以实际 `index-*.fits` 的位置为准。

## 解决方案（任选其一）

### 方案 A：不改系统配置，命令行直接指定索引目录（推荐）
`solve-field` 支持 `--index-dir`，可以绕开 `astrometry.cfg` 的 `add_path`。

```bash
solve-field input.fits --index-dir /usr/share/astrometry ...
```

本次我们就是采用这一方案：在 `test/test1.sh` 里加入 `--index-dir /usr/share/astrometry`。

优点：
- 不需要 root 权限改配置
- 对不同机器/不同索引目录更稳

### 方案 B：修改 `astrometry.cfg` 的 `add_path`
把配置里的：

```text
add_path /usr/local/astrometry/data
```

改成（或新增一行）：

```text
add_path /usr/share/astrometry
```

注意：很多安装方式下该文件属于 root（例如 `root:root`），需要用 root 权限编辑。

### 方案 C：把索引软链接/复制到配置里已有的目录
如果配置固定指向 `/usr/local/astrometry/data`，你可以把索引放进去：

```bash
# 需要 root 权限
sudo ln -sf /usr/share/astrometry/index-*.fits /usr/local/astrometry/data/
```

这样即使不改配置，引擎也能从 `/usr/local/astrometry/data` 自动加载。

## 额外说明：能“找到索引” ≠ 一定能“成功解算”
修好 index 路径后，如果出现 `Did not solve`，更多是以下因素导致，而不是路径问题：
- 输入图像星点质量/数量、噪声、畸变
- `--scale-low/--scale-high` 设定不符合真实视场
- `--cpulimit` 太低（本次脚本里设为 5 秒，可能经常来不及）

这属于求解参数/图像质量问题，不影响本总结的“索引路径修复”。
