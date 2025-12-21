export PATH="/usr/local/astrometry/bin/:$PATH"
env "PATH=$PATH" solve-field ~/Downloads/star2/1.fits --index-dir /usr/share/astrometry --overwrite --cpulimit 5 --scale-units degwidth --scale-low 2.5 --scale-high 3 --nsigma 8 --objs 40 --no-plots  --no-remove-lines --uniformize 0 --temp-dir /dev/shm  --timestamp 

