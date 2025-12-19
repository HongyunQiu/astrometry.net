[ 54164: 0.000] Reading input file 1 of 1: "/home/q/Downloads/star2/1.fits"...
[ 54164: 0.000] Base: "/home/q/Downloads/star2/1", basefile "1.fits", basedir "/home/q/Downloads/star2", suffix "fits"
[ 54164: 0.000] Checking if file "/home/q/Downloads/star2/1.fits" ext 0 is xylist or image: [ 54164: 0.001] image
[ 54164: 0.001]   (not xyls because: FITS file does not have any extensions)
[ 54164: 0.001] Running command: /usr/local/astrometry/bin/image2pnm --infile /home/q/Downloads/star2/1.fits --uncompressed-outfile /dev/shm/tmp.uncompressed.uCDbEJ --outfile /dev/shm/tmp.ppm.f6OKsZ --ppm --mydir /usr/local/astrometry/bin/solve-field
[ 54164: 0.001] Running: /usr/local/astrometry/bin/image2pnm --infile /home/q/Downloads/star2/1.fits --uncompressed-outfile /dev/shm/tmp.uncompressed.uCDbEJ --outfile /dev/shm/tmp.ppm.f6OKsZ --ppm --mydir /usr/local/astrometry/bin/solve-field
[ 54164: 0.096]   Dirs: ['/usr/local/astrometry/bin/solve-field', '/usr/local/astrometry/bin', '/usr/lib/python3/dist-packages/astrometry/util']
[ 54164: 0.096]   fits
[ 54164: 0.096] Running: pnmfile /dev/shm/tmp.ppm.f6OKsZ
[ 54164: 0.100] Looking for a WCS header in FITS input image /home/q/Downloads/star2/1.fits ext 0
[ 54164: 0.100] Failed to read a SIP or TAN header from FITS image.
[ 54164: 0.100]   (reason: Failed to parse WCS header from file "/home/q/Downloads/star2/1.fits" extension 0: SIP header: no key "CTYPE1")
[ 54164: 0.100] Extracting sources...
[ 54164: 0.100] Running image2xy: input=/home/q/Downloads/star2/1.fits, output=/dev/shm/tmp.xyls.8ay5mF, ext=0
[ 54164: 0.101] nhdus=1
[ 54164: 0.101] Got naxis=2, na1=694, na2=464
[ 54164: 0.102] simplexy: nx=694, ny=464
[ 54164: 0.103] simplexy: dpsf=1.000000, plim=8.000000, dlim=1.000000, saddle=5.000000
[ 54164: 0.103] simplexy: maxper=1000, maxnpeaks=100000, maxsize=2000, halfbox=100
[ 54164: 0.103] simplexy: median smoothing...
[ 54164: 0.251] simplexy: measuring image noise (sigma)...
[ 54164: 0.251] Sampling sigma at 805 points
[ 54164: 0.251] Nsigma=0.7, s=31.3147
[ 54164: 0.251] simplexy: found sigma=31.3147.
[ 54164: 0.251] simplexy: finding objects...
[ 54164: 0.258] simplexy: found 269 blobs
[ 54164: 0.258] simplexy: finding peaks...
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 1 at (45,109)
[ 54164: 1.001] Failed to find (3x3) centroid of peak 0, subpeak 2 at (12,462), and too close to edge for 5x5
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 3 at (43,260)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 5 at (38,437)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 6 at (668,178)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 7 at (14,88)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 8 at (661,193)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 12 at (572,449)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 13 at (2,4)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 16 at (7,23)
[ 54164: 1.001] Failed to find (3x3) centroid of peak 0, subpeak 17 at (692,436), and too close to edge for 5x5
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 18 at (634,12)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 19 at (397,13)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 21 at (595,457)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 22 at (132,21)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 23 at (280,453)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 24 at (652,360)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 25 at (192,435)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 26 at (554,445)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 27 at (478,11)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 28 at (28,358)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 29 at (269,458)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 35 at (299,445)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 36 at (74,2)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 37 at (24,183)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 38 at (168,13)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 40 at (34,87)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 42 at (28,294)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 43 at (545,18)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 44 at (232,20)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 45 at (65,206)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 47 at (621,440)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 48 at (587,24)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 49 at (363,438)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 51 at (638,25)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 53 at (47,314)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 54 at (54,105)
[ 54164: 1.001] Failed to find (5x5) centroid of peak 0, subpeak 56 at (163,34)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 1, subpeak 0 at (444,41)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 2, subpeak 0 at (527,33)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 4, subpeak 0 at (619,37)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 5, subpeak 0 at (122,38)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 6, subpeak 0 at (334,39)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 8, subpeak 0 at (588,41)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 8, subpeak 1 at (596,43)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 9, subpeak 0 at (231,42)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 10, subpeak 0 at (87,48)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 11, subpeak 0 at (188,48)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 12, subpeak 0 at (313,50)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 13, subpeak 0 at (162,50)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 15, subpeak 0 at (145,51)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 17, subpeak 0 at (586,54)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 20, subpeak 0 at (617,58)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 20, subpeak 2 at (600,68)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 22, subpeak 0 at (60,57)
[ 54164: 1.002] Failed to find (5x5) centroid of peak 22, subpeak 1 at (72,64)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 24, subpeak 0 at (546,60)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 27, subpeak 0 at (389,72)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 27, subpeak 1 at (397,77)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 29, subpeak 0 at (453,73)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 33, subpeak 0 at (130,79)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 33, subpeak 1 at (120,77)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 35, subpeak 0 at (489,83)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 37, subpeak 0 at (159,86)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 38, subpeak 0 at (196,87)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 40, subpeak 0 at (437,90)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 41, subpeak 0 at (306,91)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 44, subpeak 0 at (75,89)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 46, subpeak 0 at (96,97)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 48, subpeak 0 at (112,100)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 49, subpeak 0 at (145,99)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 50, subpeak 0 at (172,106)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 54, subpeak 0 at (591,111)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 58, subpeak 0 at (153,125)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 58, subpeak 2 at (144,125)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 60, subpeak 0 at (87,119)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 60, subpeak 1 at (96,129)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 63, subpeak 0 at (122,122)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 65, subpeak 2 at (549,140)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 65, subpeak 3 at (545,132)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 66, subpeak 0 at (220,125)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 67, subpeak 0 at (397,127)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 68, subpeak 0 at (54,128)
[ 54164: 1.003] Failed to find (5x5) centroid of peak 70, subpeak 0 at (261,132)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 72, subpeak 0 at (177,140)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 75, subpeak 0 at (62,143)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 77, subpeak 0 at (461,150)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 79, subpeak 0 at (591,152)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 79, subpeak 2 at (601,176)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 80, subpeak 1 at (480,166)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 82, subpeak 0 at (513,153)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 82, subpeak 1 at (505,163)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 83, subpeak 0 at (398,156)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 85, subpeak 0 at (305,161)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 86, subpeak 0 at (646,162)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 87, subpeak 0 at (320,170)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 87, subpeak 1 at (334,162)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 88, subpeak 0 at (566,165)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 89, subpeak 0 at (262,169)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 90, subpeak 0 at (466,169)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 91, subpeak 0 at (442,177)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 92, subpeak 0 at (252,177)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 94, subpeak 1 at (463,179)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 96, subpeak 0 at (199,184)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 100, subpeak 2 at (504,187)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 101, subpeak 0 at (560,189)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 104, subpeak 1 at (404,206)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 105, subpeak 0 at (599,192)
[ 54164: 1.004] Failed to find (5x5) centroid of peak 106, subpeak 0 at (527,194)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 110, subpeak 0 at (157,203)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 112, subpeak 1 at (138,213)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 112, subpeak 2 at (127,207)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 114, subpeak 0 at (223,213)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 116, subpeak 0 at (195,215)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 119, subpeak 0 at (639,221)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 120, subpeak 0 at (503,223)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 123, subpeak 0 at (522,224)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 124, subpeak 2 at (438,224)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 125, subpeak 0 at (486,224)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 127, subpeak 1 at (139,233)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 130, subpeak 0 at (281,229)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 136, subpeak 0 at (610,240)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 138, subpeak 0 at (261,242)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 140, subpeak 0 at (555,241)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 141, subpeak 1 at (188,246)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 143, subpeak 0 at (528,260)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 143, subpeak 1 at (521,251)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 144, subpeak 0 at (258,261)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 145, subpeak 0 at (165,255)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 148, subpeak 0 at (203,257)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 149, subpeak 0 at (541,258)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 150, subpeak 0 at (620,258)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 151, subpeak 0 at (139,272)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 151, subpeak 1 at (144,262)
[ 54164: 1.005] Failed to find (5x5) centroid of peak 152, subpeak 0 at (462,278)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 152, subpeak 3 at (467,270)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 157, subpeak 1 at (282,281)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 160, subpeak 0 at (381,280)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 161, subpeak 0 at (62,280)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 166, subpeak 0 at (312,286)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 167, subpeak 0 at (571,287)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 168, subpeak 0 at (157,288)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 169, subpeak 0 at (630,290)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 171, subpeak 1 at (90,295)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 171, subpeak 2 at (87,309)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 172, subpeak 0 at (439,295)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 173, subpeak 0 at (544,299)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 174, subpeak 0 at (194,296)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 175, subpeak 0 at (134,297)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 176, subpeak 0 at (506,298)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 177, subpeak 0 at (615,301)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 182, subpeak 0 at (482,308)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 183, subpeak 1 at (130,310)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 183, subpeak 2 at (122,310)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 184, subpeak 0 at (336,311)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 186, subpeak 0 at (154,315)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 187, subpeak 0 at (572,316)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 194, subpeak 0 at (593,324)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 195, subpeak 1 at (334,326)
[ 54164: 1.006] Failed to find (5x5) centroid of peak 196, subpeak 0 at (651,326)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 197, subpeak 0 at (145,330)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 200, subpeak 0 at (579,331)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 203, subpeak 0 at (327,337)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 205, subpeak 1 at (184,339)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 208, subpeak 0 at (449,344)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 210, subpeak 0 at (460,345)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 211, subpeak 1 at (386,354)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 212, subpeak 0 at (61,350)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 212, subpeak 1 at (71,350)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 212, subpeak 2 at (51,358)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 212, subpeak 3 at (66,357)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 212, subpeak 4 at (59,366)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 212, subpeak 5 at (49,366)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 213, subpeak 0 at (123,351)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 213, subpeak 1 at (113,360)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 214, subpeak 1 at (149,356)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 215, subpeak 0 at (576,349)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 220, subpeak 0 at (594,361)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 221, subpeak 0 at (98,366)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 222, subpeak 1 at (200,371)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 225, subpeak 2 at (483,402)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 225, subpeak 3 at (484,371)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 226, subpeak 0 at (78,375)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 228, subpeak 0 at (218,378)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 229, subpeak 0 at (587,378)
[ 54164: 1.007] Failed to find (5x5) centroid of peak 229, subpeak 2 at (582,390)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 233, subpeak 0 at (396,378)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 238, subpeak 0 at (161,384)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 240, subpeak 0 at (506,390)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 242, subpeak 0 at (225,396)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 245, subpeak 1 at (403,405)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 246, subpeak 0 at (546,408)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 247, subpeak 2 at (470,412)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 248, subpeak 0 at (532,409)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 251, subpeak 0 at (619,411)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 252, subpeak 0 at (563,412)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 254, subpeak 0 at (583,414)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 254, subpeak 1 at (586,420)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 255, subpeak 1 at (426,417)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 257, subpeak 0 at (600,423)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 257, subpeak 1 at (611,429)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 258, subpeak 0 at (362,422)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 260, subpeak 0 at (162,424)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 262, subpeak 0 at (284,429)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 264, subpeak 0 at (102,429)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 267, subpeak 0 at (431,436)
[ 54164: 1.008] Failed to find (5x5) centroid of peak 268, subpeak 0 at (222,439)
[ 54164: 1.008] simplexy: found 417 sources.
[ 54164: 1.009] Sorting file "/dev/shm/tmp.xyls.8ay5mF" to "/dev/shm/tmp.sorted.FG1kZf" using columns flux (FLUX) and background (BACKGROUND), descending
[ 54164: 1.011] Scale range: 1 to 3.9 degrees wide
[ 54164: 1.012] Image width 694 pixels; arcsec per pixel range 5.18732 20.2305
[ 54164: 1.012] Writing headers to file /home/q/Downloads/star2/1.axy
[ 54164: 1.012] Copying data block of file /dev/shm/tmp.sorted.FG1kZf to output /home/q/Downloads/star2/1.axy.
[ 54164: 1.012] Deleting temp file /dev/shm/tmp.uncompressed.uCDbEJ
[ 54164: 1.012] Deleting temp file /dev/shm/tmp.xyls.8ay5mF
[ 54164: 1.012] Deleting temp file /dev/shm/tmp.sorted.FG1kZf
[ 54164: 1.012] Solving...
[ 54164: 1.012] Running:
  /usr/local/astrometry/bin/astrometry-engine --index-dir /usr/share/astrometry --verbose /home/q/Downloads/star2/1.axy
Using config file "/usr/local/astrometry/bin/../etc/astrometry.cfg"
Auto-indexing directory "/usr/local/astrometry/data" ...
Skipping directory /usr/local/astrometry/data/.
Skipping directory /usr/local/astrometry/data/..
Auto-indexing directory "/usr/share/astrometry" ...
Checking file "/usr/share/astrometry/index-tycho2-08.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-08.littleendian.fits" is readable, using as index filename
Skipping directory /usr/share/astrometry/.
Checking file "/usr/share/astrometry/index-tycho2-09.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-09.littleendian.fits" is readable, using as index filename
Skipping directory /usr/share/astrometry/..
Checking file "/usr/share/astrometry/index-tycho2-14.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-14.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-11.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-11.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-19.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-19.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-18.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-18.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-10.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-10.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-13.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-13.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-16.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-16.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-15.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-15.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-17.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-17.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-12.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-12.littleendian.fits" is readable, using as index filename
Checking file "/usr/share/astrometry/index-tycho2-07.littleendian.fits"
Index name "/usr/share/astrometry/index-tycho2-07.littleendian.fits" is readable, using as index filename
Trying to add index "/usr/share/astrometry/index-tycho2-19.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-19.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-19.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-19.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-19.littleendian.fits" is readable, using as index filename
Index scale: [1400, 2000] arcmin, [84000, 120000] arcsec
Index has 1728 quads and 1080 stars
Trying to add index "/usr/share/astrometry/index-tycho2-18.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-18.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-18.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-18.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-18.littleendian.fits" is readable, using as index filename
Index scale: [1000, 1400] arcmin, [60000, 84000] arcsec
Index has 3072 quads and 1920 stars
Trying to add index "/usr/share/astrometry/index-tycho2-17.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-17.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-17.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-17.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-17.littleendian.fits" is readable, using as index filename
Index scale: [680, 1000] arcmin, [40800, 60000] arcsec
Index has 4800 quads and 3000 stars
Trying to add index "/usr/share/astrometry/index-tycho2-16.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-16.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-16.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-16.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-16.littleendian.fits" is readable, using as index filename
Index scale: [480, 680] arcmin, [28800, 40800] arcsec
Index has 9408 quads and 5880 stars
Trying to add index "/usr/share/astrometry/index-tycho2-15.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-15.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-15.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-15.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-15.littleendian.fits" is readable, using as index filename
Index scale: [340, 480] arcmin, [20400, 28800] arcsec
Index has 19200 quads and 12000 stars
Trying to add index "/usr/share/astrometry/index-tycho2-14.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-14.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-14.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-14.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-14.littleendian.fits" is readable, using as index filename
Index scale: [240, 340] arcmin, [14400, 20400] arcsec
Index has 37632 quads and 23520 stars
Trying to add index "/usr/share/astrometry/index-tycho2-13.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-13.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-13.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-13.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-13.littleendian.fits" is readable, using as index filename
Index scale: [170, 240] arcmin, [10200, 14400] arcsec
Index has 76800 quads and 48000 stars
Trying to add index "/usr/share/astrometry/index-tycho2-12.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-12.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-12.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-12.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-12.littleendian.fits" is readable, using as index filename
Index scale: [120, 170] arcmin, [7200, 10200] arcsec
Index has 150528 quads and 94080 stars
Trying to add index "/usr/share/astrometry/index-tycho2-11.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-11.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-11.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-11.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-11.littleendian.fits" is readable, using as index filename
Index scale: [85, 120] arcmin, [5100, 7200] arcsec
Index has 292032 quads and 182520 stars
Trying to add index "/usr/share/astrometry/index-tycho2-10.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-10.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-10.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-10.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-10.littleendian.fits" is readable, using as index filename
Index scale: [60, 85] arcmin, [3600, 5100] arcsec
Index has 580800 quads and 362950 stars
Trying to add index "/usr/share/astrometry/index-tycho2-09.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-09.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-09.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-09.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-09.littleendian.fits" is readable, using as index filename
Index scale: [42, 60] arcmin, [2520, 3600] arcsec
Index has 1168054 quads and 723026 stars
Trying to add index "/usr/share/astrometry/index-tycho2-08.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-08.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-08.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-08.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-08.littleendian.fits" is readable, using as index filename
Index scale: [30, 42] arcmin, [1800, 2520] arcsec
Index has 2320392 quads and 1279364 stars
Trying to add index "/usr/share/astrometry/index-tycho2-07.littleendian.fits".
Index name "/usr/share/astrometry/index-tycho2-07.littleendian.fits" is readable, using as index filename
Index name "/usr/share/astrometry/index-tycho2-07.littleendian.fits" is readable, using as index filename
Loading metadata for /usr/share/astrometry/index-tycho2-07.littleendian.fits...
Index name "/usr/share/astrometry/index-tycho2-07.littleendian.fits" is readable, using as index filename
Index scale: [22, 30] arcmin, [1320, 1800] arcsec
Index has 4422373 quads and 1871011 stars
Reading file "/home/q/Downloads/star2/1.axy"...
Set odds ratio to solve to 1e+09 (log = 20.7233)
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 0
enddepth 10
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Index name "/usr/share/astrometry/index-tycho2-14.littleendian.fits" is readable, using as index filename
Index scale: [240, 340] arcmin, [14400, 20400] arcsec
Index has 37632 quads and 23520 stars
Trying index /usr/share/astrometry/index-tycho2-14.littleendian.fits...
Solving field 1.
Solver:
  Arcsec per pix range: 5.18732, 20.2305
  Image size: 694 x 464
  Quad size range: 46.4, 0
  Objs: 0, 10
  Parity: 2, both
  Use_radec? no
  Pixel xscale: 0
  Verify_pix: 1
  Code tol: 0.01
  Dist from quad bonus: yes
  Distractor ratio: 0.25
  Log tune-up threshold: 13.8155
  Log bail threshold: -230.259
  Log stoplooking threshold: 1e+30
  Maxquads 0
  Maxmatches 0
  Set CRPIX? no
  Tweak? yes
    Forward order 2
    Reverse order 2
  Indexes: 1
    /usr/share/astrometry/index-tycho2-14.littleendian.fits
  Field (processed): 417 stars
  Field (orig): 417 stars
Quad scale range: [704.665, 3939.8] pixels
object 1 of 10: 0 quads tried, 0 matched.
object 2 of 10: 0 quads tried, 0 matched.
object 3 of 10: 0 quads tried, 0 matched.
object 4 of 10: 0 quads tried, 0 matched.
object 5 of 10: 0 quads tried, 0 matched.
object 6 of 10: 0 quads tried, 0 matched.
object 7 of 10: 0 quads tried, 0 matched.
object 8 of 10: 0 quads tried, 0 matched.
object 9 of 10: 0 quads tried, 0 matched.
object 10 of 10: 15 quads tried, 424 matched.
Field 1: tried 15 quads, matched 424 codes.
Field 1 did not solve (index index-tycho2-14.littleendian.fits, field objects 1-10).
Best odds encountered: 1
Spent 0.001104 s user, 4.6e-05 s system, 0.00115 s total, 0.001152 s wall time.
Index name "/usr/share/astrometry/index-tycho2-13.littleendian.fits" is readable, using as index filename
Index scale: [170, 240] arcmin, [10200, 14400] arcsec
Index has 76800 quads and 48000 stars
Trying index /usr/share/astrometry/index-tycho2-13.littleendian.fits...
Solving field 1.
Solver:
  Arcsec per pix range: 5.18732, 20.2305
  Image size: 694 x 464
  Quad size range: 46.4, 0
  Objs: 0, 10
  Parity: 2, both
  Use_radec? no
  Pixel xscale: 0
  Verify_pix: 1
  Code tol: 0.01
  Dist from quad bonus: yes
  Distractor ratio: 0.25
  Log tune-up threshold: 13.8155
  Log bail threshold: -230.259
  Log stoplooking threshold: 1e+30
  Maxquads 0
  Maxmatches 0
  Set CRPIX? no
  Tweak? yes
    Forward order 2
    Reverse order 2
  Indexes: 1
    /usr/share/astrometry/index-tycho2-13.littleendian.fits
  Field (processed): 417 stars
  Field (orig): 417 stars
Quad scale range: [499.155, 2781.03] pixels
object 1 of 10: 0 quads tried, 0 matched.
object 2 of 10: 0 quads tried, 0 matched.
object 3 of 10: 0 quads tried, 0 matched.
object 4 of 10: 0 quads tried, 0 matched.
object 5 of 10: 0 quads tried, 0 matched.
object 6 of 10: 7 quads tried, 373 matched.
Got a new best match: logodds 2.59258.
object 7 of 10: 14 quads tried, 836 matched.
Got a new best match: logodds 3.41327.
object 8 of 10: 21 quads tried, 1228 matched.
object 9 of 10: 30 quads tried, 1662 matched.
Got a new best match: logodds 5.48614.
Got a new best match: logodds 5.87867.
object 10 of 10: 61 quads tried, 3516 matched.
Field 1: tried 61 quads, matched 3516 codes.
Field 1 did not solve (index index-tycho2-13.littleendian.fits, field objects 1-10).
Best odds encountered: 357.333
Spent 0.058444 s user, 0.000767 s system, 0.059211 s total, 0.060707 s wall time.
Index name "/usr/share/astrometry/index-tycho2-12.littleendian.fits" is readable, using as index filename
Index scale: [120, 170] arcmin, [7200, 10200] arcsec
Index has 150528 quads and 94080 stars
Trying index /usr/share/astrometry/index-tycho2-12.littleendian.fits...
Solving field 1.
Solver:
  Arcsec per pix range: 5.18732, 20.2305
  Image size: 694 x 464
  Quad size range: 46.4, 0
  Objs: 0, 10
  Parity: 2, both
  Use_radec? no
  Pixel xscale: 0
  Verify_pix: 1
  Code tol: 0.01
  Dist from quad bonus: yes
  Distractor ratio: 0.25
  Log tune-up threshold: 13.8155
  Log bail threshold: -230.259
  Log stoplooking threshold: 1e+30
  Maxquads 0
  Maxmatches 0
  Set CRPIX? no
  Tweak? yes
    Forward order 2
    Reverse order 2
  Indexes: 1
    /usr/share/astrometry/index-tycho2-12.littleendian.fits
  Field (processed): 417 stars
  Field (orig): 417 stars
Quad scale range: [352.332, 1969.9] pixels
object 1 of 10: 0 quads tried, 0 matched.
object 2 of 10: 0 quads tried, 0 matched.
object 3 of 10: 0 quads tried, 0 matched.
object 4 of 10: 0 quads tried, 0 matched.
Got a new best match: logodds 0.659953.
Got a new best match: logodds 2.52067.
object 5 of 10: 5 quads tried, 509 matched.
Got a new best match: logodds 2.93255.
Got a new best match: logodds 3.80835.
Got a new best match: logodds 4.44773.
Got a new best match: logodds 4.64352.
object 6 of 10: 12 quads tried, 1240 matched.
Got a new best match: logodds 5.2662.
Got a new best match: logodds 5.94145.
object 7 of 10: 25 quads tried, 2786 matched.
Got a new best match: logodds 7.55116.
object 8 of 10: 39 quads tried, 4328 matched.
object 9 of 10: 56 quads tried, 6040 matched.
Got a new best match: logodds 9.18871.
After removing quad stars: no reference stars
object 10 of 10: 88 quads tried, 9692 matched.
Field 1: tried 88 quads, matched 9692 codes.
Field 1 did not solve (index index-tycho2-12.littleendian.fits, field objects 1-10).
Best odds encountered: 9786.03
Spent 0.278491 s user, 0.010006 s system, 0.288497 s total, 0.29051 s wall time.
Index name "/usr/share/astrometry/index-tycho2-11.littleendian.fits" is readable, using as index filename
Index scale: [85, 120] arcmin, [5100, 7200] arcsec
Index has 292032 quads and 182520 stars
Trying index /usr/share/astrometry/index-tycho2-11.littleendian.fits...
Solving field 1.
Solver:
  Arcsec per pix range: 5.18732, 20.2305
  Image size: 694 x 464
  Quad size range: 46.4, 0
  Objs: 0, 10
  Parity: 2, both
  Use_radec? no
  Pixel xscale: 0
  Verify_pix: 1
  Code tol: 0.01
  Dist from quad bonus: yes
  Distractor ratio: 0.25
  Log tune-up threshold: 13.8155
  Log bail threshold: -230.259
  Log stoplooking threshold: 1e+30
  Maxquads 0
  Maxmatches 0
  Set CRPIX? no
  Tweak? yes
    Forward order 2
    Reverse order 2
  Indexes: 1
    /usr/share/astrometry/index-tycho2-11.littleendian.fits
  Field (processed): 417 stars
  Field (orig): 417 stars
Quad scale range: [249.577, 1390.52] pixels
object 1 of 10: 0 quads tried, 0 matched.
object 2 of 10: 0 quads tried, 0 matched.
object 3 of 10: 0 quads tried, 0 matched.
object 4 of 10: 0 quads tried, 0 matched.
Got a new best match: logodds 0.981164.
Got a new best match: logodds 3.65714.
Got a new best match: logodds 4.98475.
Got a new best match: logodds 8.24118.
object 5 of 10: 5 quads tried, 982 matched.
object 6 of 10: 12 quads tried, 2413 matched.
object 7 of 10: 26 quads tried, 5574 matched.
object 8 of 10: 41 quads tried, 8814 matched.
object 9 of 10: 60 quads tried, 12521 matched.
After removing quad stars: no reference stars
object 10 of 10: 92 quads tried, 19679 matched.
Field 1: tried 92 quads, matched 19679 codes.
Field 1 did not solve (index index-tycho2-11.littleendian.fits, field objects 1-10).
Best odds encountered: 3794.03
Spent 0.988171 s user, 0.014018 s system, 1.00219 s total, 1.004 s wall time.
Index name "/usr/share/astrometry/index-tycho2-10.littleendian.fits" is readable, using as index filename
Index scale: [60, 85] arcmin, [3600, 5100] arcsec
Index has 580800 quads and 362950 stars
Trying index /usr/share/astrometry/index-tycho2-10.littleendian.fits...
Solving field 1.
Solver:
  Arcsec per pix range: 5.18732, 20.2305
  Image size: 694 x 464
  Quad size range: 46.4, 0
  Objs: 0, 10
  Parity: 2, both
  Use_radec? no
  Pixel xscale: 0
  Verify_pix: 1
  Code tol: 0.01
  Dist from quad bonus: yes
  Distractor ratio: 0.25
  Log tune-up threshold: 13.8155
  Log bail threshold: -230.259
  Log stoplooking threshold: 1e+30
  Maxquads 0
  Maxmatches 0
  Set CRPIX? no
  Tweak? yes
    Forward order 2
    Reverse order 2
  Indexes: 1
    /usr/share/astrometry/index-tycho2-10.littleendian.fits
  Field (processed): 417 stars
  Field (orig): 417 stars
Quad scale range: [176.166, 984.949] pixels
object 1 of 10: 0 quads tried, 0 matched.
object 2 of 10: 0 quads tried, 0 matched.
object 3 of 10: 0 quads tried, 0 matched.
object 4 of 10: 0 quads tried, 0 matched.
object 5 of 10: 3 quads tried, 1 matched.
object 6 of 10: 7 quads tried, 2 matched.
object 7 of 10: 21 quads tried, 2 matched.
object 8 of 10: 47 quads tried, 6 matched.
object 9 of 10: 91 quads tried, 6 matched.
object 10 of 10: 167 quads tried, 9 matched.
Field 1: tried 167 quads, matched 9 codes.
Field 1 did not solve (index index-tycho2-10.littleendian.fits, field objects 1-10).
Best odds encountered: 1
Spent 0.001201 s user, 0.001006 s system, 0.002207 s total, 0.002207 s wall time.
Index name "/usr/share/astrometry/index-tycho2-09.littleendian.fits" is readable, using as index filename
Index scale: [42, 60] arcmin, [2520, 3600] arcsec
Index has 1168054 quads and 723026 stars
Trying index /usr/share/astrometry/index-tycho2-09.littleendian.fits...
Solving field 1.
Solver:
  Arcsec per pix range: 5.18732, 20.2305
  Image size: 694 x 464
  Quad size range: 46.4, 0
  Objs: 0, 10
  Parity: 2, both
  Use_radec? no
  Pixel xscale: 0
  Verify_pix: 1
  Code tol: 0.01
  Dist from quad bonus: yes
  Distractor ratio: 0.25
  Log tune-up threshold: 13.8155
  Log bail threshold: -230.259
  Log stoplooking threshold: 1e+30
  Maxquads 0
  Maxmatches 0
  Set CRPIX? no
  Tweak? yes
    Forward order 2
    Reverse order 2
  Indexes: 1
    /usr/share/astrometry/index-tycho2-09.littleendian.fits
  Field (processed): 417 stars
  Field (orig): 417 stars
Quad scale range: [123.306, 695.258] pixels
object 1 of 10: 0 quads tried, 0 matched.
object 2 of 10: 0 quads tried, 0 matched.
object 3 of 10: 0 quads tried, 0 matched.
object 4 of 10: 1 quads tried, 0 matched.
object 5 of 10: 4 quads tried, 0 matched.
object 6 of 10: 8 quads tried, 1 matched.
object 7 of 10: 22 quads tried, 3 matched.
object 8 of 10: 49 quads tried, 6 matched.
object 9 of 10: 95 quads tried, 10 matched.
object 10 of 10: 112 quads tried, 11 matched.
Field 1: tried 112 quads, matched 11 codes.
Field 1 did not solve (index index-tycho2-09.littleendian.fits, field objects 1-10).
Best odds encountered: 1
Spent 0.002678 s user, 1.9e-05 s system, 0.002697 s total, 0.002697 s wall time.
Index name "/usr/share/astrometry/index-tycho2-08.littleendian.fits" is readable, using as index filename
Index scale: [30, 42] arcmin, [1800, 2520] arcsec
Index has 2320392 quads and 1279364 stars
Trying index /usr/share/astrometry/index-tycho2-08.littleendian.fits...
Solving field 1.
Solver:
  Arcsec per pix range: 5.18732, 20.2305
  Image size: 694 x 464
  Quad size range: 46.4, 0
  Objs: 0, 10
  Parity: 2, both
  Use_radec? no
  Pixel xscale: 0
  Verify_pix: 1
  Code tol: 0.01
  Dist from quad bonus: yes
  Distractor ratio: 0.25
  Log tune-up threshold: 13.8155
  Log bail threshold: -230.259
  Log stoplooking threshold: 1e+30
  Maxquads 0
  Maxmatches 0
  Set CRPIX? no
  Tweak? yes
    Forward order 2
    Reverse order 2
  Indexes: 1
    /usr/share/astrometry/index-tycho2-08.littleendian.fits
  Field (processed): 417 stars
  Field (orig): 417 stars
Quad scale range: [88.0936, 486.681] pixels
object 1 of 10: 0 quads tried, 0 matched.
object 2 of 10: 0 quads tried, 0 matched.
object 3 of 10: 0 quads tried, 0 matched.
object 4 of 10: 1 quads tried, 0 matched.
object 5 of 10: 4 quads tried, 0 matched.
object 6 of 10: 4 quads tried, 0 matched.
object 7 of 10: 8 quads tried, 1 matched.
Got a new best match: logodds 2.39853.
object 8 of 10: 20 quads tried, 4 matched.
object 9 of 10: 43 quads tried, 7 matched.
object 10 of 10: 43 quads tried, 7 matched.
Field 1: tried 43 quads, matched 7 codes.
Field 1 did not solve (index index-tycho2-08.littleendian.fits, field objects 1-10).
Best odds encountered: 11.007
Spent 0.001988 s user, 0 s system, 0.001988 s total, 0.001989 s wall time.
Index name "/usr/share/astrometry/index-tycho2-07.littleendian.fits" is readable, using as index filename
Index scale: [22, 30] arcmin, [1320, 1800] arcsec
Index has 4422373 quads and 1871011 stars
Trying index /usr/share/astrometry/index-tycho2-07.littleendian.fits...
Solving field 1.
Solver:
  Arcsec per pix range: 5.18732, 20.2305
  Image size: 694 x 464
  Quad size range: 46.4, 0
  Objs: 0, 10
  Parity: 2, both
  Use_radec? no
  Pixel xscale: 0
  Verify_pix: 1
  Code tol: 0.01
  Dist from quad bonus: yes
  Distractor ratio: 0.25
  Log tune-up threshold: 13.8155
  Log bail threshold: -230.259
  Log stoplooking threshold: 1e+30
  Maxquads 0
  Maxmatches 0
  Set CRPIX? no
  Tweak? yes
    Forward order 2
    Reverse order 2
  Indexes: 1
    /usr/share/astrometry/index-tycho2-07.littleendian.fits
  Field (processed): 417 stars
  Field (orig): 417 stars
Quad scale range: [64.6187, 347.629] pixels
object 1 of 10: 0 quads tried, 0 matched.
object 2 of 10: 0 quads tried, 0 matched.
object 3 of 10: 0 quads tried, 0 matched.
object 4 of 10: 1 quads tried, 0 matched.
object 5 of 10: 1 quads tried, 0 matched.
object 6 of 10: 1 quads tried, 0 matched.
object 7 of 10: 1 quads tried, 0 matched.
Got a new best match: logodds 0.95932.
Got a new best match: logodds 339.984.
mo field stars:
  star 3; field_xy 560.5,27.0, field_orig 560.5,27.0
  star 7; field_xy 592.0,153.0, field_orig 592.0,153.0
  star 1; field_xy 618.0,59.0, field_orig 618.0,59.0
  star 2; field_xy 614.8,79.6, field_orig 614.8,79.6
  log-odds ratio 339.984 (4.50061e+147), 192 match, 12 conflict, 127 distractors, 301 index.
  RA,Dec = (266.197,20.711), pixel scale 13.6356 arcsec/pix.
  Hit/miss:   Hit/miss: +c-+++++---+++-++++c++++++-++-++++-++-+++++-+++++c+-++-c+++++++++-++++-+++-+++-+-++++++-++++-++c++++
Pixel scale: 13.6356 arcsec/pix.
Parity: neg.
solver_tweak2: setting orders 2, 2
solver_tweak2: set_crpix 0, crpix (0.0,0.0)
tweak2: starting orders 2, 2
Tweak2: starting from WCS:
TAN-SIP Structure:
  crval=(267.367, 20.8776)
  crpix=(596.33, 79.6551)
  CD = (    0.0029068     -0.0024283 )
       (    0.0024283      0.0029068 )
  image size = (694 x 464)
  SIP order: A=2, B=2, AP=2, BP=2
  A =            0           0           0
                 0           0
                 0
  B =            0           0           0
                 0           0
                 0
  AP =            0           0           0
                 0           0
                 0
  BP =            0           0           0
                 0           0
                 0
  sqrt(det(CD))=13.6356 [arcsec]
Annealing: order 1, step 0, gamma = 1
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 361 of 417
Good bins: 100 / 117; effA 322016 of 275227
Ref stars in RoR: 245 of 301
Logodds: 363.937
243 matches, 86 distractors, 14 conflicts (at best log-odds); 417 field sources, 301 index sources
258 matches, 139 distractors, 20 conflicts (all sources)
Hit/miss: +++++c+-+++++c+++c+++-++++++++++--++++++-++++c++++-+++--+++----c-+-+++++++++-++-++--+c+-++++++-+-+++
Moved quad center to (398.1, 218.0)
tweak2: setting orders 1, 2
Total weight: 170.91
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -0.0014329,-0.000172853 deg (-0.319345,0.207273 pix) to CRVAL and CD.
Annealing: order 1, step 1, gamma = 0.9
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 533.368
241 matches, 149 distractors, 9 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 165 distractors, 10 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++c++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (338.7, 234.9)
tweak2: setting orders 1, 2
Total weight: 218.431
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = 0.000130041,-8.01088e-05 deg (0.0127952,-0.0382028 pix) to CRVAL and CD.
Annealing: order 1, step 2, gamma = 0.81
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 562.514
241 matches, 150 distractors, 8 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 165 distractors, 10 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (332.1, 235.8)
tweak2: setting orders 1, 2
Total weight: 221.747
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = 2.51135e-05,-2.64075e-05 deg (0.000623939,-0.00959219 pix) to CRVAL and CD.
Annealing: order 1, step 3, gamma = 0.729
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 583.559
241 matches, 152 distractors, 6 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 168 distractors, 7 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.5, 235.9)
tweak2: setting orders 1, 2
Total weight: 223.399
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.11497e-06,3.77215e-06 deg (-0.00019594,0.00145938 pix) to CRVAL and CD.
Annealing: order 1, step 4, gamma = 0.6561
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 604.008
241 matches, 153 distractors, 5 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 170 distractors, 5 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 235.9)
tweak2: setting orders 1, 2
Total weight: 224.874
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.96356e-06,7.05268e-06 deg (-0.000218554,0.00260518 pix) to CRVAL and CD.
Annealing: order 1, step 5, gamma = 0.59049
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 624.083
241 matches, 154 distractors, 4 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 171 distractors, 4 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 235.9)
tweak2: setting orders 1, 2
Total weight: 226.209
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.81392e-06,8.46992e-06 deg (-0.000353777,0.00320496 pix) to CRVAL and CD.
Annealing: order 1, step 6, gamma = 0.531441
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 643.783
241 matches, 155 distractors, 3 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 172 distractors, 3 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 235.8)
tweak2: setting orders 1, 2
Total weight: 227.428
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.1935e-06,9.87778e-06 deg (-0.000192853,0.00355425 pix) to CRVAL and CD.
Annealing: order 1, step 7, gamma = 0.478297
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 663.093
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.3, 235.8)
tweak2: setting orders 1, 2
Total weight: 228.538
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.6188e-06,1.13394e-05 deg (-3.21066e-05,0.00392216 pix) to CRVAL and CD.
Annealing: order 1, step 8, gamma = 0.430467
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 681.992
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.3, 235.9)
tweak2: setting orders 1, 2
Total weight: 229.546
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.00881e-05,1.28203e-05 deg (0.000122993,0.00430144 pix) to CRVAL and CD.
Annealing: order 1, step 9, gamma = 0.38742
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 700.462
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.2, 235.9)
tweak2: setting orders 1, 2
Total weight: 230.457
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.05548e-05,1.42324e-05 deg (0.000267016,0.00466633 pix) to CRVAL and CD.
Annealing: order 1, step 10, gamma = 0.348678
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 718.487
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.2, 235.9)
tweak2: setting orders 1, 2
Total weight: 231.277
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.09456e-05,1.54418e-05 deg (0.000392139,0.00497736 pix) to CRVAL and CD.
Annealing: order 1, step 11, gamma = 0.313811
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 736.047
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.1, 235.9)
tweak2: setting orders 1, 2
Total weight: 232.013
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.11629e-05,1.62711e-05 deg (0.000488218,0.00518211 pix) to CRVAL and CD.
Annealing: order 1, step 12, gamma = 0.28243
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 753.126
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 174 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 1, 2
Total weight: 232.212
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.13284e-05,9.20914e-05 deg (0.00516253,0.0273277 pix) to CRVAL and CD.
Annealing: order 1, step 13, gamma = 0.254187
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 769.721
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 174 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 1, 2
Total weight: 232.849
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.10402e-06,-4.69233e-07 deg (-0.000505152,0.000260691 pix) to CRVAL and CD.
Annealing: order 1, step 14, gamma = 0.228768
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 785.785
241 matches, 157 distractors, 1 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 175 distractors, 1 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 1, 2
Total weight: 233.422
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.64758e-06,-5.01376e-07 deg (-0.000418185,0.000177013 pix) to CRVAL and CD.
Annealing: order 1, step 15, gamma = 0.205891
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 801.323
241 matches, 157 distractors, 1 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 175 distractors, 1 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 1, 2
Total weight: 233.932
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.55941e-06,-4.9502e-07 deg (-0.000399265,0.000163394 pix) to CRVAL and CD.
Annealing: order 1, step 16, gamma = 0.185302
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 816.32
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 1, 2
Total weight: 234.393
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.41373e-06,-4.47268e-07 deg (-0.00036171,0.000148434 pix) to CRVAL and CD.
Annealing: order 1, step 17, gamma = 0.166772
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 830.767
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 1, 2
Total weight: 234.809
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.27978e-06,-4.03509e-07 deg (-0.000327206,0.00013465 pix) to CRVAL and CD.
Annealing: order 1, step 18, gamma = 0.150095
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 844.653
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 1, 2
Total weight: 235.186
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.15765e-06,-3.63859e-07 deg (-0.000295788,0.000122033 pix) to CRVAL and CD.
Annealing: order 1, step 19, gamma = 0.135085
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 857.97
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 235.526
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.04645e-06,-3.27963e-07 deg (-0.000267217,0.000110502 pix) to CRVAL and CD.
Annealing: order 1, step 20, gamma = 0.121577
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 870.713
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 235.834
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.45296e-07,-2.95484e-07 deg (-0.000241255,9.99779e-05 pix) to CRVAL and CD.
Annealing: order 1, step 21, gamma = 0.109419
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 882.879
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 236.111
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.53352e-07,-2.66112e-07 deg (-0.000217683,9.03815e-05 pix) to CRVAL and CD.
Annealing: order 1, step 22, gamma = 0.0984771
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 894.466
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 236.361
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -7.69835e-07,-2.39563e-07 deg (-0.000196293,8.16383e-05 pix) to CRVAL and CD.
Annealing: order 1, step 23, gamma = 0.0886294
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 905.476
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 236.586
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.94016e-07,-2.15578e-07 deg (-0.000176895,7.3677e-05 pix) to CRVAL and CD.
Annealing: order 1, step 24, gamma = 0.0797664
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 915.911
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 236.79
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.25214e-07,-1.93921e-07 deg (-0.00015931,6.6431e-05 pix) to CRVAL and CD.
Annealing: order 1, step 25, gamma = 0.0717898
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 925.778
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 236.973
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.62802e-07,-1.74374e-07 deg (-0.000143375,5.98377e-05 pix) to CRVAL and CD.
Annealing: order 1, step 26, gamma = 0.0646108
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 935.085
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.138
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.06201e-07,-1.56741e-07 deg (-0.000128939,5.38393e-05 pix) to CRVAL and CD.
Annealing: order 1, step 27, gamma = 0.0581497
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 943.843
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.286
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.5488e-07,-1.40841e-07 deg (-0.000115866,4.83826e-05 pix) to CRVAL and CD.
Annealing: order 1, step 28, gamma = 0.0523348
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 952.063
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.419
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.08355e-07,-1.26511e-07 deg (-0.000104028,4.3419e-05 pix) to CRVAL and CD.
Annealing: order 1, step 29, gamma = 0.0471013
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 959.761
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.54
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.66186e-07,-1.13601e-07 deg (-9.33111e-05,3.89041e-05 pix) to CRVAL and CD.
Annealing: order 1, step 30, gamma = 0.0423912
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 966.953
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.648
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.27973e-07,-1.01975e-07 deg (-8.36123e-05,3.4798e-05 pix) to CRVAL and CD.
Annealing: order 1, step 31, gamma = 0.038152
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 973.655
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.745
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.93356e-07,-9.15091e-08 deg (-7.48375e-05,3.10648e-05 pix) to CRVAL and CD.
Annealing: order 1, step 32, gamma = 0.0343368
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 979.889
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.832
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.62009e-07,-8.20921e-08 deg (-6.69017e-05,2.76722e-05 pix) to CRVAL and CD.
Annealing: order 1, step 33, gamma = 0.0309032
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 985.673
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.911
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.33641e-07,-7.36215e-08 deg (-5.97287e-05,2.45915e-05 pix) to CRVAL and CD.
Annealing: order 1, step 34, gamma = 0.0278128
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 991.028
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 237.981
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.07989e-07,-6.60051e-08 deg (-5.32497e-05,2.1797e-05 pix) to CRVAL and CD.
Annealing: order 1, step 35, gamma = 0.0250316
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 995.977
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.044
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.84816e-07,-5.9159e-08 deg (-4.74027e-05,1.92657e-05 pix) to CRVAL and CD.
Annealing: order 1, step 36, gamma = 0.0225284
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1000.54
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.101
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.6391e-07,-5.30076e-08 deg (-4.21319e-05,1.69769e-05 pix) to CRVAL and CD.
Annealing: order 1, step 37, gamma = 0.0202756
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1004.74
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.152
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.45078e-07,-4.74825e-08 deg (-3.73868e-05,1.4912e-05 pix) to CRVAL and CD.
Annealing: order 1, step 38, gamma = 0.018248
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1008.6
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.198
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.28147e-07,-4.25218e-08 deg (-3.31216e-05,1.30541e-05 pix) to CRVAL and CD.
Annealing: order 1, step 39, gamma = 0.0164232
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1012.15
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.239
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.12956e-07,-3.80698e-08 deg (-2.92947e-05,1.13874e-05 pix) to CRVAL and CD.
Annealing: order 1, step 40, gamma = 0.0147809
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1015.39
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.276
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.93584e-08,-3.40759e-08 deg (-2.58677e-05,9.89734e-06 pix) to CRVAL and CD.
Annealing: order 1, step 41, gamma = 0.0133028
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1018.36
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.31
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.72189e-08,-3.04948e-08 deg (-2.28055e-05,8.57019e-06 pix) to CRVAL and CD.
Annealing: order 1, step 42, gamma = 0.0119725
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1021.07
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.339
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -7.64107e-08,-2.72851e-08 deg (-2.00756e-05,7.39289e-06 pix) to CRVAL and CD.
Annealing: order 1, step 43, gamma = 0.0107753
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1023.54
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.366
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.68155e-08,-2.44097e-08 deg (-1.76477e-05,6.35295e-06 pix) to CRVAL and CD.
Annealing: order 1, step 44, gamma = 0.00969774
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1025.79
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.39
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.83222e-08,-2.18351e-08 deg (-1.54936e-05,5.43843e-06 pix) to CRVAL and CD.
Annealing: order 1, step 45, gamma = 0.00872796
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1027.84
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.412
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.08266e-08,-1.95307e-08 deg (-1.35871e-05,4.63784e-06 pix) to CRVAL and CD.
Annealing: order 1, step 46, gamma = 0.00785517
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1029.7
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.431
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.42309e-08,-1.7469e-08 deg (-1.19038e-05,3.94024e-06 pix) to CRVAL and CD.
Annealing: order 1, step 47, gamma = 0.00706965
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1031.4
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.448
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.84437e-08,-1.56253e-08 deg (-1.04209e-05,3.3352e-06 pix) to CRVAL and CD.
Annealing: order 1, step 48, gamma = 0.00636269
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1032.93
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.464
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.33796e-08,-1.39769e-08 deg (-9.11739e-06,2.81284e-06 pix) to CRVAL and CD.
Annealing: order 1, step 49, gamma = 0.00572642
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1034.33
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.478
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.89594e-08,-1.25036e-08 deg (-7.97383e-06,2.36391e-06 pix) to CRVAL and CD.
Annealing: order 1, step 50, gamma = 0.00515378
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1035.59
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.491
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.51106e-08,-1.11871e-08 deg (-6.97238e-06,1.97981e-06 pix) to CRVAL and CD.
Annealing: order 1, step 51, gamma = 0.0046384
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1036.73
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.502
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.17662e-08,-1.00108e-08 deg (-6.09673e-06,1.65259e-06 pix) to CRVAL and CD.
Annealing: order 1, step 52, gamma = 0.00417456
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1037.77
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.512
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.88654e-08,-8.95996e-09 deg (-5.33205e-06,1.37498e-06 pix) to CRVAL and CD.
Annealing: order 1, step 53, gamma = 0.0037571
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1038.7
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.521
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.63533e-08,-8.0211e-09 deg (-4.66498e-06,1.1404e-06 pix) to CRVAL and CD.
Annealing: order 1, step 54, gamma = 0.00338139
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1039.55
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.529
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.41807e-08,-7.18228e-09 deg (-4.08352e-06,9.42956e-07 pix) to CRVAL and CD.
Annealing: order 1, step 55, gamma = 0.00304325
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1040.31
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.537
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.23035e-08,-6.43277e-09 deg (-3.57694e-06,7.77366e-07 pix) to CRVAL and CD.
Annealing: order 1, step 56, gamma = 0.00273893
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1041
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.543
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.06826e-08,-5.76294e-09 deg (-3.13571e-06,6.38987e-07 pix) to CRVAL and CD.
Annealing: order 1, step 57, gamma = 0.00246503
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1041.63
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.549
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.28366e-09,-5.16421e-09 deg (-2.75141e-06,5.23723e-07 pix) to CRVAL and CD.
Annealing: order 1, step 58, gamma = 0.00221853
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1042.19
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.555
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.07641e-09,-4.6289e-09 deg (-2.41663e-06,4.28027e-07 pix) to CRVAL and CD.
Annealing: order 1, step 59, gamma = 0.00199668
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1042.7
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.559
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -7.03448e-09,-4.15014e-09 deg (-2.12486e-06,3.48825e-07 pix) to CRVAL and CD.
Annealing: order 1, step 60, gamma = 0.00179701
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1043.16
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.564
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.13479e-09,-3.72187e-09 deg (-1.87041e-06,2.8345e-07 pix) to CRVAL and CD.
Annealing: order 1, step 61, gamma = 0.00161731
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1043.57
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.568
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.3575e-09,-3.33862e-09 deg (-1.64834e-06,2.2965e-07 pix) to CRVAL and CD.
Annealing: order 1, step 62, gamma = 0.00145558
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1043.94
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.571
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.68535e-09,-2.99555e-09 deg (-1.45434e-06,1.8549e-07 pix) to CRVAL and CD.
Annealing: order 1, step 63, gamma = 0.00131002
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1044.28
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.574
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.10362e-09,-2.68836e-09 deg (-1.2847e-06,1.49349e-07 pix) to CRVAL and CD.
Annealing: order 1, step 64, gamma = 0.00117902
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1044.58
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.577
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.59943e-09,-2.4132e-09 deg (-1.13617e-06,1.1983e-07 pix) to CRVAL and CD.
Annealing: order 1, step 65, gamma = 0.00106112
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1044.86
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.58
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.162e-09,-2.16665e-09 deg (-1.00598e-06,9.58049e-08 pix) to CRVAL and CD.
Annealing: order 1, step 66, gamma = 0.000955005
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.1
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.582
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.78179e-09,-1.94568e-09 deg (-8.91703e-07,7.62755e-08 pix) to CRVAL and CD.
Annealing: order 1, step 67, gamma = 0.000859504
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.33
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.584
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.45097e-09,-1.74757e-09 deg (-7.91277e-07,6.04666e-08 pix) to CRVAL and CD.
Annealing: order 1, step 68, gamma = 0.000773554
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.53
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.586
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.16253e-09,-1.5699e-09 deg (-7.02885e-07,4.76812e-08 pix) to CRVAL and CD.
Annealing: order 1, step 69, gamma = 0.000696199
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.71
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.588
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.91075e-09,-1.41052e-09 deg (-6.24999e-07,3.73914e-08 pix) to CRVAL and CD.
Annealing: order 1, step 70, gamma = 0.000626579
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.87
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.589
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.6905e-09,-1.26751e-09 deg (-5.56263e-07,2.91161e-08 pix) to CRVAL and CD.
Annealing: order 1, step 71, gamma = 0.000563921
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.01
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.59
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.49756e-09,-1.13915e-09 deg (-4.95529e-07,2.24908e-08 pix) to CRVAL and CD.
Annealing: order 1, step 72, gamma = 0.000507529
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.15
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.592
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.32827e-09,-1.02392e-09 deg (-4.41801e-07,1.72053e-08 pix) to CRVAL and CD.
Annealing: order 1, step 73, gamma = 0.000456776
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.26
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.593
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.17946e-09,-9.20458e-10 deg (-3.94205e-07,1.29998e-08 pix) to CRVAL and CD.
Annealing: order 1, step 74, gamma = 0.000411098
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.37
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.594
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.04849e-09,-8.27532e-10 deg (-3.51999e-07,9.67566e-09 pix) to CRVAL and CD.
Annealing: order 1, step 75, gamma = 0.000369988
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.47
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.595
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.3307e-10,-7.44069e-10 deg (-3.14539e-07,7.06448e-09 pix) to CRVAL and CD.
Annealing: order 1, step 76, gamma = 0.00033299
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.55
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.595
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.31026e-10,-6.69077e-10 deg (-2.81218e-07,4.99951e-09 pix) to CRVAL and CD.
Annealing: order 1, step 77, gamma = 0.000299691
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.63
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.596
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -7.4085e-10,-6.01698e-10 deg (-2.51585e-07,3.39907e-09 pix) to CRVAL and CD.
Annealing: order 1, step 78, gamma = 0.000269722
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.7
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.597
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.61028e-10,-5.41136e-10 deg (-2.25198e-07,2.16851e-09 pix) to CRVAL and CD.
Annealing: order 1, step 79, gamma = 0.000242749
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.76
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.597
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.90207e-10,-4.86713e-10 deg (-2.01671e-07,1.2166e-09 pix) to CRVAL and CD.
Annealing: order 1, step 80, gamma = 0.000218475
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.82
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.598
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.27396e-10,-4.37785e-10 deg (-1.80694e-07,5.06139e-10 pix) to CRVAL and CD.
Annealing: order 1, step 81, gamma = 0.000196627
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.87
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.598
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.71559e-10,-3.93801e-10 deg (-1.61962e-07,-2.6387e-11 pix) to CRVAL and CD.
Annealing: order 1, step 82, gamma = 0.000176964
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.92
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.599
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.21866e-10,-3.54246e-10 deg (-1.45223e-07,-4.17373e-10 pix) to CRVAL and CD.
Annealing: order 1, step 83, gamma = 0.000159268
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.96
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.599
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.77625e-10,-3.1869e-10 deg (-1.30263e-07,-6.96469e-10 pix) to CRVAL and CD.
Annealing: order 1, step 84, gamma = 0.000143341
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.599
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.38224e-10,-2.86703e-10 deg (-1.16885e-07,-8.7984e-10 pix) to CRVAL and CD.
Annealing: order 1, step 85, gamma = 0.000129007
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.03
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.6
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.03064e-10,-2.5795e-10 deg (-1.04912e-07,-1.00121e-09 pix) to CRVAL and CD.
Annealing: order 1, step 86, gamma = 0.000116106
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.06
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.6
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.71646e-10,-2.32079e-10 deg (-9.41825e-08,-1.07357e-09 pix) to CRVAL and CD.
Annealing: order 1, step 87, gamma = 0.000104496
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.09
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.6
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.43599e-10,-2.08806e-10 deg (-8.45749e-08,-1.10226e-09 pix) to CRVAL and CD.
Annealing: order 1, step 88, gamma = 9.40461e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.11
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.6
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.18523e-10,-1.87885e-10 deg (-7.59655e-08,-1.10498e-09 pix) to CRVAL and CD.
Annealing: order 1, step 89, gamma = 8.46415e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.13
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.601
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.96116e-10,-1.69054e-10 deg (-6.82496e-08,-1.07957e-09 pix) to CRVAL and CD.
Annealing: order 1, step 90, gamma = 7.61773e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.15
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.601
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.76024e-10,-1.52115e-10 deg (-6.13216e-08,-1.04597e-09 pix) to CRVAL and CD.
Annealing: order 1, step 91, gamma = 6.85596e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.17
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.601
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.5801e-10,-1.36882e-10 deg (-5.51027e-08,-1.00669e-09 pix) to CRVAL and CD.
Annealing: order 1, step 92, gamma = 6.17037e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.19
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.601
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.41904e-10,-1.23168e-10 deg (-4.95262e-08,-9.52253e-10 pix) to CRVAL and CD.
Annealing: order 1, step 93, gamma = 5.55333e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.2
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.601
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.27423e-10,-1.10835e-10 deg (-4.45119e-08,-9.02937e-10 pix) to CRVAL and CD.
Annealing: order 1, step 94, gamma = 4.998e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.22
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.601
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.14497e-10,-9.97357e-11 deg (-4.0021e-08,-8.4052e-10 pix) to CRVAL and CD.
Annealing: order 1, step 95, gamma = 4.4982e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.23
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.602
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.02884e-10,-8.97532e-11 deg (-3.59843e-08,-7.82291e-10 pix) to CRVAL and CD.
Annealing: order 1, step 96, gamma = 4.04838e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.24
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.602
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.24544e-11,-8.07687e-11 deg (-3.23557e-08,-7.26086e-10 pix) to CRVAL and CD.
Annealing: order 1, step 97, gamma = 3.64354e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.25
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.602
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.31241e-11,-7.26927e-11 deg (-2.91031e-08,-6.67997e-10 pix) to CRVAL and CD.
Annealing: order 1, step 98, gamma = 3.27919e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.26
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.602
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -7.47172e-11,-6.54104e-11 deg (-2.61715e-08,-6.14524e-10 pix) to CRVAL and CD.
Annealing: order 1, step 99, gamma = 0
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.33
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 1, 2
Total weight: 238.602
sip_compute-inverse_polynomials: A 1, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.58278e-10,-5.87353e-10 deg (-2.32447e-07,-7.65616e-09 pix) to CRVAL and CD.
Annealing: order 2, step 0, gamma = 1
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 520.372
241 matches, 149 distractors, 9 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 163 distractors, 12 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.3, 236.0)
tweak2: setting orders 2, 2
Total weight: 218.101
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = 4.44702e-06,-0.000430172 deg (-0.0717296,-0.0879062 pix) to CRVAL and CD.
Annealing: order 2, step 1, gamma = 0.9
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 541.761
241 matches, 150 distractors, 8 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 164 distractors, 11 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 236.0)
tweak2: setting orders 2, 2
Total weight: 220.021
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.75418e-06,6.57421e-06 deg (-5.64586e-05,0.00230416 pix) to CRVAL and CD.
Annealing: order 2, step 2, gamma = 0.81
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 562.848
241 matches, 150 distractors, 8 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 164 distractors, 11 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 235.9)
tweak2: setting orders 2, 2
Total weight: 221.785
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.57859e-06,1.262e-05 deg (0.000391763,0.00400636 pix) to CRVAL and CD.
Annealing: order 2, step 3, gamma = 0.729
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 583.618
241 matches, 152 distractors, 6 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 168 distractors, 7 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 235.9)
tweak2: setting orders 2, 2
Total weight: 223.405
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.00832e-06,1.39083e-05 deg (0.000522176,0.0043401 pix) to CRVAL and CD.
Annealing: order 2, step 4, gamma = 0.6561
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 604.052
241 matches, 153 distractors, 5 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 170 distractors, 5 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 235.9)
tweak2: setting orders 2, 2
Total weight: 224.879
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.54654e-06,1.52891e-05 deg (0.000646201,0.00471092 pix) to CRVAL and CD.
Annealing: order 2, step 5, gamma = 0.59049
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 624.131
241 matches, 154 distractors, 4 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 171 distractors, 4 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 235.8)
tweak2: setting orders 2, 2
Total weight: 226.214
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.28665e-05,1.65705e-05 deg (0.000189568,0.00553168 pix) to CRVAL and CD.
Annealing: order 2, step 6, gamma = 0.531441
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 643.839
241 matches, 155 distractors, 3 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 172 distractors, 3 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.4, 235.8)
tweak2: setting orders 2, 2
Total weight: 227.433
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.35843e-05,1.84482e-05 deg (0.000361083,0.0060336 pix) to CRVAL and CD.
Annealing: order 2, step 7, gamma = 0.478297
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 663.155
241 matches, 155 distractors, 3 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 172 distractors, 3 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.3, 235.8)
tweak2: setting orders 2, 2
Total weight: 228.543
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.4392e-05,2.04784e-05 deg (0.000540136,0.00658166 pix) to CRVAL and CD.
Annealing: order 2, step 8, gamma = 0.430467
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 682.062
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.3, 235.9)
tweak2: setting orders 2, 2
Total weight: 229.55
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.52599e-05,2.2572e-05 deg (0.000717716,0.00715278 pix) to CRVAL and CD.
Annealing: order 2, step 9, gamma = 0.38742
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 700.54
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.2, 235.9)
tweak2: setting orders 2, 2
Total weight: 230.46
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.61066e-05,2.45801e-05 deg (0.000885154,0.00770303 pix) to CRVAL and CD.
Annealing: order 2, step 10, gamma = 0.348678
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 718.573
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.2, 235.9)
tweak2: setting orders 2, 2
Total weight: 231.28
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.68099e-05,2.62795e-05 deg (0.00102953,0.00816653 pix) to CRVAL and CD.
Annealing: order 2, step 11, gamma = 0.313811
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 736.142
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 173 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (331.1, 235.9)
tweak2: setting orders 2, 2
Total weight: 232.014
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.7207e-05,2.73735e-05 deg (0.00113379,0.00845564 pix) to CRVAL and CD.
Annealing: order 2, step 12, gamma = 0.28243
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 753.23
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 174 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 2, 2
Total weight: 232.216
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.06793e-05,0.000145214 deg (0.00816504,0.0430711 pix) to CRVAL and CD.
Annealing: order 2, step 13, gamma = 0.254187
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 769.828
241 matches, 156 distractors, 2 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 174 distractors, 2 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 2, 2
Total weight: 232.852
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.62675e-06,6.76225e-08 deg (-0.000521,0.00045788 pix) to CRVAL and CD.
Annealing: order 2, step 14, gamma = 0.228768
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 785.903
241 matches, 157 distractors, 1 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 175 distractors, 1 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 2, 2
Total weight: 233.425
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.81183e-06,-2.5598e-08 deg (-0.000371563,0.000301188 pix) to CRVAL and CD.
Annealing: order 2, step 15, gamma = 0.205891
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 801.452
241 matches, 157 distractors, 1 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 175 distractors, 1 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 2, 2
Total weight: 233.934
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.68175e-06,-3.96499e-08 deg (-0.00034757,0.000276344 pix) to CRVAL and CD.
Annealing: order 2, step 16, gamma = 0.185302
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 816.461
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 2, 2
Total weight: 234.395
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.53736e-06,-3.87616e-08 deg (-0.000318155,0.00025211 pix) to CRVAL and CD.
Annealing: order 2, step 17, gamma = 0.166772
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 830.919
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 2, 2
Total weight: 234.812
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.40356e-06,-3.85687e-08 deg (-0.000291002,0.000229523 pix) to CRVAL and CD.
Annealing: order 2, step 18, gamma = 0.150095
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 844.817
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.6, 236.2)
tweak2: setting orders 2, 2
Total weight: 235.189
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.28126e-06,-3.88226e-08 deg (-0.000266256,0.000208791 pix) to CRVAL and CD.
Annealing: order 2, step 19, gamma = 0.135085
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 858.146
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 235.529
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.16969e-06,-3.94054e-08 deg (-0.000243741,0.000189808 pix) to CRVAL and CD.
Annealing: order 2, step 20, gamma = 0.121577
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 870.902
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 235.836
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.06807e-06,-4.02276e-08 deg (-0.000223283,0.000172458 pix) to CRVAL and CD.
Annealing: order 2, step 21, gamma = 0.109419
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 883.081
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 236.113
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.75639e-07,-4.12194e-08 deg (-0.000204715,0.000156627 pix) to CRVAL and CD.
Annealing: order 2, step 22, gamma = 0.0984771
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 894.68
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 236.363
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.9166e-07,-4.23266e-08 deg (-0.00018788,0.000142201 pix) to CRVAL and CD.
Annealing: order 2, step 23, gamma = 0.0886294
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 905.703
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 236.589
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.15437e-07,-4.35073e-08 deg (-0.000172629,0.000129073 pix) to CRVAL and CD.
Annealing: order 2, step 24, gamma = 0.0797664
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 916.151
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 236.792
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -7.4631e-07,-4.47286e-08 deg (-0.000158824,0.000117136 pix) to CRVAL and CD.
Annealing: order 2, step 25, gamma = 0.0717898
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 926.032
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 236.975
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.83652e-07,-4.59651e-08 deg (-0.000146333,0.00010629 pix) to CRVAL and CD.
Annealing: order 2, step 26, gamma = 0.0646108
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 935.352
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.14
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.26872e-07,-4.71965e-08 deg (-0.000135032,9.64394e-05 pix) to CRVAL and CD.
Annealing: order 2, step 27, gamma = 0.0581497
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 944.123
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.288
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.75416e-07,-4.84064e-08 deg (-0.000124806,8.74929e-05 pix) to CRVAL and CD.
Annealing: order 2, step 28, gamma = 0.0523348
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 952.356
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.422
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.28764e-07,-4.95815e-08 deg (-0.000115548,7.93659e-05 pix) to CRVAL and CD.
Annealing: order 2, step 29, gamma = 0.0471013
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 960.067
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.542
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.86433e-07,-5.07107e-08 deg (-0.000107159,7.1979e-05 pix) to CRVAL and CD.
Annealing: order 2, step 30, gamma = 0.0423912
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 967.271
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.65
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.47977e-07,-5.17843e-08 deg (-9.95454e-05,6.52585e-05 pix) to CRVAL and CD.
Annealing: order 2, step 31, gamma = 0.038152
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 973.987
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.747
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.12987e-07,-5.27945e-08 deg (-9.26236e-05,5.91369e-05 pix) to CRVAL and CD.
Annealing: order 2, step 32, gamma = 0.0343368
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 980.233
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.835
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.81087e-07,-5.37345e-08 deg (-8.63165e-05,5.35522e-05 pix) to CRVAL and CD.
Annealing: order 2, step 33, gamma = 0.0309032
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 986.029
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.913
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.51942e-07,-5.4599e-08 deg (-8.05549e-05,4.84485e-05 pix) to CRVAL and CD.
Annealing: order 2, step 34, gamma = 0.0278128
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 991.397
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 237.984
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.25249e-07,-5.5384e-08 deg (-7.52768e-05,4.37756e-05 pix) to CRVAL and CD.
Annealing: order 2, step 35, gamma = 0.0250316
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 996.358
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.047
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.0074e-07,-5.60869e-08 deg (-7.04277e-05,3.94887e-05 pix) to CRVAL and CD.
Annealing: order 2, step 36, gamma = 0.0225284
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1000.93
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.104
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.78181e-07,-5.67065e-08 deg (-6.59598e-05,3.55484e-05 pix) to CRVAL and CD.
Annealing: order 2, step 37, gamma = 0.0202756
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1005.15
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.155
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.5737e-07,-5.72432e-08 deg (-6.18321e-05,3.19204e-05 pix) to CRVAL and CD.
Annealing: order 2, step 38, gamma = 0.018248
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1009.02
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.201
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.38131e-07,-5.76986e-08 deg (-5.80094e-05,2.85748e-05 pix) to CRVAL and CD.
Annealing: order 2, step 39, gamma = 0.0164232
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1012.57
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.242
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.20316e-07,-5.8076e-08 deg (-5.4462e-05,2.54857e-05 pix) to CRVAL and CD.
Annealing: order 2, step 40, gamma = 0.0147809
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1015.83
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.279
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.03797e-07,-5.83794e-08 deg (-5.11651e-05,2.2631e-05 pix) to CRVAL and CD.
Annealing: order 2, step 41, gamma = 0.0133028
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1018.8
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.312
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.88469e-07,-5.86141e-08 deg (-4.80977e-05,1.99913e-05 pix) to CRVAL and CD.
Annealing: order 2, step 42, gamma = 0.0119725
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1021.52
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.342
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.74239e-07,-5.87859e-08 deg (-4.52424e-05,1.75503e-05 pix) to CRVAL and CD.
Annealing: order 2, step 43, gamma = 0.0107753
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1024
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.369
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.6103e-07,-5.89013e-08 deg (-4.25846e-05,1.52933e-05 pix) to CRVAL and CD.
Annealing: order 2, step 44, gamma = 0.00969774
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1026.26
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.393
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.48775e-07,-5.89668e-08 deg (-4.01115e-05,1.32076e-05 pix) to CRVAL and CD.
Annealing: order 2, step 45, gamma = 0.00872796
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1028.32
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.415
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.37413e-07,-5.89892e-08 deg (-3.78123e-05,1.12817e-05 pix) to CRVAL and CD.
Annealing: order 2, step 46, gamma = 0.00785517
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1030.19
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.434
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.26891e-07,-5.8975e-08 deg (-3.5677e-05,9.50524e-06 pix) to CRVAL and CD.
Annealing: order 2, step 47, gamma = 0.00706965
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1031.89
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.452
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.17158e-07,-5.89304e-08 deg (-3.36968e-05,7.86854e-06 pix) to CRVAL and CD.
Annealing: order 2, step 48, gamma = 0.00636269
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1033.43
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.467
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.0817e-07,-5.88613e-08 deg (-3.18633e-05,6.36262e-06 pix) to CRVAL and CD.
Annealing: order 2, step 49, gamma = 0.00572642
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1034.83
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.481
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.98816e-08,-5.87729e-08 deg (-3.01683e-05,4.97895e-06 pix) to CRVAL and CD.
Annealing: order 2, step 50, gamma = 0.00515378
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1036.1
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.494
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -9.22509e-08,-5.867e-08 deg (-2.86042e-05,3.70944e-06 pix) to CRVAL and CD.
Annealing: order 2, step 51, gamma = 0.0046384
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1037.25
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.505
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -8.52372e-08,-5.85567e-08 deg (-2.71635e-05,2.54636e-06 pix) to CRVAL and CD.
Annealing: order 2, step 52, gamma = 0.00417456
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1038.29
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.515
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -7.88007e-08,-5.84367e-08 deg (-2.58386e-05,1.48226e-06 pix) to CRVAL and CD.
Annealing: order 2, step 53, gamma = 0.0037571
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1039.23
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.525
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -7.29033e-08,-5.83129e-08 deg (-2.46223e-05,5.10083e-07 pix) to CRVAL and CD.
Annealing: order 2, step 54, gamma = 0.00338139
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1040.08
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.533
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.75078e-08,-5.81879e-08 deg (-2.35075e-05,-3.76972e-07 pix) to CRVAL and CD.
Annealing: order 2, step 55, gamma = 0.00304325
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1040.85
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.54
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -6.25785e-08,-5.80638e-08 deg (-2.24874e-05,-1.18537e-06 pix) to CRVAL and CD.
Annealing: order 2, step 56, gamma = 0.00273893
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1041.54
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.547
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.80812e-08,-5.79421e-08 deg (-2.15553e-05,-1.92121e-06 pix) to CRVAL and CD.
Annealing: order 2, step 57, gamma = 0.00246503
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1042.17
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.553
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.39831e-08,-5.78242e-08 deg (-2.07047e-05,-2.59032e-06 pix) to CRVAL and CD.
Annealing: order 2, step 58, gamma = 0.00221853
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1042.73
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.558
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -5.0253e-08,-5.77109e-08 deg (-1.99295e-05,-3.19813e-06 pix) to CRVAL and CD.
Annealing: order 2, step 59, gamma = 0.00199668
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1043.24
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.563
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.68615e-08,-5.7603e-08 deg (-1.92239e-05,-3.74976e-06 pix) to CRVAL and CD.
Annealing: order 2, step 60, gamma = 0.00179701
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1043.7
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.567
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.37808e-08,-5.75008e-08 deg (-1.85822e-05,-4.25e-06 pix) to CRVAL and CD.
Annealing: order 2, step 61, gamma = 0.00161731
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1044.12
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.571
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -4.09851e-08,-5.74047e-08 deg (-1.79993e-05,-4.70328e-06 pix) to CRVAL and CD.
Annealing: order 2, step 62, gamma = 0.00145558
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1044.49
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.575
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.84499e-08,-5.73147e-08 deg (-1.74702e-05,-5.11374e-06 pix) to CRVAL and CD.
Annealing: order 2, step 63, gamma = 0.00131002
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1044.83
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.578
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.61528e-08,-5.72307e-08 deg (-1.69904e-05,-5.48517e-06 pix) to CRVAL and CD.
Annealing: order 2, step 64, gamma = 0.00117902
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.14
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.581
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.40726e-08,-5.71528e-08 deg (-1.65556e-05,-5.82114e-06 pix) to CRVAL and CD.
Annealing: order 2, step 65, gamma = 0.00106112
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.41
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.583
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.21901e-08,-5.70807e-08 deg (-1.61619e-05,-6.12485e-06 pix) to CRVAL and CD.
Annealing: order 2, step 66, gamma = 0.000955005
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.66
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.586
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -3.04875e-08,-5.70141e-08 deg (-1.58055e-05,-6.39928e-06 pix) to CRVAL and CD.
Annealing: order 2, step 67, gamma = 0.000859504
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1045.88
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.588
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.89483e-08,-5.69528e-08 deg (-1.54832e-05,-6.64716e-06 pix) to CRVAL and CD.
Annealing: order 2, step 68, gamma = 0.000773554
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.08
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.589
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.75574e-08,-5.68966e-08 deg (-1.51918e-05,-6.87095e-06 pix) to CRVAL and CD.
Annealing: order 2, step 69, gamma = 0.000696199
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.26
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.591
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.63011e-08,-5.68451e-08 deg (-1.49284e-05,-7.07295e-06 pix) to CRVAL and CD.
Annealing: order 2, step 70, gamma = 0.000626579
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.43
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.593
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.51668e-08,-5.6798e-08 deg (-1.46905e-05,-7.25523e-06 pix) to CRVAL and CD.
Annealing: order 2, step 71, gamma = 0.000563921
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.57
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.594
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.41428e-08,-5.6755e-08 deg (-1.44757e-05,-7.41966e-06 pix) to CRVAL and CD.
Annealing: order 2, step 72, gamma = 0.000507529
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.71
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.595
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.32189e-08,-5.67157e-08 deg (-1.42818e-05,-7.56795e-06 pix) to CRVAL and CD.
Annealing: order 2, step 73, gamma = 0.000456776
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.83
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.596
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.23854e-08,-5.668e-08 deg (-1.41068e-05,-7.70166e-06 pix) to CRVAL and CD.
Annealing: order 2, step 74, gamma = 0.000411098
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1046.93
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.597
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.16337e-08,-5.66476e-08 deg (-1.3949e-05,-7.8222e-06 pix) to CRVAL and CD.
Annealing: order 2, step 75, gamma = 0.000369988
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.03
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.598
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.09557e-08,-5.66181e-08 deg (-1.38066e-05,-7.93087e-06 pix) to CRVAL and CD.
Annealing: order 2, step 76, gamma = 0.00033299
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.12
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.599
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -2.03446e-08,-5.65913e-08 deg (-1.36782e-05,-8.02879e-06 pix) to CRVAL and CD.
Annealing: order 2, step 77, gamma = 0.000299691
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.2
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.6
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.97936e-08,-5.65671e-08 deg (-1.35624e-05,-8.11704e-06 pix) to CRVAL and CD.
Annealing: order 2, step 78, gamma = 0.000269722
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.27
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.6
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.92972e-08,-5.65451e-08 deg (-1.34581e-05,-8.19653e-06 pix) to CRVAL and CD.
Annealing: order 2, step 79, gamma = 0.000242749
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.33
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.601
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.88498e-08,-5.65252e-08 deg (-1.3364e-05,-8.26816e-06 pix) to CRVAL and CD.
Annealing: order 2, step 80, gamma = 0.000218475
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.39
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.601
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.84467e-08,-5.65071e-08 deg (-1.32793e-05,-8.33267e-06 pix) to CRVAL and CD.
Annealing: order 2, step 81, gamma = 0.000196627
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.44
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.602
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.80835e-08,-5.64909e-08 deg (-1.32029e-05,-8.39079e-06 pix) to CRVAL and CD.
Annealing: order 2, step 82, gamma = 0.000176964
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.48
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.602
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.77563e-08,-5.64761e-08 deg (-1.31341e-05,-8.44313e-06 pix) to CRVAL and CD.
Annealing: order 2, step 83, gamma = 0.000159268
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.53
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.603
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.74617e-08,-5.64628e-08 deg (-1.30722e-05,-8.49026e-06 pix) to CRVAL and CD.
Annealing: order 2, step 84, gamma = 0.000143341
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.56
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.603
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.71963e-08,-5.64508e-08 deg (-1.30163e-05,-8.5327e-06 pix) to CRVAL and CD.
Annealing: order 2, step 85, gamma = 0.000129007
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.6
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.603
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.69572e-08,-5.644e-08 deg (-1.2966e-05,-8.57092e-06 pix) to CRVAL and CD.
Annealing: order 2, step 86, gamma = 0.000116106
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.63
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.604
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.6742e-08,-5.64302e-08 deg (-1.29208e-05,-8.60534e-06 pix) to CRVAL and CD.
Annealing: order 2, step 87, gamma = 0.000104496
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.66
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.604
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.65482e-08,-5.64213e-08 deg (-1.288e-05,-8.63632e-06 pix) to CRVAL and CD.
Annealing: order 2, step 88, gamma = 9.40461e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.68
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.604
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.63736e-08,-5.64134e-08 deg (-1.28433e-05,-8.66422e-06 pix) to CRVAL and CD.
Annealing: order 2, step 89, gamma = 8.46415e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.7
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.604
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.62164e-08,-5.64062e-08 deg (-1.28102e-05,-8.68934e-06 pix) to CRVAL and CD.
Annealing: order 2, step 90, gamma = 7.61773e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.72
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.6075e-08,-5.63997e-08 deg (-1.27804e-05,-8.71195e-06 pix) to CRVAL and CD.
Annealing: order 2, step 91, gamma = 6.85596e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.74
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.59476e-08,-5.63938e-08 deg (-1.27536e-05,-8.73231e-06 pix) to CRVAL and CD.
Annealing: order 2, step 92, gamma = 6.17037e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.76
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.58329e-08,-5.63886e-08 deg (-1.27295e-05,-8.75063e-06 pix) to CRVAL and CD.
Annealing: order 2, step 93, gamma = 5.55333e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.77
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.57297e-08,-5.63838e-08 deg (-1.27078e-05,-8.76713e-06 pix) to CRVAL and CD.
Annealing: order 2, step 94, gamma = 4.998e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.78
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.56367e-08,-5.63795e-08 deg (-1.26882e-05,-8.78198e-06 pix) to CRVAL and CD.
Annealing: order 2, step 95, gamma = 4.4982e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.8
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.5553e-08,-5.63757e-08 deg (-1.26706e-05,-8.79535e-06 pix) to CRVAL and CD.
Annealing: order 2, step 96, gamma = 4.04838e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.81
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.54777e-08,-5.63722e-08 deg (-1.26547e-05,-8.80738e-06 pix) to CRVAL and CD.
Annealing: order 2, step 97, gamma = 3.64354e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.82
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.54099e-08,-5.63691e-08 deg (-1.26405e-05,-8.81821e-06 pix) to CRVAL and CD.
Annealing: order 2, step 98, gamma = 3.27919e-05
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.82
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.605
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.53489e-08,-5.63663e-08 deg (-1.26276e-05,-8.82796e-06 pix) to CRVAL and CD.
Annealing: order 2, step 99, gamma = 0
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 1047.9
241 matches, 158 distractors, 0 conflicts (at best log-odds); 417 field sources, 301 index sources
241 matches, 176 distractors, 0 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+----+++--+---+--+-++++++++++-++-
Moved quad center to (330.7, 236.2)
tweak2: setting orders 2, 2
Total weight: 238.606
sip_compute-inverse_polynomials: A 2, AP 2
NX,NY 30,30, x range [0.000000, 694.000000], y range [0.000000, 464.000000]
Applying shift of sx,sy = -1.96388e-08,-5.65639e-08 deg (-1.35305e-05,-8.14258e-06 pix) to CRVAL and CD.
301 reference sources within the image.
RoR: 514.823
Test stars in RoR: 417 of 417
Good bins: 117 / 117; effA 322016 of 322016
Ref stars in RoR: 301 of 301
Logodds: 520.395
241 matches, 149 distractors, 9 conflicts (at best log-odds); 417 field sources, 301 index sources
242 matches, 163 distractors, 12 conflicts (all sources)
Hit/miss: ++++++-+-++-+++++-+++-+++-+++++++++++++--+++++++++-++++-++++-++-++-+-c--+++--+---+--+-++++++++++-++-
Tweak2: final WCS:
TAN-SIP Structure:
  crval=(267.366, 20.8774)
  crpix=(596.33, 79.6551)
  CD = (    0.0029106     -0.0024247 )
       (    0.0024286      0.0029111 )
  image size = (694 x 464)
  SIP order: A=2, B=2, AP=2, BP=2
  A =            0           0 -2.3834e-06
                 0  2.2752e-07
       -1.2068e-06
  B =            0           0  5.7938e-07
                 0 -1.2628e-06
       -8.5813e-07
  AP =   1.2512e-05  9.6624e-07  2.3789e-06
        -1.195e-07 -2.2536e-07
        1.2052e-06
  BP =   8.9158e-06 -4.0871e-08  -5.781e-07
       -2.1952e-07  1.2624e-06
        8.5604e-07
  sqrt(det(CD))=13.6429 [arcsec]
Found tag-along columns from field: FLUX BACKGROUND
Field 1: solved with index index-tycho2-07.littleendian.fits.
Field 1: tried 2 quads, matched 3 codes.
Field 1 solved: writing to file /home/q/Downloads/star2/1.solved to indicate this.
Spent 0.150002 s user, 0.046161 s system, 0.196163 s total, 0.197536 s wall time.
Writing 242 rows (of 417 field and 301 index objects) to correspondence file.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 10
enddepth 20
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 20
enddepth 30
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 30
enddepth 40
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 40
enddepth 50
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 50
enddepth 60
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 60
enddepth 70
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 70
enddepth 80
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 80
enddepth 90
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 90
enddepth 100
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 100
enddepth 110
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 110
enddepth 120
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 120
enddepth 130
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 130
enddepth 140
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 140
enddepth 150
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 150
enddepth 160
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 160
enddepth 170
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 170
enddepth 180
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 180
enddepth 190
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
Running solver:
solver run parameters:
indexes:
  /usr/share/astrometry/index-tycho2-14.littleendian.fits
  /usr/share/astrometry/index-tycho2-13.littleendian.fits
  /usr/share/astrometry/index-tycho2-12.littleendian.fits
  /usr/share/astrometry/index-tycho2-11.littleendian.fits
  /usr/share/astrometry/index-tycho2-10.littleendian.fits
  /usr/share/astrometry/index-tycho2-09.littleendian.fits
  /usr/share/astrometry/index-tycho2-08.littleendian.fits
  /usr/share/astrometry/index-tycho2-07.littleendian.fits
fieldfname /home/q/Downloads/star2/1.axy
fields 1 
fieldid 0
matchfname /home/q/Downloads/star2/1.match
solved_out /home/q/Downloads/star2/1.solved
wcs /home/q/Downloads/star2/1.wcs
fieldid_key FIELDID
indexrdlsfname /home/q/Downloads/star2/1.rdls
parity 2
codetol 0.01
startdepth 190
enddepth 200
fieldunits_lower 5.18732
fieldunits_upper 20.2305
verify_pix 1
xcolname X
ycolname Y
maxquads 0
maxmatches 0
cpulimit 5.000000
timelimit 0
total_timelimit 0
total_cpulimit 5.000000
Reading fields file /home/q/Downloads/star2/1.axy...found 1 fields.
cx<=dx constraints: 0
meanx constraints: 1945
RA,Dec constraints: 0
AB scale constraints: 0
Spent 1.60488 seconds on this field.
[ 54164: 2.643] Field: /home/q/Downloads/star2/1.fits
[ 54164: 2.643] Field center: (RA,Dec) = (266.194841, 20.713748) deg.
[ 54164: 2.643] Field center: (RA H:M:S, Dec D:M:S) = (17:44:46.762, +20:42:49.494).
[ 54164: 2.643] Field size: 2.63115 x 1.75823 degrees
[ 54164: 2.643] Field rotation angle: up is -39.8167 degrees E of N
[ 54164: 2.643] Field parity: neg
[ 54164: 2.643] Creating new FITS file "/home/q/Downloads/star2/1.new"...
[ 54164: 2.644] Reading input file FITS headers...
[ 54164: 2.644] Read input header line: "SIMPLE  =                    T / file does conform to FITS standard             "
[ 54164: 2.644] Read input header line: "BITPIX  =                   16 / number of bits per data pixel                  "
[ 54164: 2.644] Read input header line: "NAXIS   =                    2 / number of data axes                            "
[ 54164: 2.644] Read input header line: "NAXIS1  =                  694 / length of data axis 1                          "
[ 54164: 2.644] Read input header line: "NAXIS2  =                  464 / length of data axis 2                          "
[ 54164: 2.644] Read input header line: "EXTEND  =                    T / FITS dataset may contain extensions            "
[ 54164: 2.644] Read input header line: "COMMENT   FITS (Flexible Image Transport System) format is defined in 'Astronomy"
[ 54164: 2.644] Read input header line: "COMMENT   and Astrophysics', volume 376, page 359; bibcode: 2001A&A...376..359H "
[ 54164: 2.644] Read input header line: "BZERO   =   32768.000000000000 / offset data range to that of unsigned short    "
[ 54164: 2.644] Read input header line: "BSCALE  =   1.0000000000000000 / default scaling factor                         "
[ 54164: 2.644] Read input header line: "ROWORDER= 'TOP-DOWN'           / Row Order                                      "
[ 54164: 2.644] Read input header line: "INSTRUME= 'QHY CCD QHY268M-385fff4' / Camera Name                               "
[ 54164: 2.644] Read input header line: "TELESCOP= 'Telescope Simulator' / Telescope name                                "
[ 54164: 2.644] Read input header line: "EXPTIME =         5.000000E+00 / Total Exposure Time (s)                        "
[ 54164: 2.644] Read input header line: "CCD-TEMP=            4.700E+00 / CCD Temperature (Celsius)                      "
[ 54164: 2.644] Read input header line: "PIXSIZE1=         3.760000E+00 / Pixel Size 1 (microns)                         "
[ 54164: 2.644] Read input header line: "PIXSIZE2=         3.760000E+00 / Pixel Size 2 (microns)                         "
[ 54164: 2.644] Read input header line: "XBINNING=                    9 / Binning factor in width                        "
[ 54164: 2.644] Read input header line: "YBINNING=                    9 / Binning factor in height                       "
[ 54164: 2.644] Read input header line: "XPIXSZ  =   33.839999999999996 / X binned pixel size in microns                 "
[ 54164: 2.644] Read input header line: "YPIXSZ  =   33.839999999999996 / Y binned pixel size in microns                 "
[ 54164: 2.644] Read input header line: "FRAME   = 'Light   '           / Frame Type                                     "
[ 54164: 2.644] Read input header line: "IMAGETYP= 'Light Frame'        / Frame Type                                     "
[ 54164: 2.644] Read input header line: "DATE-OBS= '2025-06-26T07:57:00.093' / UTC start date of observation             "
[ 54164: 2.644] Read input header line: "COMMENT Generated by INDI                                                       "
[ 54164: 2.644] Read input header line: "GAIN    =            3.000E+01 / Gain                                           "
[ 54164: 2.644] Read input header line: "OFFSET  =            3.000E+01 / Offset                                         "
[ 54164: 2.644] Read input header line: "READMODE=              0.0E+00 / Read Mode                                      "
[ 54164: 2.644] Read input header line: "INPUTFMT= 'FITS    ' /          Format of file from which image was read        "
[ 54164: 2.644] Read input header line: "SWMODIFY= 'MaxIm DL Version 5.12' /Name of software that modified the image     "
[ 54164: 2.644] Read input header line: "HISTORY  Edit Bin 3x3                                                           "
[ 54164: 2.644] Read input header line: "HISTORY  Edit Bin 3x3                                                           "
[ 54164: 2.644] Read input header line: "HISTORY  Process Stretch                                                        "
[ 54164: 2.645] Read input header line: "CBLACK  =                    0 /Initial display black level in ADUs             "
[ 54164: 2.645] Read input header line: "CWHITE  =                65535 /Initial display white level in ADUs             "
[ 54164: 2.645] Read input header line: "PEDESTAL=                    0 /Correction to add for zero-based ADU            "
[ 54164: 2.645] Read input header line: "SWOWNER = 'Team SND' /          Licensed owner of software                      "
[ 54164: 2.645] Read input header line: "END                                                                             "
[ 54164: 2.645] Regular expression matched: "^END$", key "END".
[ 54164: 2.645] Reading WCS file FITS headers...
[ 54164: 2.645] Regular expression matched: "^SIMPLE$", key "SIMPLE".
[ 54164: 2.645] Regular expression matched: "^BITPIX$", key "BITPIX".
[ 54164: 2.645] Regular expression matched: "^NAXIS$", key "NAXIS".
[ 54164: 2.645] Regular expression matched: "^EXTEND$", key "EXTEND".
[ 54164: 2.645] Regular expression matched: "^END$", key "END".
[ 54164: 2.645] Copying from offset 5760 to offset 650880 (length 645120) of the input file to the output.
[ 54164: 2.648] Deleting temp file /dev/shm/tmp.ppm.f6OKsZ
[ 54164: 2.648] 
