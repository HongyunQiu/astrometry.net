solve_field.c

int main(){

    while(1){
        if (fromstdin) {
            char fnbuf[1024];
            if (!fgets(fnbuf, sizeof(fnbuf), stdin)) {
                if (ferror(stdin))
                    SYSERROR("Failed to read a filename from stdin");
                break;
            }
            len = strlen(fnbuf);
            if (fnbuf[len-1] == '\n')
                fnbuf[len-1] = '\0';
            infile = fnbuf;
            logmsg("Reading input file \"%s\"...\n", infile);
        } else {
            if (f == argc)
                break;
            infile = args[f];
            f++;
            logmsg("Reading input file %i of %i: \"%s\"...\n",
                    f - optind, argc - optind, infile);
        }
        ......
        logverb("Base: \"%s\", basefile \"%s\", basedir \"%s\", suffix \"%s\"\n", base, basefile, basedir, suffix);
        ......
        logverb("QHYCCD LOG:  go to augment-xylist ++++++++++++\n");

        if (augment_xylist(axy, me)) {
            ERROR("augment-xylist failed");
            exit(-1);
        }

        augment_xylist(axy, me){    // augment-xylist.c --> augment_xylist 
            ......
            if (axy->assume_fits_image) {
                axy->isfits = TRUE;
                if (!axy->pnmfn) {
                    qfits_header* hdr;
                    want_pnm = FALSE;
                    // We need to get image W,H from the FITS header.
                    logverb("Reading FITS image \"%s\" to find image size\n", axy->imagefn);
                    hdr = anqfits_get_header2(axy->imagefn, axy->extension);
                    axy->W = qfits_header_getint(hdr, "NAXIS1", -1);
                    axy->H = qfits_header_getint(hdr, "NAXIS2", -1);
                    qfits_header_destroy(hdr);
                    if (axy->W == -1 || axy->H == -1) {
                        ERROR("Failed to find size of FITS image \"%s\": got NAXIS1 = %i, NAXIS2 = %i\n",
                            axy->imagefn, axy->W, axy->H);
                        return -1;
                    }
                    logverb("  got FITS image size %i x %i\n", axy->W, axy->H);
                }
            }
            ......
            if (axy->isfits) {
                ......
                if (axy->try_verify) {
                    char* errstr;
                    sip_t sip;
                    anbool ok;
                    // Try to read WCS header from FITS image; if successful,
                    // add it to the list of WCS headers to verify.
                    logverb("Looking for a WCS header in FITS input image %s ext %i\n", fitsimgfn, axy->fitsimgext);

                    // FIXME - Right now we just try to read SIP/TAN -
                    // obviously this should be more flexible and robust.
                    errors_start_logging_to_string();
                    memset(&sip, 0, sizeof(sip_t));
                    ok = (sip_read_header_file_ext(fitsimgfn, axy->fitsimgext, &sip) != NULL);
                    errstr = errors_stop_logging_to_string(": ");
                    if (ok) {
                        logmsg("Found an existing WCS header, will try to verify it.\n");
                        sl_append(axy->verifywcs, fitsimgfn);
                        il_append(axy->verifywcs_ext, axy->fitsimgext);
                    } else {
                        logverb("Failed to read a SIP or TAN header from FITS image.\n");
                        logverb("  (reason: %s)\n", errstr);
                    }
                    free(errstr);
                }
            }
            ......
            logmsg("Extracting sources...\n");
            ......
            logverb("Running image2xy: input=%s, output=%s, ext=%i\n", fitsimgfn, xylsfn, axy->fitsimgext);
            ......
            logverb("QHYCCD LOG:  go to image2xy_files ++++++++++\n");
            if (image2xy_files(fitsimgfn, xylsfn, TRUE, axy->downsample, 3,
                                axy->fitsimgext, 0, &sxyparams)) {
                ERROR("Source extraction failed");
                exit(-1);
            }

            image2xy_files(fitsimgfn, xylsfn, TRUE, axy->downsample, 3, axy->fitsimgext, 0, &sxyparams){    // image2xy-files.c --> image2xy_files 
                ......
                logverb("nhdus=%d\n", nhdus);
                ......
                for (kk=1; kk <= nhdus; kk++){
                    logverb("Got naxis=%d, na1=%lu, na2=%lu\n", naxis, naxisn[0], naxisn[1]);
                    ......
                    logverb("QHYCCD LOG:  go to image2xy_run ++++++++++\n");
                    image2xy_run(params, downsample, downsample_as_required);
                }


                image2xy_run(params, downsample, downsample_as_required){      //image2xy.c --> image2xy_run
                    ......
                    do{
                        logverb("QHYCCD LOG:  go to simplexy_run ++++++++++\n");
                        simplexy_run(s);
                        simplexy_run(s){        //  simplexy.c --> simplexy_run
                            ......
                            logverb("simplexy: nx=%d, ny=%d\n", nx, ny);
                            logverb("simplexy: dpsf=%f, plim=%f, dlim=%f, saddle=%f\n",
                                    s->dpsf, s->plim, s->dlim, s->saddle);
                            logverb("simplexy: maxper=%d, maxnpeaks=%d, maxsize=%d, halfbox=%d\n",
                                    s->maxper, s->maxnpeaks, s->maxsize, s->halfbox);
                            ......
                            logverb("simplexy: median smoothing...\n");
                            ......
                            if (s->sigma == 0.0) {
                                logverb("simplexy: measuring image noise (sigma)...\n");
                                if (s->image_u8){
                                    logverb("QHYCCD LOG:  go to dsigma_u8 ++++++++++\n");
                                    dsigma_u8(s->image_u8, nx, ny, 5, 0, &(s->sigma))   // dsigma.inc
                                    dsigma_u8(s->image_u8, nx, ny, 5, 0, &(s->sigma)){
                                        ......
                                        logverb("Sampling sigma at %i points\n", ndiff);
                                        ......
                                        logverb("Nsigma=%g, s=%g\n", Nsigma, s);
                                    }

                                }else{
                                    logverb("QHYCCD LOG:  go to dsigma ++++++++++\n");
                                    dsigma(s->image, nx, ny, 5, 0, &(s->sigma));
                                }
                                logverb("simplexy: found sigma=%g.\n", s->sigma);
                                ......
                            }else {
                                logverb("simplexy: assuming sigma=%g.\n", s->sigma);
                            }
                            logverb("simplexy: finding objects...\n");
                            ......
                            logverb("simplexy: found %i blobs\n", nblobs);
                            ......
                            logverb("simplexy: finding peaks...\n");
                            if (bgsub){
                                logverb("QHYCCD LOG:  go to dallpeaks ++++++++++\n");
                                dallpeaks(bgsub, nx, ny, ccimg, s->x, s->y, &(s->npeaks), s->dpsf,
                                        s->sigma, s->dlim, s->saddle, s->maxper, s->maxnpeaks, s->sigma, s->maxsize);
                            }else{
                                logverb("QHYCCD LOG:  go to dallpeaks_i16 ++++++++++\n");
                                dallpeaks_i16(bgsub_i16, nx, ny, ccimg, s->x, s->y, &(s->npeaks), s->dpsf,
                                        s->sigma, s->dlim, s->saddle, s->maxper, s->maxnpeaks, s->sigma, s->maxsize);   //  dallpeaks.inc
                                dallpeaks_i16(bgsub_i16, nx, ny, ccimg, s->x, s->y, &(s->npeaks), s->dpsf,
                                    s->sigma, s->dlim, s->saddle, s->maxper, s->maxnpeaks, s->sigma, s->maxsize){
                                    for (i=0; i<nc; i++) {
                                        ......
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
                                                // don't add this peak.
                                                logverb("Failed to find (5x5) centroid of peak %i, subpeak %i at (%i,%i)\n", current, i, xmin+xc[i], ymin+yc[i]);
                                                debug("5x5 box:\n  %g,%g,%g,%g,%g,%g,%g,%g,%g\n", three[0],three[1],three[2],three[3],three[4],three[5],three[6],three[7],three[8]);

                                                max_gaussian(oimage, onx, ony, dpsf, xc[i], yc[i], &tmpxc, &tmpyc);
                                                debug("max_gaussian: %g,%g\n", tmpxc, tmpyc);
                                                xcen[imore + (*npeaks)] = tmpxc + xmin;
                                                ycen[imore + (*npeaks)] = tmpyc + ymin;
                                                //continue;
                                            }
                                        } else {
                                            logverb("Failed to find (3x3) centroid of peak %i, subpeak %i at (%i,%i), and too close to edge for 5x5\n",
                                                    current, i, xmin+xc[i], ymin+yc[i]);
                                        }
                                    }
                                }
                            }
                            logmsg("simplexy: found %i sources.\n", s->npeaks);          
                        }

                        tryagain = FALSE;
                        if (s->npeaks == 0 &&
                            downsample_as_required) {
                            logmsg("Downsampling by 2...\n");
                            if (s->image_u8) {
                                s->image = upconvert(s->image_u8, s->nx, s->ny);
                                if (!s->image)
                                    goto bailout;
                                free_fimage = TRUE;
                                s->image_u8 = NULL;
                            }
                            rebin(&s->image, s->nx, s->ny, 2, &newW, &newH);
                            s->nx = newW;
                            s->ny = newH;
                            S *= 2;
                            tryagain = TRUE;
                            downsample_as_required--;
                        }
                    }while (tryagain);

                }   
            }       

            if (axy->resort) {
                char* err;
                int rtn;
                logverb("Sorting file \"%s\" to \"%s\" using columns flux (%s) and background (%s), %sscending\n",
                        xylsfn, sortedxylsfn, axy->sortcol, axy->bgcol, axy->sort_ascending?"a":"de");
                errors_start_logging_to_string();
                rtn = resort_xylist(xylsfn, sortedxylsfn, axy->sortcol, axy->bgcol, axy->sort_ascending);
                err = errors_stop_logging_to_string(": ");
                if (rtn) {
                    logmsg("Sorting brightness using %s and BACKGROUND columns failed; falling back to %s.\n",
                            axy->sortcol, axy->sortcol);
                    logverb("Reason: %s\n", err);
                    do_tabsort = TRUE;
                }
                free(err);
            } else
                do_tabsort = TRUE;

            if ((axy->scalelo > 0.0) || (axy->scalehi > 0.0)) {
                double appu, appl;
                switch (axy->scaleunit) {
                case SCALE_UNITS_DEG_WIDTH:
                    logverb("Scale range: %g to %g degrees wide\n", axy->scalelo, axy->scalehi);
                    appl = deg2arcsec(axy->scalelo) / (double)axy->W;
                    appu = deg2arcsec(axy->scalehi) / (double)axy->W;
                    logverb("Image width %i pixels; arcsec per pixel range %g %g\n", axy->W, appl, appu);
                    break;
                ......
                dl_append(scales, appl);
                dl_append(scales, appu);
                }
            }
            ......
            logverb("Writing headers to file %s\n", axy->axyfn);
            ......
            logverb("Copying data block of file %s to output %s.\n", xylsfn, axy->axyfn);
            ......
            

            cleanup:
            if (!axy->no_delete_temp) {
                for (i=0; i<sl_size(tempfiles); i++) {
                    char* fn = sl_get(tempfiles, i);
                    logverb("QHYCCD   -----Deleting temp file %s\n", fn);
                    if (unlink(fn)) {
                        SYSERROR("Failed to delete temp file \"%s\"", fn);
                    }
                }
            }

        }   

        if (!engine_batch) {
            run_engine(engineargs);

            run_engine(engineargs){
                logmsg("Solving...\n");
                logverb("Running:\n  %s\n", cmd);
                logverb("QHYCCD LOG:  go to engine-main ++++++++++\n");
                if (run_command_get_outputs(cmd, NULL, NULL)) {         //cmd : /usr/local/astrometry/bin/astrometry-engine --verbose ./file_2000-01-01_00-38-57_6.axy
                    ERROR("engine failed.  Command that failed was:\n  %s", cmd);
                    exit(-1);
                }

                run_command_get_outputs(cmd, NULL, NULL){   //  engine-main.c --> int main
                    int main(int argc, char** args) {
                        ......
                        if (!configfn) {
                            ......
                            for (i=0; i<sl_size(trycf); i++) {
                                char* cf = sl_get(trycf, i);
                                if (file_exists(cf)) {
                                    configfn = strdup(cf);
                                    logverb("Using config file \"%s\"\n", cf);
                                    break;
                                } else {
                                    logverb("Config file \"%s\" doesn't exist.\n", cf);
                                }
                            }
                        }
                        ......
                        if (!streq(configfn, "none")) {
                            logverb("QHYCCD LOG:  go to engine ++++++++++\n");
                            if (engine_parse_config_file(engine, configfn)) {   //  engine.c --> engine_parse_config_file
                                logerr("Failed to parse (or encountered an error while interpreting) config file \"%s\"\n", configfn);
                                exit( -1);
                            }
                            engine_parse_config_file(engine, configfn){
                                ......
                                rtn = engine_parse_config_file_stream(engine, fconf);

                                engine_parse_config_file_stream(engine, fconf){
                                    ......
                                    if (auto_index) {
                                        engine_autoindex_search_paths(engine);

                                        engine_autoindex_search_paths(engine){
                                            for (i=0; i<sl_size(engine->index_paths); i++) {
                                                ......
                                                logverb("Auto-indexing directory \"%s\" ...\n", path);
                                                tryinds = sl_new(16);
                                                while (1) {
                                                    ......
                                                    if (path_is_dir(fullpath)) {
                                                        logverb("Skipping directory %s\n", fullpath);
                                                        free(fullpath);
                                                        continue;
                                                    }

                                                    logverb("Checking file \"%s\"\n", fullpath);
                                                    errors_start_logging_to_string();
                                                    ok = index_is_file_index(fullpath);     // index.c --> index_is_file_index

                                                    index_is_file_index(fullpath){
                                                        ......
                                                        indexfn = get_filename(filename);
                                                        get_filename(filename){
                                                            ......
                                                            if (file_readable(indexname)) {
                                                                logverb("Index name \"%s\" is readable, using as index filename\n", indexname);
                                                                return strdup(indexname);
                                                            }
                                                            ......
                                                        }
                                                        ......
                                                    }
                                                    ......
                                                }
                                                closedir(dir);

                                                // add them in reverse order... (why?)
                                                for (j=sl_size(tryinds)-1; j>=0; j--) {
                                                    char* path = sl_get(tryinds, j);
                                                    logverb("Trying to add index \"%s\".\n", path);
                                                    if (engine_add_index(engine, path))
                                                        logmsg("Failed to add index \"%s\".\n", path);
                                                    
                                                    engine_add_index(engine, path){
                                                        int k;
                                                        index_t* ind = NULL;
                                                        char* quadpath = index_get_quad_filename(path);     // index.c --> index_get_quad_filename

                                                        index_get_quad_filename(path){
                                                            if (!index_is_file_index(indexname))
                                                                return NULL;

                                                            index_is_file_index(indexname){
                                                                char* indexfn;
                                                                anbool rtn = TRUE;
                                                                indexfn = get_filename(filename);
                                                                
                                                                get_filename(filename){
                                                                    char* fits;
                                                                    if (file_readable(indexname)) {
                                                                        logverb("Index name \"%s\" is readable, using as index filename\n", indexname);
                                                                        return strdup(indexname);
                                                                    }
                                                                    asprintf_safe(&fits, "%s.fits", indexname);
                                                                    if (file_readable(fits)) {
                                                                        // assume single-file index.
                                                                        logverb("Index name \"%s\" with .fits suffix, \"%s\", is readable, using as index filename.\n", indexname, fits);
                                                                        return fits;
                                                                    }
                                                                    free(fits);
                                                                    return NULL;
                                                                }
                                                            }
                                                            return get_filename(indexname);
                                                        }

                                                        char* base = basename_safe(quadpath);
                                                        double t0;
                                                        free(quadpath);
                                                        ......
                                                        ind = index_load(path, engine->inparallel ? 0 : INDEX_ONLY_LOAD_METADATA, NULL);    // index.c --> index_load

                                                        index_load(path, engine->inparallel ? 0 : INDEX_ONLY_LOAD_METADATA, NULL){
                                                            if (flags & INDEX_ONLY_LOAD_METADATA)
                                                                logverb("QHYCCD Loading metadata for %s...\n", indexname);
                                                            ......
                                                            dest->indexfn = get_filename(indexname);

                                                            get_filename(indexname){
                                                                    char* fits;
                                                                    if (file_readable(indexname)) {
                                                                        logverb("Index name \"%s\" is readable, using as index filename\n", indexname);
                                                                        return strdup(indexname);
                                                                    }
                                                                    asprintf_safe(&fits, "%s.fits", indexname);
                                                                    if (file_readable(fits)) {
                                                                        // assume single-file index.
                                                                        logverb("Index name \"%s\" with .fits suffix, \"%s\", is readable, using as index filename.\n", indexname, fits);
                                                                        return fits;
                                                                    }
                                                                    free(fits);
                                                                    return NULL;
                                                            }
                                                            ......
                                                            logverb("Index scale: [%g, %g] arcmin, [%g, %g] arcsec\n",
                                                                    dest->index_scale_lower / 60.0, dest->index_scale_upper / 60.0,
                                                                    dest->index_scale_lower, dest->index_scale_upper);
                                                            logverb("Index has %i quads and %i stars\n", dest->nquads, dest->nstars);

                                                        }
                                                    }
                                                }
                                                sl_free2(tryinds);
                                            }
                                        }
                                    }
                                    ......

                                }
                                ......
                            }
                        }
                        ......
                        while(1){
                            ......
                            logmsg("Reading file \"%s\"...\n", jobfn);
                            job = engine_read_job_file(engine, jobfn);  //  engine.c --> engine_read_job_file

                            engine_read_job_file(engine, jobfn){
                                ......
                                if (!parse_job_from_qfits_header(hdr, job)) {
                                    job_free(job);
                                    qfits_header_destroy(hdr);
                                    return NULL;
                                }
                                parse_job_from_qfits_header(hdr, job){
                                    ......
                                    logverb("Set odds ratio to solve to %g (log = %g)\n", exp(bp->logratio_tosolve), bp->logratio_tosolve);
                                    ......
                                }
                                ......
                                // The job can only decrease the CPU limit.
                                if ((bp->cpulimit == 0.0) || bp->cpulimit > engine->cpulimit) {
                                    logverb("Decreasing CPU time limit to the engine's limit of %g seconds\n",
                                            engine->cpulimit);
                                    bp->cpulimit = engine->cpulimit;
                                }
                                ......

                            }
                            ......
                            if (engine_run_job(engine, job))    //  engine.c --> engine_run_job
                                logerr("Failed to run_job()\n");
                            
                            engine_run_job(engine, job){
                                ......
                                for (i=0; i<il_size(job->depths)/2; i++){
                                    ......
                                    for (j=0; j<dl_size(job->scales) / 2; j++){
                                        ......
                                        logverb("Running solver:\n");
                                        onefield_log_run_parameters(bp);    // onefield.c   --> onefield_log_run_parameters

                                        onefield_log_run_parameters(bp){
                                            solver_t* sp = &(bp->solver);
                                            int i, N;

                                            logverb("solver run parameters:\n");
                                            logverb("indexes:\n");
                                            N = n_indexes(bp);
                                            for (i=0; i<N; i++)
                                                logverb("  %s\n", get_index_name(bp, i));
                                            if (bp->fieldfname)
                                                logverb("fieldfname %s\n", bp->fieldfname);
                                            logverb("fields ");
                                            for (i = 0; i < il_size(bp->fieldlist); i++)
                                                logverb("%i ", il_get(bp->fieldlist, i));
                                            logverb("\n");
                                            for (i = 0; i < sl_size(bp->verify_wcsfiles); i++)
                                                logverb("verify %s\n", sl_get(bp->verify_wcsfiles, i));
                                            logverb("fieldid %i\n", bp->fieldid);
                                            if (bp->matchfname)
                                                logverb("matchfname %s\n", bp->matchfname);
                                            if (bp->solved_in)
                                                logverb("solved_in %s\n", bp->solved_in);
                                            if (bp->solved_out)
                                                logverb("solved_out %s\n", bp->solved_out);
                                            if (bp->cancelfname)
                                                logverb("cancel %s\n", bp->cancelfname);
                                            if (bp->wcs_template)
                                                logverb("wcs %s\n", bp->wcs_template);
                                            if (bp->fieldid_key)
                                                logverb("fieldid_key %s\n", bp->fieldid_key);
                                            if (bp->indexrdlsfname)
                                                logverb("indexrdlsfname %s\n", bp->indexrdlsfname);
                                            logverb("parity %i\n", sp->parity);
                                            logverb("codetol %g\n", sp->codetol);
                                            logverb("startdepth %i\n", sp->startobj);
                                            logverb("enddepth %i\n", sp->endobj);
                                            logverb("fieldunits_lower %g\n", sp->funits_lower);
                                            logverb("fieldunits_upper %g\n", sp->funits_upper);
                                            logverb("verify_pix %g\n", sp->verify_pix);
                                            if (bp->xcolname)
                                                logverb("xcolname %s\n", bp->xcolname);
                                            if (bp->ycolname)
                                                logverb("ycolname %s\n", bp->ycolname);
                                            logverb("maxquads %i\n", sp->maxquads);
                                            logverb("maxmatches %i\n", sp->maxmatches);
                                            logverb("cpulimit %f\n", bp->cpulimit);
                                            logverb("timelimit %i\n", bp->timelimit);
                                            logverb("total_timelimit %g\n", bp->total_timelimit);
                                            logverb("total_cpulimit %f\n", bp->total_cpulimit);
                                        }

                                        onefield_run(bp);   //onefield.c --> onefield_run(bp)

                                        onefield_run(bp){
                                            ......
                                            // Read .xyls file...
                                            logverb("Reading fields file %s...\n", bp->fieldfname);
                                            xylist_set_xname(bp->xyls, bp->xcolname);
                                            xylist_set_yname(bp->xyls, bp->ycolname);
                                            xylist_set_include_flux(bp->xyls, FALSE);
                                            xylist_set_include_background(bp->xyls, FALSE);
                                            logverb("found %u fields.\n", xylist_n_fields(bp->xyls));
                                            ......

                                            if (bp->single_field_solved)
                                                goto cleanup;           //for循环的最后一次跳转到了clean up
                                            
                                            
                                            // Start solving...
                                            if (bp->indexes_inparallel) {
                                                ......
                                            }else{
                                                for(I=0; I<Nindexes; I++){
                                                    ......
                                                    // Load the index...
                                                    index = get_index(bp, I);

                                                    get_index(bp, I){
                                                        if (i < sl_size(bp->indexnames)) {
                                                        char* fn = sl_get(bp->indexnames, i);
                                                        index_t* ind = index_load(fn, bp->index_options, NULL); // index.c --> index_load

                                                        index_load(fn, bp->index_options, NULL){
                                                            ......
                                                            dest->indexfn = get_filename(indexname);
                                                            get_filename(indexname){
                                                                char* fits;
                                                                if (file_readable(indexname)) {
                                                                    logverb("Index name \"%s\" is readable, using as index filename\n", indexname);
                                                                    return strdup(indexname);
                                                                }
                                                                asprintf_safe(&fits, "%s.fits", indexname);
                                                                if (file_readable(fits)) {
                                                                    // assume single-file index.
                                                                    logverb("Index name \"%s\" with .fits suffix, \"%s\", is readable, using as index filename.\n", indexname, fits);
                                                                    return fits;
                                                                }
                                                                free(fits);
                                                                return NULL;
                                                            }
                                                            ......
                                                            logverb("Index scale: [%g, %g] arcmin, [%g, %g] arcsec\n",
                                                                dest->index_scale_lower / 60.0, dest->index_scale_upper / 60.0,
                                                                dest->index_scale_lower, dest->index_scale_upper);
                                                            logverb("Index has %i quads and %i stars\n", dest->nquads, dest->nstars);
                                                            ......
                                                        }
                                                        if (!ind) {
                                                            ERROR("Failed to load index %s", fn);
                                                            exit( -1);
                                                        }
                                                        return ind;
                                                        }
                                                        i -= sl_size(bp->indexnames);
                                                        return pl_get(bp->indexes, i);
                                                    }
                                                    solver_add_index(sp, index);
                                                    logverb("Trying index %s...\n", index->indexname);
                                                    // Record current CPU usage.
                                                    bp->cpu_start = get_cpu_usage();
                                                    // Record current wall-clock time.
                                                    bp->time_start = time(NULL);

                                                    // Do it!
                                                    solve_fields(bp, NULL);
                                                    
                                                    solve_fields(bp, NULL){
                                                        ......
                                                        for (fi = 0; fi < il_size(bp->fieldlist); fi++){
                                                            ......
                                                            if (verify_wcs) {
                                                                //MatchObj mo;
                                                                logmsg("Verifying WCS of field %i.\n", fieldnum);
                                                                solver_verify_sip_wcs(sp, verify_wcs); //, &mo);
                                                                logmsg(" --> log-odds %g\n", sp->best_logodds);

                                                            } else {
                                                                logverb("Solving field %i.\n", fieldnum);
                                                                sp->distance_from_quad_bonus = TRUE;
                                                                solver_log_params(sp);  // solver.c --> solver_log_params

                                                                solver_log_params(sp){
                                                                    int i;
                                                                    logverb("Solver:\n");
                                                                    logverb("  Arcsec per pix range: %g, %g\n", sp->funits_lower, sp->funits_upper);
                                                                    logverb("  Image size: %g x %g\n", solver_field_width(sp), solver_field_height(sp));
                                                                    logverb("  Quad size range: %g, %g\n", sp->quadsize_min, sp->quadsize_max);
                                                                    logverb("  Objs: %i, %i\n", sp->startobj, sp->endobj);
                                                                    logverb("  Parity: %i, %s\n", sp->parity, sp->parity == PARITY_NORMAL ? "normal" : (sp->parity == PARITY_FLIP ? "flip" : "both"));
                                                                    if (sp->use_radec) {
                                                                        double ra,dec,rad;
                                                                        xyzarr2radecdeg(sp->centerxyz, &ra, &dec);
                                                                        rad = distsq2deg(sp->r2);
                                                                        logverb("  Use_radec? yes, (%g, %g), radius %g deg\n", ra, dec, rad);
                                                                    } else {
                                                                        logverb("  Use_radec? no\n");
                                                                    }
                                                                    logverb("  Pixel xscale: %g\n", sp->pixel_xscale);
                                                                    logverb("  Verify_pix: %g\n", sp->verify_pix);
                                                                    logverb("  Code tol: %g\n", sp->codetol);
                                                                    logverb("  Dist from quad bonus: %s\n", sp->distance_from_quad_bonus ? "yes" : "no");
                                                                    logverb("  Distractor ratio: %g\n", sp->distractor_ratio);
                                                                    logverb("  Log tune-up threshold: %g\n", sp->logratio_totune);
                                                                    logverb("  Log bail threshold: %g\n", sp->logratio_bail_threshold);
                                                                    logverb("  Log stoplooking threshold: %g\n", sp->logratio_stoplooking);
                                                                    logverb("  Maxquads %i\n", sp->maxquads);
                                                                    logverb("  Maxmatches %i\n", sp->maxmatches);
                                                                    logverb("  Set CRPIX? %s", sp->set_crpix ? "yes" : "no\n");
                                                                    if (sp->set_crpix) {
                                                                        if (sp->set_crpix_center)
                                                                            logverb(", center\n");
                                                                        else
                                                                            logverb(", %g, %g\n", sp->crpix[0], sp->crpix[1]);
                                                                    }
                                                                    logverb("  Tweak? %s\n", sp->do_tweak ? "yes" : "no");
                                                                    if (sp->do_tweak) {
                                                                        logverb("    Forward order %i\n", sp->tweak_aborder);
                                                                        logverb("    Reverse order %i\n", sp->tweak_abporder);
                                                                    }
                                                                    logverb("  Indexes: %zu\n", pl_size(sp->indexes));
                                                                    for (i=0; i<pl_size(sp->indexes); i++) {
                                                                        index_t* ind = pl_get(sp->indexes, i);
                                                                        logverb("    %s\n", ind->indexname);
                                                                    }
                                                                    if (sp->fieldxy) {
                                                                        logverb("  Field (processed): %i stars\n", starxy_n(sp->fieldxy));
                                                                        for (i=0; i<starxy_n(sp->fieldxy); i++) {
                                                                            debug("    xy (%.1f, %.1f), flux %.1f\n",
                                                                                starxy_getx(sp->fieldxy, i), starxy_gety(sp->fieldxy, i),
                                                                                sp->fieldxy->flux ? starxy_get_flux(sp->fieldxy, i) : 0.0);
                                                                        }
                                                                    }
                                                                    if (sp->fieldxy_orig) {
                                                                        logverb("  Field (orig): %i stars\n", starxy_n(sp->fieldxy_orig));
                                                                        for (i=0; i<starxy_n(sp->fieldxy_orig); i++) {
                                                                            debug("    xy (%.1f, %.1f), flux %.1f\n",
                                                                                starxy_getx(sp->fieldxy_orig, i), starxy_gety(sp->fieldxy_orig, i),
                                                                                sp->fieldxy_orig->flux ? starxy_get_flux(sp->fieldxy_orig, i) : 0.0);
                                                                        }
                                                                    }
                                                                }

                                                                // The real thing
                                                                solver_run(sp);     // solver.c --> solver_run
                                                                
                                                                solver_run(sp){
                                                                    ......
                                                                    logverb("Quad scale range: [%g, %g] pixels\n", sqrt(solver->minminAB2), sqrt(solver->maxmaxAB2));
                                                                    ......
                                                                    for (newpoint = solver->startobj; newpoint < numxy; newpoint++) {
                                                                        ......
                                                                        for (field[A] = 0; field[A] < newpoint; field[A]++) {
                                                                            for (field[B] = field[A] + 1; field[B] < newpoint; field[B]++) {
                                                                                ......
                                                                                for (i = 0; i < pl_size(solver->indexes); i++) {
                                                                                    ......  
                                                                                    if (dimquads > 3) {
                                                                                        // ("dimquads - 3" because we've set stars A, B, and C at this point)
                                                                                        add_stars(pq, field, D, dimquads-3, 0, newpoint, dimquads, solver, tol2);
                                                                                    } else {
                                                                                        logverb("QHYCCD go to TRY_ALL_CODES -----------\n");
                                                                                        TRY_ALL_CODES(pq, field, dimquads, solver, tol2);   //#define TRY_ALL_CODES try_all_codes

                                                                                        try_all_codes(pq, field, dimquads, solver, tol2){
                                                                                            ......
                                                                                            if (solver->parity == PARITY_NORMAL ||
                                                                                                solver->parity == PARITY_BOTH) {

                                                                                                debug("    trying normal parity: code=[");
                                                                                                for (i=0; i<dimcode; i++)
                                                                                                    debug("%s%g", (i?", ":""), code[i]);
                                                                                                debug("].\n");
                                                                                                try_all_codes_2(fieldstars, dimquad, code, solver, FALSE, tol2);

                                                                                                try_all_codes_2(fieldstars, dimquad, code, solver, FALSE, tol2){
                                                                                                    ......
                                                                                                    // Un-flipped:
                                                                                                    stars[0] = fieldstars[0];
                                                                                                    stars[1] = fieldstars[1];

                                                                                                    for (i=0; i<DQMAX; i++)
                                                                                                        placed[i] = FALSE;
                                                                                                    logverb("QHYCCD ---Un-flipped  try_permutations \n");
                                                                                                    try_permutations(fieldstars, dimquad, code, solver, current_parity,
                                                                                                                    tol2, stars, NULL, 0, placed, &result);

                                                                                                    try_permutations(fieldstars, dimquad, code, solver, current_parity,tol2, stars, NULL, 0, placed, &result){
                                                                                                        ......
                                                                                                        for (i=0; i<Nstars; i++) {
                                                                                                            ......
                                                                                                            if (slot < lastslot) {

                                                                                                            }else{
                                                                                                                ......
                                                                                                                resolve_matches(*presult, pixvals, stars, dimquad, solver,current_parity);

                                                                                                                resolve_matches(*presult, pixvals, stars, dimquad, solver,current_parity){
                                                                                                                    for (jj = 0; jj < krez->nres; jj++) {
                                                                                                                        ......
                                                                                                                        if (solver_handle_hit(solver, &mo, NULL, FALSE))
                                                                                                                            solver->quit_now = TRUE;

                                                                                                                        solver_handle_hit(solver, &mo, NULL, FALSE){
                                                                                                                            ......
                                                                                                                            if (mo->logodds >= sp->best_logodds) {
                                                                                                                                sp->best_logodds = mo->logodds;
                                                                                                                                logverb("QHYCCD ---Got a new best match: logodds %g.\n", mo->logodds);
                                                                                                                            }
                                                                                                                            ......
                                                                                                                            // Also copy original field star coordinates
                                                                                                                            //mo.quadpix_orig
                                                                                                                            logverb("mo field stars:\n");
                                                                                                                            int i;
                                                                                                                            for (i=0; i<mo->dimquads; i++) {
                                                                                                                                logverb("  star %i; field_xy %.1f,%.1f, field_orig %.1f,%.1f\n",
                                                                                                                                    mo->field[i], mo->quadpix[2*i+0], mo->quadpix[2*i+1],
                                                                                                                                    starxy_getx(sp->fieldxy_orig, mo->field[i]),
                                                                                                                                    starxy_gety(sp->fieldxy_orig, mo->field[i]));
                                                                                                                                mo->quadpix_orig[2*i+0] = starxy_getx(sp->fieldxy_orig, mo->field[i]);
                                                                                                                                mo->quadpix_orig[2*i+1] = starxy_gety(sp->fieldxy_orig, mo->field[i]);
                                                                                                                            }

                                                                                                                            update_timeused(sp);
                                                                                                                            mo->timeused = sp->timeused;

                                                                                                                            matchobj_print(mo, log_get_level());    // matchobj.c --> matchobj_print

                                                                                                                            matchobj_print(mo, log_get_level()){
                                                                                                                                double ra,dec;
                                                                                                                                loglevel(loglvl, "  log-odds ratio %g (%g), %i match, %i conflict, %i distractors, %i index.\n",
                                                                                                                                        mo->logodds, exp(mo->logodds), mo->nmatch, mo->nconflict, mo->ndistractor, mo->nindex);
                                                                                                                                xyzarr2radecdeg(mo->center, &ra, &dec);
                                                                                                                                loglevel(loglvl, "  RA,Dec = (%g,%g), pixel scale %g arcsec/pix.\n",
                                                                                                                                        ra, dec, mo->scale);
                                                                                                                                if (mo->theta && mo->testperm) {
                                                                                                                                    loglevel(loglvl, "  Hit/miss: ");
                                                                                                                                    matchobj_log_hit_miss(mo->theta, mo->testperm, mo->nbest, mo->nfield,
                                                                                                                                                        loglvl, "  Hit/miss: ");
                                                                                                                                }

                                                                                                                            }

                                                                                                                            if (mo->logodds < sp->logratio_tokeep)
                                                                                                                                return FALSE;

                                                                                                                            logverb("Pixel scale: %g arcsec/pix.\n", mo->scale);
                                                                                                                            logverb("Parity: %s.\n", (mo->parity ? "neg" : "pos"));

                                                                                                                            mo->index = sp->index;
                                                                                                                            mo->index_jitter = sp->index->index_jitter;

                                                                                                                            if (sp->predistort || (sp->pixel_xscale > 0)) {
                                                                                                                                ......
                                                                                                                            }else if (sp->do_tweak){
                                                                                                                                solver_tweak2(sp, mo, sp->tweak_aborder, verifysip);

                                                                                                                                solver_tweak2(sp, mo, sp->tweak_aborder, verifysip){
                                                                                                                                    ......
                                                                                                                                    logverb("solver_tweak2: setting orders %i, %i\n", sp->tweak_aborder, sp->tweak_abporder);

                                                                                                                                    // for TWEAK_DEBUG_PLOTs
                                                                                                                                    theta = mo->theta;
                                                                                                                                    besti = mo->nbest-1;//mo->nmatch + mo->nconflict + mo->ndistractor;

                                                                                                                                    logverb("solver_tweak2: set_crpix %i, crpix (%.1f,%.1f)\n",
                                                                                                                                        sp->set_crpix, sp->crpix[0], sp->crpix[1]);
                                                                                                                                    mo->sip = tweak2(xy, Nxy,           //  tweak2.c --> tweak2
                                                                                                                                                    sp->verify_pix, // pixel positional noise sigma
                                                                                                                                                    solver_field_width(sp),
                                                                                                                                                    solver_field_height(sp),
                                                                                                                                                    refradec, mo->nindex,
                                                                                                                                                    indexjitter, qc, Q2,
                                                                                                                                                    sp->distractor_ratio,
                                                                                                                                                    sp->logratio_bail_threshold,
                                                                                                                                                    order, sp->tweak_abporder,
                                                                                                                                                    &startsip, NULL, &theta, &odds,
                                                                                                                                                    sp->set_crpix ? sp->crpix : NULL,
                                                                                                                                                    &newodds, &besti, mo->testperm, startorder);
                                                                                                                                    
                                                                                                                                    tweak2(xy, Nxy,          
                                                                                                                                        sp->verify_pix, // pixel positional noise sigma
                                                                                                                                        solver_field_width(sp),
                                                                                                                                        solver_field_height(sp),
                                                                                                                                        refradec, mo->nindex,
                                                                                                                                        indexjitter, qc, Q2,
                                                                                                                                        sp->distractor_ratio,
                                                                                                                                        sp->logratio_bail_threshold,
                                                                                                                                        order, sp->tweak_abporder,
                                                                                                                                        &startsip, NULL, &theta, &odds,
                                                                                                                                        sp->set_crpix ? sp->crpix : NULL,
                                                                                                                                        &newodds, &besti, mo->testperm, startorder){
                                                                                                                                            ......
                                                                                                                                            logverb("tweak2: starting orders %i, %i\n", sipout->a_order, sipout->ap_order);
                                                                                                                                            if (!sipout->wcstan.imagew)
                                                                                                                                                sipout->wcstan.imagew = W;
                                                                                                                                            if (!sipout->wcstan.imageh)
                                                                                                                                                sipout->wcstan.imageh = H;

                                                                                                                                            logverb("Tweak2: starting from WCS:\n");
                                                                                                                                            if (log_get_level() >= LOG_VERB)
                                                                                                                                                sip_print_to(sipout, stdout);   // sip.c --> sip_print_to 
                                                                                                                                            
                                                                                                                                            sip_print_to(sipout, stdout){
                                                                                                                                                double det,pixsc;

                                                                                                                                                if (sip->wcstan.sin) {
                                                                                                                                                    print_to(&(sip->wcstan), f, "SIN-SIP");
                                                                                                                                                } else {
                                                                                                                                                    print_to(&(sip->wcstan), f, "TAN-SIP");

                                                                                                                                                    print_to(&(sip->wcstan), f, "TAN-SIP"){
                                                                                                                                                        fprintf(f,"%s Structure:\n", type);
                                                                                                                                                        fprintf(f,"  crval=(%g, %g)\n", tan->crval[0], tan->crval[1]);
                                                                                                                                                        fprintf(f,"  crpix=(%g, %g)\n", tan->crpix[0], tan->crpix[1]);
                                                                                                                                                        fprintf(f,"  CD = ( %12.5g   %12.5g )\n", tan->cd[0][0], tan->cd[0][1]);
                                                                                                                                                        fprintf(f,"       ( %12.5g   %12.5g )\n", tan->cd[1][0], tan->cd[1][1]);
                                                                                                                                                        fprintf(f,"  image size = (%g x %g)\n", tan->imagew, tan->imageh);
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                fprintf(f, "  SIP order: A=%i, B=%i, AP=%i, BP=%i\n",
                                                                                                                                                        sip->a_order, sip->b_order, sip->ap_order, sip->bp_order);
                                                                                                                                                
                                                                                                                                                if (sip->a_order > 0) {
                                                                                                                                                    int p, q;
                                                                                                                                                    for (p=0; p<=sip->a_order; p++) {
                                                                                                                                                        fprintf(f, (p ? "      " : "  A = "));
                                                                                                                                                        for (q=0; q<=sip->a_order; q++)
                                                                                                                                                            if (p+q <= sip->a_order)
                                                                                                                                                                //fprintf(f,"a%d%d=%le\n", p,q,sip->a[p][q]);
                                                                                                                                                                fprintf(f,"%12.5g", sip->a[p][q]);
                                                                                                                                                        fprintf(f,"\n");
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                if (sip->b_order > 0) {
                                                                                                                                                    int p, q;
                                                                                                                                                    for (p=0; p<=sip->b_order; p++) {
                                                                                                                                                        fprintf(f, (p ? "      " : "  B = "));
                                                                                                                                                        for (q=0; q<=sip->b_order; q++)
                                                                                                                                                            if (p+q <= sip->a_order)
                                                                                                                                                                fprintf(f,"%12.5g", sip->b[p][q]);
                                                                                                                                                        //if (p+q <= sip->b_order && p+q > 0)
                                                                                                                                                        //fprintf(f,"b%d%d=%le\n", p,q,sip->b[p][q]);
                                                                                                                                                        fprintf(f,"\n");
                                                                                                                                                    }
                                                                                                                                                }

                                                                                                                                                if (sip->ap_order > 0) {
                                                                                                                                                    int p, q;
                                                                                                                                                    for (p=0; p<=sip->ap_order; p++) {
                                                                                                                                                        fprintf(f, (p ? "      " : "  AP = "));
                                                                                                                                                        for (q=0; q<=sip->ap_order; q++)
                                                                                                                                                            if (p+q <= sip->ap_order)
                                                                                                                                                                fprintf(f,"%12.5g", sip->ap[p][q]);
                                                                                                                                                        fprintf(f,"\n");
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                if (sip->bp_order > 0) {
                                                                                                                                                    int p, q;
                                                                                                                                                    for (p=0; p<=sip->bp_order; p++) {
                                                                                                                                                        fprintf(f, (p ? "      " : "  BP = "));
                                                                                                                                                        for (q=0; q<=sip->bp_order; q++)
                                                                                                                                                            if (p+q <= sip->bp_order)
                                                                                                                                                                fprintf(f,"%12.5g", sip->bp[p][q]);
                                                                                                                                                        fprintf(f,"\n");
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                det = sip_det_cd(sip);
                                                                                                                                                pixsc = 3600*sqrt(fabs(det));
                                                                                                                                                //fprintf(f,"  det(CD)=%g\n", det);
                                                                                                                                                fprintf(f,"  sqrt(det(CD))=%g [arcsec]\n", pixsc);
                                                                                                                                                //fprintf(f,"\n");

                                                                                                                                            }

                                                                                                                                            for (order=startorder; order <= sip_order; order++) {
                                                                                                                                                ......
                                                                                                                                                for (step=0; step<STEPS; step++) {
                                                                                                                                                    ......
                                                                                                                                                    logverb("Annealing: order %i, step %i, gamma = %g\n", order, step, gamma);
                                                                                                                                                    ......
                                                                                                                                                    logverb("%i reference sources within the image.\n", Nin);
                                                                                                                                                    ......
                                                                                                                                                    logodds = verify_star_lists_ror(indexpix, Nin,
                                                                                                                                                                                    fieldxy, fieldsigma2s, Nfield,
                                                                                                                                                                                    pix2, gamma, qc, quadR2,
                                                                                                                                                                                    W, H, distractors,
                                                                                                                                                                                    logodds_bail, LARGE_VAL,
                                                                                                                                                                                    &besti, &odds, &theta, NULL,
                                                                                                                                                                                    &testperm, &refperm);       //verify.c --> verify_star_lists_ror
                                                                                                                                                    
                                                                                                                                                    verify_star_lists_ror(indexpix, Nin, fieldxy, fieldsigma2s, Nfield, pix2, gamma, 
                                                                                                                                                                        qc, quadR2, W, H, distractors, logodds_bail, LARGE_VAL,
                                                                                                                                                                        &besti, &odds, &theta, NULL,
                                                                                                                                                                        &testperm, &refperm){
                                                                                                                                                                            ......
                                                                                                                                                                            ror2 = verify_get_ror2(Q2, W*H, distractors, NR, pix2);
                                                                                                                                                                            logverb("RoR: %g\n", sqrt(ror2));
                                                                                                                                                                            ......
                                                                                                                                                                            v.NT = igood;
                                                                                                                                                                            // remember the bad guys
                                                                                                                                                                            memcpy(v.testperm + igood, v.tbadguys, ibad * sizeof(int));
                                                                                                                                                                            logverb("Test stars in RoR: %i of %i\n", v.NT, v.NTall);
                                                                                                                                                                            ......
                                                                                                                                                                            effective_area = W*H * (double)Ngood / (double)NB;
                                                                                                                                                                            logverb("Good bins: %i / %i; effA %g of %g\n", Ngood, NB, W*H, effective_area);
                                                                                                                                                                            ......
                                                                                                                                                                            // remember the bad guys
                                                                                                                                                                            memcpy(v.refperm + igood, v.badguys, ibad * sizeof(int));
                                                                                                                                                                            v.NR = igood;
                                                                                                                                                                            logverb("Ref stars in RoR: %i of %i\n", v.NR, v.NRall);
                                                                                                                                                                            ......
                                                                                                                                                                        }
                                                                                                                                                    logverb("Logodds: %g\n", logodds);
                                                                                                                                                    verify_count_hits(theta, besti, &nmatch, &nconf, &ndist);
                                                                                                                                                    logverb("%i matches, %i distractors, %i conflicts (at best log-odds); %i field sources, %i index sources\n", nmatch, ndist, nconf, Nfield, Nin);
                                                                                                                                                    verify_count_hits(theta, Nfield-1, &nmatch, &nconf, &ndist);
                                                                                                                                                    logverb("%i matches, %i distractors, %i conflicts (all sources)\n", nmatch, ndist, nconf);
                                                                                                                                                    if (log_get_level() >= LOG_VERB) {
                                                                                                                                                        matchobj_log_hit_miss(theta, testperm, besti+1, Nfield, LOG_VERB, "Hit/miss: ");
                                                                                                                                                    }
                                                                                                                                                    ......
                                                                                                                                                    // Update the "quad center" to be the weighted average matched star posn.
                                                                                                                                                    qc[0] = qc[1] = 0.0;
                                                                                                                                                    totalweight = 0.0;
                                                                                                                                                    for (i=0; i<Nmatch; i++) {
                                                                                                                                                        qc[0] += (weights[i] * matchxy[2*i+0]);
                                                                                                                                                        qc[1] += (weights[i] * matchxy[2*i+1]);
                                                                                                                                                        totalweight += weights[i];
                                                                                                                                                    }
                                                                                                                                                    qc[0] /= totalweight;
                                                                                                                                                    qc[1] /= totalweight;
                                                                                                                                                    logverb("Moved quad center to (%.1f, %.1f)\n", qc[0], qc[1]);

                                                                                                                                                    //
                                                                                                                                                    sipout->a_order = sipout->b_order = order;
                                                                                                                                                    sipout->ap_order = sipout->bp_order = sip_invorder;
                                                                                                                                                    logverb("tweak2: setting orders %i, %i\n", sipout->a_order, sipout->ap_order);
                                                                                                                                                    ......
                                                                                                                                                    fit_sip_wcs(matchxyz, matchxy, weights, Nmatch,
                                                                                                                                                                &(sipout->wcstan), order, sip_invorder,
                                                                                                                                                                doshift, sipout);       // fit-wcs.c --> fit_sip_wcs

                                                                                                                                                    fit_sip_wcs(matchxyz, matchxy, weights, Nmatch,
                                                                                                                                                                &(sipout->wcstan), order, sip_invorder,
                                                                                                                                                                doshift, sipout){
                                                                                                                                                                    ......
                                                                                                                                                                    if (weights)
                                                                                                                                                                        logverb("Total weight: %g\n", totalweight);
                                                                                                                                                                    ......
                                                                                                                                                                    sip_compute_inverse_polynomials(sipout, 0, 0, 0, 0, 0, 0);  //  sip-utils.c --> sip_ensure_inverse_polynomials

                                                                                                                                                                    sip_compute_inverse_polynomials(sipout, 0, 0, 0, 0, 0, 0){
                                                                                                                                                                        ......
                                                                                                                                                                        logverb("sip_compute-inverse_polynomials: A %i, AP %i\n",
                                                                                                                                                                                sip->a_order, sip->ap_order); 
                                                                                                                                                                        ......
                                                                                                                                                                        logverb("NX,NY %i,%i, x range [%f, %f], y range [%f, %f]\n",
                                                                                                                                                                                NX,NY, xlo, xhi, ylo, yhi);

                                                                                                                                                                    }

                                                                                                                                                                    if (doshift) {
                                                                                                                                                                        sU =
                                                                                                                                                                            cdinv[0][0] * sx +
                                                                                                                                                                            cdinv[0][1] * sy;
                                                                                                                                                                        sV =
                                                                                                                                                                            cdinv[1][0] * sx +
                                                                                                                                                                            cdinv[1][1] * sy;
                                                                                                                                                                        logverb("Applying shift of sx,sy = %g,%g deg (%g,%g pix) to CRVAL and CD.\n",
                                                                                                                                                                                sx, sy, sU, sV);

                                                                                                                                                                        sip_calc_inv_distortion(sipout, sU, sV, &su, &sv);

                                                                                                                                                                        debug("sx = %g, sy = %g\n", sx, sy);
                                                                                                                                                                        debug("sU = %g, sV = %g\n", sU, sV);
                                                                                                                                                                        debug("su = %g, sv = %g\n", su, sv);

                                                                                                                                                                        wcs_shift(&(sipout->wcstan), -su, -sv);
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                    ......
                                                                                                                                                }
                                                                                                                                    


                                                                                                                                            }
                                                                                                                                            // Now, recompute final logodds after turning 'gamma' on again (?)
                                                                                                                                            // FIXME -- this counts the quad stars in the logodds...
                                                                                                                                            {
                                                                                                                                                ......
                                                                                                                                                logverb("%i reference sources within the image.\n", Nin);
                                                                                                                                                ......
                                                                                                                                                logodds = verify_star_lists_ror(indexpix, Nin,
                                                                                                                                                        fieldxy, fieldsigma2s, Nfield,
                                                                                                                                                        pix2, gamma, qc, quadR2,
                                                                                                                                                        W, H, distractors,
                                                                                                                                                        logodds_bail, LARGE_VAL,
                                                                                                                                                        &besti, &odds, &theta, NULL,
                                                                                                                                                        &testperm, &refperm);
                                                                                                                                                
                                                                                                                                                verify_star_lists_ror(indexpix, Nin, fieldxy, fieldsigma2s, Nfield, pix2, gamma, 
                                                                                                                                                                        qc, quadR2, W, H, distractors, logodds_bail, LARGE_VAL,
                                                                                                                                                                        &besti, &odds, &theta, NULL,
                                                                                                                                                                        &testperm, &refperm){
                                                                                                                                                                            ......
                                                                                                                                                                            ror2 = verify_get_ror2(Q2, W*H, distractors, NR, pix2);
                                                                                                                                                                            logverb("RoR: %g\n", sqrt(ror2));
                                                                                                                                                                            ......
                                                                                                                                                                            v.NT = igood;
                                                                                                                                                                            // remember the bad guys
                                                                                                                                                                            memcpy(v.testperm + igood, v.tbadguys, ibad * sizeof(int));
                                                                                                                                                                            logverb("Test stars in RoR: %i of %i\n", v.NT, v.NTall);
                                                                                                                                                                            ......
                                                                                                                                                                            effective_area = W*H * (double)Ngood / (double)NB;
                                                                                                                                                                            logverb("Good bins: %i / %i; effA %g of %g\n", Ngood, NB, W*H, effective_area);
                                                                                                                                                                            ......
                                                                                                                                                                            // remember the bad guys
                                                                                                                                                                            memcpy(v.refperm + igood, v.badguys, ibad * sizeof(int));
                                                                                                                                                                            v.NR = igood;
                                                                                                                                                                            logverb("Ref stars in RoR: %i of %i\n", v.NR, v.NRall);
                                                                                                                                                                            ......
                                                                                                                                                                        }

                                                                                                                                                logverb("Logodds: %g\n", logodds);
                                                                                                                                                verify_count_hits(theta, besti, &nmatch, &nconf, &ndist);
                                                                                                                                                logverb("%i matches, %i distractors, %i conflicts (at best log-odds); %i field sources, %i index sources\n", nmatch, ndist, nconf, Nfield, Nin);
                                                                                                                                                verify_count_hits(theta, Nfield-1, &nmatch, &nconf, &ndist);
                                                                                                                                                logverb("%i matches, %i distractors, %i conflicts (all sources)\n", nmatch, ndist, nconf);
                                                                                                                                                if (log_get_level() >= LOG_VERB) {
                                                                                                                                                    matchobj_log_hit_miss(theta, testperm, besti+1, Nfield, LOG_VERB,
                                                                                                                                                                        "Hit/miss: ");
                                                                                                                                                }

                                                                                                                                                ......

                                                                                                                                            }

                                                                                                                                            logverb("Tweak2: final WCS:\n");
                                                                                                                                            if (log_get_level() >= LOG_VERB)
                                                                                                                                                sip_print_to(sipout, stdout);

                                                                                                                                            sip_print_to(sipout, stdout){
                                                                                                                                                double det,pixsc;

                                                                                                                                                if (sip->wcstan.sin) {
                                                                                                                                                    print_to(&(sip->wcstan), f, "SIN-SIP");
                                                                                                                                                } else {
                                                                                                                                                    print_to(&(sip->wcstan), f, "TAN-SIP");

                                                                                                                                                    print_to(&(sip->wcstan), f, "TAN-SIP"){
                                                                                                                                                        fprintf(f,"%s Structure:\n", type);
                                                                                                                                                        fprintf(f,"  crval=(%g, %g)\n", tan->crval[0], tan->crval[1]);
                                                                                                                                                        fprintf(f,"  crpix=(%g, %g)\n", tan->crpix[0], tan->crpix[1]);
                                                                                                                                                        fprintf(f,"  CD = ( %12.5g   %12.5g )\n", tan->cd[0][0], tan->cd[0][1]);
                                                                                                                                                        fprintf(f,"       ( %12.5g   %12.5g )\n", tan->cd[1][0], tan->cd[1][1]);
                                                                                                                                                        fprintf(f,"  image size = (%g x %g)\n", tan->imagew, tan->imageh);
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                fprintf(f, "  SIP order: A=%i, B=%i, AP=%i, BP=%i\n",
                                                                                                                                                        sip->a_order, sip->b_order, sip->ap_order, sip->bp_order);
                                                                                                                                                
                                                                                                                                                if (sip->a_order > 0) {
                                                                                                                                                    int p, q;
                                                                                                                                                    for (p=0; p<=sip->a_order; p++) {
                                                                                                                                                        fprintf(f, (p ? "      " : "  A = "));
                                                                                                                                                        for (q=0; q<=sip->a_order; q++)
                                                                                                                                                            if (p+q <= sip->a_order)
                                                                                                                                                                //fprintf(f,"a%d%d=%le\n", p,q,sip->a[p][q]);
                                                                                                                                                                fprintf(f,"%12.5g", sip->a[p][q]);
                                                                                                                                                        fprintf(f,"\n");
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                if (sip->b_order > 0) {
                                                                                                                                                    int p, q;
                                                                                                                                                    for (p=0; p<=sip->b_order; p++) {
                                                                                                                                                        fprintf(f, (p ? "      " : "  B = "));
                                                                                                                                                        for (q=0; q<=sip->b_order; q++)
                                                                                                                                                            if (p+q <= sip->a_order)
                                                                                                                                                                fprintf(f,"%12.5g", sip->b[p][q]);
                                                                                                                                                        //if (p+q <= sip->b_order && p+q > 0)
                                                                                                                                                        //fprintf(f,"b%d%d=%le\n", p,q,sip->b[p][q]);
                                                                                                                                                        fprintf(f,"\n");
                                                                                                                                                    }
                                                                                                                                                }

                                                                                                                                                if (sip->ap_order > 0) {
                                                                                                                                                    int p, q;
                                                                                                                                                    for (p=0; p<=sip->ap_order; p++) {
                                                                                                                                                        fprintf(f, (p ? "      " : "  AP = "));
                                                                                                                                                        for (q=0; q<=sip->ap_order; q++)
                                                                                                                                                            if (p+q <= sip->ap_order)
                                                                                                                                                                fprintf(f,"%12.5g", sip->ap[p][q]);
                                                                                                                                                        fprintf(f,"\n");
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                if (sip->bp_order > 0) {
                                                                                                                                                    int p, q;
                                                                                                                                                    for (p=0; p<=sip->bp_order; p++) {
                                                                                                                                                        fprintf(f, (p ? "      " : "  BP = "));
                                                                                                                                                        for (q=0; q<=sip->bp_order; q++)
                                                                                                                                                            if (p+q <= sip->bp_order)
                                                                                                                                                                fprintf(f,"%12.5g", sip->bp[p][q]);
                                                                                                                                                        fprintf(f,"\n");
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                                det = sip_det_cd(sip);
                                                                                                                                                pixsc = 3600*sqrt(fabs(det));
                                                                                                                                                //fprintf(f,"  det(CD)=%g\n", det);
                                                                                                                                                fprintf(f,"  sqrt(det(CD))=%g [arcsec]\n", pixsc);
                                                                                                                                                //fprintf(f,"\n");

                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                            ......
                                                                                                                            // If the user didn't supply a callback, or if the callback
                                                                                                                            // returns TRUE, consider it solved.
                                                                                                                            solved = (!sp->record_match_callback ||
                                                                                                                                    sp->record_match_callback(mo, sp->userdata));   //  onefield.c --> record_match_callback 
                                                                                                                            
                                                                                                                            record_match_callback(mo, sp->userdata){
                                                                                                                                ......
                                                                                                                                if (bp->indexrdlsfname || bp->scamp_fname || bp->corr_fname){
                                                                                                                                    ......
                                                                                                                                    if (bp->rdls_tagalong || bp->rdls_tagalong_all)
                                                                                                                                        grab_tagalong_data(sp->index->starkd, mymo, bp, mymo->refstarid, mymo->nindex);
                                                                                                                                
                                                                                                                                    grab_tagalong_data(sp->index->starkd, mymo, bp, mymo->refstarid, mymo->nindex){
                                                                                                                                        ......
                                                                                                                                        if (bp->rdls_tagalong_all) { // && ! bp->done_rdls_tagalong_all
                                                                                                                                        ......
                                                                                                                                        logverb("Found tag-along columns: %s\n", cols);
                                                                                                                                        }

                                                                                                                                    }

                                                                                                                                }
                                                                                                                                ......
                                                                                                                                if (bp->nsolves_sofar < bp->nsolves) {
                                                                                                                                    logmsg("Found a quad that solves the image; that makes %i of %i required.\n",
                                                                                                                                        bp->nsolves_sofar, bp->nsolves);
                                                                                                                                } else {
                                                                                                                                    if (bp->solver.index) {
                                                                                                                                        char* base = basename_safe(bp->solver.index->indexname);
                                                                                                                                        logmsg("QHYCCD solver.index Field %i: solved with index %s.\n", mymo->fieldnum, base);
                                                                                                                                        free(base);
                                                                                                                                    } else {
                                                                                                                                        logmsg("QHYCCD++++Field %i: solved with index %i", mymo->fieldnum, mymo->indexid);
                                                                                                                                        if (mymo->healpix >= 0)
                                                                                                                                            logmsg(", healpix %i\n", mymo->healpix);
                                                                                                                                        else
                                                                                                                                            logmsg("\n");
                                                                                                                                    }
                                                                                                                                    return TRUE;
                                                                                                                                }

                                                                                                                                

                                                                                                                            }

                                                                                                                }


                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    if (unlikely(solver->quit_now))
                                                                                                        goto bailout;

                                                                                                    // Flipped:
                                                                                                    stars[0] = fieldstars[1];
                                                                                                    stars[1] = fieldstars[0];

                                                                                                    for (i=0; i<dimcode; i++)
                                                                                                        flipcode[i] = 1.0 - code[i];

                                                                                                    for (i=0; i<DQMAX; i++)
                                                                                                        placed[i] = FALSE;
                                                                                                    logverb("QHYCCD ---Flipped:   try_permutations \n");

                                                                                                    try_permutations(fieldstars, dimquad, flipcode, solver, current_parity,
                                                                                                                    tol2, stars, NULL, 0, placed, &result);

                                                                                                    try_permutations(fieldstars, dimquad, code, solver, current_parity,tol2, stars, NULL, 0, placed, &result){
                                                                                                        ......
                                                                                                        for (i=0; i<Nstars; i++) {
                                                                                                            ......
                                                                                                            if (slot < lastslot) {

                                                                                                            }else{
                                                                                                                ......
                                                                                                                resolve_matches(*presult, pixvals, stars, dimquad, solver,current_parity);

                                                                                                                resolve_matches(*presult, pixvals, stars, dimquad, solver,current_parity){
                                                                                                                    for (jj = 0; jj < krez->nres; jj++) {
                                                                                                                        ......
                                                                                                                        if (solver_handle_hit(solver, &mo, NULL, FALSE))
                                                                                                                            solver->quit_now = TRUE;

                                                                                                                        solver_handle_hit(solver, &mo, NULL, FALSE){
                                                                                                                            ......
                                                                                                                            if (mo->logodds >= sp->best_logodds) {
                                                                                                                                sp->best_logodds = mo->logodds;
                                                                                                                                logverb("QHYCCD ---Got a new best match: logodds %g.\n", mo->logodds);
                                                                                                                            }
                                                                                                                            ......
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                            if (solver->parity == PARITY_FLIP ||
                                                                                                solver->parity == PARITY_BOTH) {

                                                                                                quad_flip_parity(code, flipcode, dimcode);

                                                                                                debug("    trying reverse parity: code=[");
                                                                                                for (i=0; i<dimcode; i++)
                                                                                                    debug("%s%g", (i?", ":""), flipcode[i]);
                                                                                                debug("].\n");
                                                                                                try_all_codes_2(fieldstars, dimquad, flipcode, solver, TRUE, tol2);


                                                                                                try_all_codes_2(fieldstars, dimquad, code, solver, FALSE, tol2){
                                                                                                    ......
                                                                                                    try_permutations(fieldstars, dimquad, code, solver, current_parity,
                                                                                                                    tol2, stars, NULL, 0, placed, &result);

                                                                                                    try_permutations(fieldstars, dimquad, code, solver, current_parity,tol2, stars, NULL, 0, placed, &result){
                                                                                                        ......
                                                                                                        for (i=0; i<Nstars; i++) {
                                                                                                            ......
                                                                                                            if (slot < lastslot) {

                                                                                                            }else{
                                                                                                                ......
                                                                                                                resolve_matches(*presult, pixvals, stars, dimquad, solver,current_parity);

                                                                                                                resolve_matches(*presult, pixvals, stars, dimquad, solver,current_parity){
                                                                                                                    for (jj = 0; jj < krez->nres; jj++) {
                                                                                                                        ......
                                                                                                                        if (solver_handle_hit(solver, &mo, NULL, FALSE))
                                                                                                                            solver->quit_now = TRUE;

                                                                                                                        solver_handle_hit(solver, &mo, NULL, FALSE){
                                                                                                                            ......
                                                                                                                            if (mo->logodds >= sp->best_logodds) {
                                                                                                                                sp->best_logodds = mo->logodds;
                                                                                                                                logverb("QHYCCD ---Got a new best match: logodds %g.\n", mo->logodds);
                                                                                                                            }
                                                                                                                            ......
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    if (unlikely(solver->quit_now))
                                                                                                        goto bailout;

                                                                                                    // Flipped:
                                                                                                    stars[0] = fieldstars[1];
                                                                                                    stars[1] = fieldstars[0];

                                                                                                    for (i=0; i<dimcode; i++)
                                                                                                        flipcode[i] = 1.0 - code[i];

                                                                                                    for (i=0; i<DQMAX; i++)
                                                                                                        placed[i] = FALSE;

                                                                                                    try_permutations(fieldstars, dimquad, flipcode, solver, current_parity,
                                                                                                                    tol2, stars, NULL, 0, placed, &result);

                                                                                                    try_permutations(fieldstars, dimquad, code, solver, current_parity,tol2, stars, NULL, 0, placed, &result){
                                                                                                        ......
                                                                                                        for (i=0; i<Nstars; i++) {
                                                                                                            ......
                                                                                                            if (slot < lastslot) {

                                                                                                            }else{
                                                                                                                ......
                                                                                                                resolve_matches(*presult, pixvals, stars, dimquad, solver,current_parity);

                                                                                                                resolve_matches(*presult, pixvals, stars, dimquad, solver,current_parity){
                                                                                                                    for (jj = 0; jj < krez->nres; jj++) {
                                                                                                                        ......
                                                                                                                        if (solver_handle_hit(solver, &mo, NULL, FALSE))
                                                                                                                            solver->quit_now = TRUE;

                                                                                                                        solver_handle_hit(solver, &mo, NULL, FALSE){
                                                                                                                            ......
                                                                                                                            if (mo->logodds >= sp->best_logodds) {
                                                                                                                                sp->best_logodds = mo->logodds;
                                                                                                                                logverb("QHYCCD ---Got a new best match: logodds %g.\n", mo->logodds);
                                                                                                                            }
                                                                                                                            ......
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                        logverb("object %u of %u: %i quads tried, %i matched.\n",
                                                                            newpoint + 1, numxy, solver->numtries, solver->nummatches);
                                                                    }
                                                                }

                                                                logverb("Field %i: tried %i quads, matched %i codes.\n",
                                                                        fieldnum, sp->numtries, sp->nummatches);

                                                                if (sp->maxquads && sp->numtries >= sp->maxquads)
                                                                    logmsg("  exceeded the number of quads to try: %i >= %i.\n",
                                                                        sp->numtries, sp->maxquads);
                                                                if (sp->maxmatches && sp->nummatches >= sp->maxmatches)
                                                                    logmsg("  exceeded the number of quads to match: %i >= %i.\n",
                                                                        sp->nummatches, sp->maxmatches);
                                                                if (bp->cancelled)
                                                                    logmsg("  cancelled at user request.\n");
                                                            }

                                                            if (sp->best_match_solves) {
                                                                solved_field(bp, fieldnum);

                                                                solved_field(bp, fieldnum){
                                                                    // Record in solved file, or send to solved server.
                                                                    if (bp->solved_out) {
                                                                        logmsg("Field %i solved: writing to file %s to indicate this.\n", fieldnum, bp->solved_out);
                                                                        if (solvedfile_set(bp->solved_out, fieldnum)) {
                                                                            logerr("Failed to write solvedfile %s.\n", bp->solved_out);
                                                                        }
                                                                    }
                                                                    // If we're just solving a single field, and we solved it...
                                                                    if (il_size(bp->fieldlist) == 1)
                                                                        bp->single_field_solved = TRUE;
                                                                }
                                                            } else if (!verify_wcs) {
                                                                // Field unsolved.
                                                                logerr("Field %i did not solve", fieldnum);
                                                                if (bp->solver.index && bp->solver.index->indexname) {
                                                                    char* copy;
                                                                    char* base;
                                                                    copy = strdup(bp->solver.index->indexname);
                                                                    base = strdup(basename(copy));
                                                                    free(copy);
                                                                    logerr(" (index %s", base);
                                                                    free(base);
                                                                    if (bp->solver.endobj)
                                                                        logerr(", field objects %i-%i", bp->solver.startobj+1, bp->solver.endobj);
                                                                    logerr(")");
                                                                }
                                                                logerr(".\n");
                                                                if (sp->have_best_match) {
                                                                    logverb("Best match encountered: ");
                                                                    matchobj_print(&(sp->best_match), log_get_level());
                                                                } else {
                                                                    logverb("Best odds encountered: %g\n", exp(sp->best_logodds));
                                                                }
                                                            }

                                                            ......
                                                            logverb("Spent %g s user, %g s system, %g s total, %g s wall time.\n",
                                                                    (utime - last_utime), (stime - last_stime),
                                                                    (stime - last_stime + utime - last_utime),
                                                                    millis_between(&last_wtime, &wtime) * 0.001);
                                                        }
                                                    }
                                                }
                                            }
                                            cleanup:
                                                // Clean up.
                                                xylist_close(bp->xyls);

                                                if (write_solutions(bp))
                                                    exit(-1);

                                                write_solutions(bp){
                                                    ......
                                                    if (bp->corr_fname) {
                                                        if (write_corr_file(bp))
                                                            return -1;

                                                        write_corr_file(bp){
                                                            ......
                                                            {
                                                                int rows = 0;
                                                                for (j=0; j<mo->nfield; j++) {
                                                                    if (mo->theta[j] < 0)
                                                                        continue;
                                                                    rows++;
                                                                }
                                                                logverb("Writing %i rows (of %i field and %i index objects) to correspondence file.\n", rows, mo->nfield, mo->nindex);
                                                            }
                                                            ......

                                                        }
                                                    }
                                                    return 0;
                                                }

                                                for (i=0; i<bl_size(bp->solutions); i++) {
                                                    MatchObj* mo = bl_access(bp->solutions, i);
                                                    verify_free_matchobj(mo);
                                                    onefield_free_matchobj(mo);
                                                }
                                                bl_remove_all(bp->solutions);
                                            }
                                        }
                                    }
                                        }
                                    }
                                }
                                logverb("cx<=dx constraints: %i\n", sp->num_cxdx_skipped);
                                logverb("meanx constraints: %i\n", sp->num_meanx_skipped);
                                logverb("RA,Dec constraints: %i\n", sp->num_radec_skipped);
                                logverb("AB scale constraints: %i\n", sp->num_abscale_skipped);
                            }
                        }
                    }
                }
            }
            after_solved(axy, sf, makeplots, me, verbose,
                        axy->tempdir, tempdirs, tempfiles, plotxy, plotscale, bgfn); 
            after_solved(axy, sf, makeplots, me, verbose, axy->tempdir, tempdirs, tempfiles, plotxy, plotscale, bgfn){
                // print info about the field.
                logmsg("Field: %s\n", axy->imagefn ? axy->imagefn : axy->xylsfn);
                if (file_exists(axy->wcsfn)) {
                    double orient;
                    if (axy->wcs_last_mod) {
                        time_t t = file_get_last_modified_time(axy->wcsfn);
                        if (t == axy->wcs_last_mod) {
                            logmsg("Warning: there was already a WCS file, and its timestamp has not changed.\n");
                        }
                    }
                    if (!sip_read_header_file(axy->wcsfn, &wcs)) {
                        ERROR("Failed to read WCS header from file %s", axy->wcsfn);
                        exit(-1);
                    }
                    sip_get_radec_center(&wcs, &ra, &dec);
                    sip_get_radec_center_hms_string(&wcs, rastr, decstr);
                    sip_get_field_size(&wcs, &fieldw, &fieldh, &fieldunits);
                    orient = sip_get_orientation(&wcs);
                    logmsg("Field center: (RA,Dec) = (%3.6f, %3.6f) deg.\n", ra, dec);
                    logmsg("Field center: (RA H:M:S, Dec D:M:S) = (%s, %s).\n", rastr, decstr);
                    logmsg("Field size: %g x %g %s\n", fieldw, fieldh, fieldunits);
                    logmsg("Field rotation angle: up is %g degrees E of N\n", orient);
                    // Note, negative determinant = positive parity.
                    double det = sip_det_cd(&wcs);
                    logmsg("Field parity: %s\n", (det < 0 ? "pos" : "neg"));

                } else {
                    logmsg("Did not solve (or no WCS file was written).\n");
                }

                // create new FITS file...
                if (axy->fitsimgfn && sf->newfitsfn && file_exists(axy->wcsfn)) {
                    int ext = axy->isfits ? axy->fitsimgext : 0;
                    logmsg("Creating new FITS file \"%s\"...\n", sf->newfitsfn);
                    //logmsg("From image %s, ext
                    if (new_wcs(axy->fitsimgfn, ext, axy->wcsfn,    // new-wcs.c --> new_wcs
                                sf->newfitsfn, TRUE)) {
                        ERROR("Failed to create FITS image with new WCS headers");
                        exit(-1);
                    }

                    new_wcs(axy->fitsimgfn, ext, axy->wcsfn, sf->newfitsfn, TRUE){
                        ......
                        logverb("Reading input file FITS headers...\n");
                        ......
                        for (i=0; i<N; i++) {
                            anbool added_newkey = FALSE;
                            char line[FITS_LINESZ + 1];
                            if (qfits_header_getitem(inhdr, i, key, val, comment, line)) {
                                ERROR("Failed to read FITS header card %i from input file", i);
                                goto bailout;
                            }
                            logverb("Read input header line: \"%s\"\n", line);

                            if (key_matches(key, re1, exclude_input, NE1, &imatch)) {
                                logverb("Regular expression matched: \"%s\", key \"%s\".\n", exclude_input[imatch], key);
                                snprintf(newkey, FITS_LINESZ+1, "Original key: \"%s\"", key);
                                qfits_header_append(outhdr, "COMMENT", newkey, NULL, NULL);
                                // Completely skip the END card, since _ND is not a valid line.
                                if (streq(key, "END"))
                                    continue;
                                snprintf(newkey, FITS_LINESZ+1, "_%.7s", key+1);
                                logverb("New key: \"%s\"\n", newkey);
                                strcpy(key, newkey);
                                line[0] = '_';
                                added_newkey = TRUE;
                            }
                            ......
                        }
                        ......
                        logverb("Reading WCS file FITS headers...\n");
                        ......
                        for (i=0; i<N; i++) {
                            ......
                            if (key_matches(key, re2, exclude_wcs, NE2, &imatch)) {
                                logverb("Regular expression matched: \"%s\", key \"%s\".\n", exclude_wcs[imatch], key);
                                // These don't really need to appear in the output file...
                                /*
                                snprintf(newkey, FITS_LINESZ+1, "Original WCS key: \"%s\"", key);
                                qfits_header_append(outhdr, "COMMENT", newkey, NULL, NULL);
                                snprintf(newkey, FITS_LINESZ+1, "_%.7s", key);
                                strcpy(key, newkey);
                                */
                                continue;
                            }
                            ......
                        }
                        ......
                        if (copydata) {
                            ......
                            logverb("Copying from offset %i to offset %i (length %i) of the input file to the output.\n",
                                    datstart, datstart + datsize, datsize);
                            ......
                        }


                    }


                }
            }  
        }
    }
}