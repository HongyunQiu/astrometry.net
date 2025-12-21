/*
# This file is part of the Astrometry.net suite.
# Licensed under a 3-clause BSD style license - see LICENSE
 */

/* Finds all peaks in the image by cutting a bounding box out around
 each one */

#define GLUE2(a,b) a ## b
#define GLUE(a,b) GLUE2(a, b)

int GLUE(dallpeaks, SUFFIX)(IMGTYPE *image,
							int nx,
    			            int ny,
							int *object,
							float *xcen,
							float *ycen,
							int *npeaks,
							float dpsf,
							float sigma,
							float dlim,
							float saddle,
							int maxper,
							int maxnpeaks,
							float minpeak,
							int maxsize) {

#undef GLUE
#undef GLUE2
	double t_dall_start = timenow();
	double t_sort = 0.0;
	double t_bbox = 0.0;
	double t_cutout = 0.0;
	double t_smooth = 0.0;
	double t_peaks = 0.0;
	double t_maxgauss = 0.0;
	int nobj_timed = 0;
	int nsubpeaks_total = 0;
	int ncentroid5_fail = 0;
	int ncentroid3_fail_edge = 0;
	logverb("QHYCCD | dallpeaks\n");
	int i, j, k, nobj;
	int xcurr, ycurr, imore ;
	float tmpxc, tmpyc, three[9];

	int *indx = NULL;
	float *oimage = NULL;
	float *simage = NULL;
	int npix = 0;
	int *xc = NULL;
	int *yc = NULL;

	/* Group the connected pixels together.  We do this by computing a
	 permutation index array that would sort the "object" array.
	 (Recall that the "object" array labels the connected components.)
	 All the unlabelled pixels (object == -1) are listed first, then
	 the indices of all the pixels labeled with (object == 0), (object
	 == 1), etc.  The pixel coordinate is (x,y) = (indx[i] % nx,
	 indx[i] / nx).
	 */
	{
		double t0 = timenow();
		indx = permuted_sort(object, sizeof(int), compare_ints_asc, NULL, nx*ny);
		t_sort += timenow() - t0;
	}

	// skip over the unlabelled pixels (object == -1)
	for (k=0; k<(nx*ny) && object[indx[k]] == -1; k++);

	nobj = 0;
	*npeaks = 0;
	xc = malloc(sizeof(int) * maxper);
	yc = malloc(sizeof(int) * maxper);
	while (k < (nx*ny)) {
		int current;
		int m;
		int di, dj;
		int oi, oj;
		int xmax, ymax, xmin, ymin, onx, ony, nc;
		double t_obj_start = timenow();
		// Low-noise logging threshold (seconds) for expensive per-object stages.
		const double log_stage_thresh = 0.050;

		// the object number we're looking at.
		current = object[indx[k]];

		// find the object limits in pixel space.
		{
			double t0 = timenow();
		xmax = -1;
		xmin = nx + 1;
		ymax = -1;
		ymin = ny + 1;
		for (m=k; m<(nx*ny) && object[indx[m]] == current; m++) {
			xcurr = indx[m] % nx;
			ycurr = indx[m] / nx;
			xmin = MIN(xmin, xcurr);
			xmax = MAX(xmax, xcurr);
			ymin = MIN(ymin, ycurr);
			ymax = MAX(ymax, ycurr);
		}
			t_bbox += timenow() - t0;
		}
		// we've also computed where this object ends...
		// "k" is not used in the rest of this loop, so set it to its next value now.
		k = m;

		// skip if it is smaller than 3x3 or bigger than maxsize.
		onx = xmax - xmin + 1;
		ony = ymax - ymin + 1;
		if (onx < 3 || ony < 3) {
			logverb("Skipping object %i: too small, %ix%i (x %i:%i, y %i:%i)\n",
					current, onx, ony, xmin,xmax, ymin,ymax);
			continue;
		}
		if (ony > maxsize || onx > maxsize) {
			logverb("Skipping object %i: too big, %ix%i (x %i:%i, y %i:%i)\n",
					current, onx, ony, xmin,xmax, ymin,ymax);
			continue;
		}
		if (*npeaks > maxnpeaks) {
			logverb("Skipping all further objects: already found the maximum number (%i)\n", maxnpeaks);
			break;
		}

		// enlarge cutout arrays, if necessary.
		if (onx*ony > npix) {
			free(oimage);
			free(simage);
			npix = onx * ony;
			oimage = malloc(npix * sizeof(float));
			simage = malloc(npix * sizeof(float));
		}

		// make object cutout
		{
			double t0 = timenow();
			for (oj=0; oj<ony; oj++)
				for (oi=0; oi<onx; oi++) {
					oimage[oi + oj*onx] = 0.;
					i = oi + xmin;
					j = oj + ymin;
					// copy only pixels that are part of the current object
					if (object[i + j*nx] == current)
						oimage[oi + oj*onx] = image[i + j*nx];
				}
			t_cutout += timenow() - t0;
		}
		// find peaks in cutout
		{
			double t0 = timenow();
			dsmooth2(oimage, onx, ony, dpsf, simage);
			{
				double dt = timenow() - t0;
				t_smooth += dt;
				if (dt > log_stage_thresh) {
					logverb("dallpeaks: object %i dsmooth2(%ix%i) took %.3f s\n", current, onx, ony, dt);
				}
			}
		}
		{
			double t0 = timenow();
			dpeaks(simage, onx, ony, &nc, xc, yc,
				   sigma, dlim, saddle, maxper, 0, 1, minpeak);
			{
				double dt = timenow() - t0;
				t_peaks += dt;
				if (dt > log_stage_thresh) {
					logverb("dallpeaks: object %i dpeaks(%ix%i) -> nc=%i took %.3f s\n", current, onx, ony, nc, dt);
				}
			}
		}
		imore = 0;
		for (i=0; i<nc; i++) {
			nsubpeaks_total++;
			if (xc[i] <= 0 || xc[i] >= onx-1 ||
				yc[i] <= 0 || yc[i] >= ony-1) {
				logverb("Skipping subpeak %i: position %i,%i out of bounds 1:%i, 1:%i\n",
						i, xc[i], yc[i], onx-1, ony-1);
				continue;
			}
			if (imore + *npeaks >= maxnpeaks) {
				logverb("Skipping all further subpeaks: exceeded max number (%i)\n", maxnpeaks);
				break;
			}

			/* install default centroid to begin */
			xcen[imore + (*npeaks)] = xc[i] + xmin;
			ycen[imore + (*npeaks)] = yc[i] + ymin;
			assert(isfinite(xcen[imore + *npeaks]));
			assert(isfinite(ycen[imore + *npeaks]));

			// cut out 3x3 box
			for (di=-1; di<=1; di++)
				for (dj=-1; dj<=1; dj++)
					three[(di+1) + (dj+1)*3] = simage[xc[i]+di + (yc[i]+dj)*onx];
			// try to find centroid in the 3x3 cutout
			if (dcen3x3(three, &tmpxc, &tmpyc)) {
				assert(isfinite(tmpxc));
				assert(isfinite(tmpyc));
				xcen[imore + (*npeaks)] = (tmpxc-1.0) + xc[i] + xmin;
				ycen[imore + (*npeaks)] = (tmpyc-1.0) + yc[i] + ymin;
				assert(isfinite(xcen[imore + *npeaks]));
				assert(isfinite(ycen[imore + *npeaks]));

			} else if (xc[i] > 1 && xc[i] < onx - 2 &&
					   yc[i] > 1 && yc[i] < ony - 2 &&
					   imore < (maxnpeaks - (*npeaks))) {
				debug("Peak %i subpeak %i at (%i,%i): searching for centroid in 3x3 box failed; trying 5x5 box...\n", current, i, xmin+xc[i], ymin+yc[i]);
				debug("3x3 box:\n  %g,%g,%g,%g,%g,%g,%g,%g,%g\n", three[0],three[1],three[2],three[3],three[4],three[5],three[6],three[7],three[8]);
				/* try to get centroid in the 5 x 5 box */
				for (di=-1; di<=1; di++)
					for (dj=-1; dj<=1; dj++)
						three[(di+1) + (dj+1)*3] = simage[xc[i]+(2*di) + (yc[i] + (2*dj)) * onx];
				if (dcen3x3(three, &tmpxc, &tmpyc)) {
					xcen[imore + (*npeaks)] = 2.0*(tmpxc-1.0) + xc[i] + xmin;
					ycen[imore + (*npeaks)] = 2.0*(tmpyc-1.0) + yc[i] + ymin;
					assert(isfinite(xcen[imore + *npeaks]));
					assert(isfinite(ycen[imore + *npeaks]));
				} else {
					double t0, dt;
					// don't add this peak.
					ncentroid5_fail++;
					debug("Failed to find (5x5) centroid of peak %i, subpeak %i at (%i,%i)\n", current, i, xmin+xc[i], ymin+yc[i]);
					debug("5x5 box:\n  %g,%g,%g,%g,%g,%g,%g,%g,%g\n", three[0],three[1],three[2],three[3],three[4],three[5],three[6],three[7],three[8]);

					// max_gaussian can be expensive; time it.
					t0 = timenow();
					max_gaussian(oimage, onx, ony, dpsf, xc[i], yc[i], &tmpxc, &tmpyc);
					dt = timenow() - t0;
					t_maxgauss += dt;
					debug("max_gaussian: %g,%g\n", tmpxc, tmpyc);
					xcen[imore + (*npeaks)] = tmpxc + xmin;
					ycen[imore + (*npeaks)] = tmpyc + ymin;
					//continue;
				}
			} else {
				ncentroid3_fail_edge++;
				debug("Failed to find (3x3) centroid of peak %i, subpeak %i at (%i,%i), and too close to edge for 5x5\n",
						current, i, xmin+xc[i], ymin+yc[i]);
			}
			imore++;
		}
		(*npeaks) += imore;
		nobj++;
		nobj_timed++;
	}

	logverb("dallpeaks: timing summary: total %.3f s; sort %.3f s; bbox %.3f s; cutout %.3f s; smooth %.3f s; peaks %.3f s; max_gaussian %.3f s; objects %i; subpeaks %i; centroid5_fail %i; centroid3_fail_edge %i\n",
			timenow() - t_dall_start, t_sort, t_bbox, t_cutout, t_smooth, t_peaks, t_maxgauss,
			nobj_timed, nsubpeaks_total, ncentroid5_fail, ncentroid3_fail_edge);
	
	FREEVEC(indx);
	FREEVEC(oimage);
	FREEVEC(simage);
	FREEVEC(xc);
	FREEVEC(yc);

	return 1;

} /* end dallpeaks */
