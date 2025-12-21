/*
 # This file is part of the Astrometry.net suite.
 # Licensed under a 3-clause BSD style license - see LICENSE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "keywords.h"
#include "dimage.h"
#include "permutedsort.h"
#include "simplexy-common.h"
#include "log.h"
#include "tic.h"

/*
 * dpeaks.c
 *
 * Find peaks in an image, for the purposes of deblending children.
 *
 * Mike Blanton
 * 1/2006 */

static anbool g_dpeaks_use_dfind2 = FALSE;

void dpeaks_set_use_dfind2(anbool use_dfind2) {
    g_dpeaks_use_dfind2 = use_dfind2;
}

typedef struct {
    const float* smooth;
} dpeaks_cmp_ctx_t;

static dpeaks_cmp_ctx_t g_dpeaks_cmp_ctx;

static int cmp_pix_desc_by_smooth(const void* v1, const void* v2) {
    int i1 = *(const int*)v1;
    int i2 = *(const int*)v2;
    float a = g_dpeaks_cmp_ctx.smooth[i1];
    float b = g_dpeaks_cmp_ctx.smooth[i2];
    // Descending by value.
    return (a < b) ? 1 : ((a > b) ? -1 : 0);
}

typedef struct {
    const double* level;
} dpeaks_level_cmp_ctx_t;

static dpeaks_level_cmp_ctx_t g_dpeaks_level_ctx;

static int cmp_peak_desc_by_level(const void* v1, const void* v2) {
    int p1 = *(const int*)v1;
    int p2 = *(const int*)v2;
    double a = g_dpeaks_level_ctx.level[p1];
    double b = g_dpeaks_level_ctx.level[p2];
    // Descending by level.
    return (a < b) ? 1 : ((a > b) ? -1 : 0);
}

static inline int uf_find(int* parent, int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

static inline void uf_union(int* parent, uint8_t* rank, int* bestpeak, int a, int b) {
    int ra = uf_find(parent, a);
    int rb = uf_find(parent, b);
    if (ra == rb)
        return;
    if (rank[ra] < rank[rb]) {
        int tmp = ra;
        ra = rb;
        rb = tmp;
    }
    parent[rb] = ra;
    if (rank[ra] == rank[rb])
        rank[ra]++;
    // Merge best peak index (min).
    if (bestpeak[rb] < bestpeak[ra])
        bestpeak[ra] = bestpeak[rb];
}

int dpeaks(float *image,
           int nx,
           int ny,
           int *npeaks,
           int *xcen,
           int *ycen,
           float sigma,    /* sky sigma */
           float dlim,     /* limiting distance */
           float saddle,   /* number of sigma for allowed saddle */
           int maxnpeaks,
           int smoothimage,
           int checkpeaks,
           float minpeak)
{
    double t_dpeaks0 = timenow();
    double dt_smooth = 0.0;
    double dt_findpeaks = 0.0;
    double dt_sort = 0.0;
    double dt_check_mask = 0.0;
    double dt_check_dfind = 0.0;
    double dt_check_join = 0.0;
    double dt_close = 0.0;
    double dt_check_fast_sortpix = 0.0;
    double dt_check_fast_process = 0.0;
    const double log_stage_thresh = 0.050;
    int i, j, ip, jp, ist, jst, ind, jnd, highest, tmpnpeaks;
    float dx, dy, level;
        
    float *smooth = NULL;
    int *peaks = NULL;
    int *indx = NULL;
    int *object = NULL;
    int *keep = NULL;
    int *mask = NULL;
    int *fullxcen = NULL;
    int *fullycen = NULL;

    /* 1. smooth image */
    smooth = (float *) malloc(sizeof(float) * nx * ny);
    if (smoothimage) {
        double t0 = timenow();
        dsmooth2(image, nx, ny, 1, smooth);
        dt_smooth += timenow() - t0;
    } else {
        double t0 = timenow();
        for (j = 0;j < ny;j++)
            for (i = 0;i < nx;i++)
                smooth[i + j*nx] = image[i + j*nx];
        dt_smooth += timenow() - t0;
    }

    /* 2. find peaks (highest in the 3x3 neighbourhood) */
    peaks = (int *) malloc(sizeof(int) * nx * ny);
    *npeaks = 0;
    {
        double t0 = timenow();
    for (j = 1; j < ny - 1; j++) {
        jst = j - 1;
        jnd = j + 1;
        for (i = 1; i < nx - 1; i++) {
            if (smooth[i + j*nx] < minpeak)
                continue;
            ist = i - 1;
            ind = i + 1;
            highest = 1;
            for (ip = ist; ip <= ind; ip++)
                for (jp = jst; jp <= jnd; jp++)
                    if (smooth[ip + jp*nx] > smooth[i + j*nx])
                        highest = 0;
            if (highest) {
                peaks[*npeaks] = i + j * nx;
                (*npeaks)++;
            }
        }
    }
        dt_findpeaks += timenow() - t0;
    }

    // DEBUG
    for (i=0; i<(*npeaks); i++) {
        Unused float pk = smooth[peaks[i]];
        assert((peaks[i] % nx) >= 1);
        assert((peaks[i] % nx) <= (nx-2));
        assert((peaks[i] / nx) >= 1);
        assert((peaks[i] / nx) <= (ny-2));
        assert(pk >= minpeak);
        assert(pk >= smooth[peaks[i]-1]);
        assert(pk >= smooth[peaks[i]+1]);
        assert(pk >= smooth[peaks[i]-nx]);
        assert(pk >= smooth[peaks[i]+nx]);
        assert(pk >= smooth[peaks[i]+nx+1]);
        assert(pk >= smooth[peaks[i]+nx-1]);
        assert(pk >= smooth[peaks[i]-nx+1]);
        assert(pk >= smooth[peaks[i]-nx-1]);
    }

    /* 2. sort peaks */
    indx = realloc(peaks, sizeof(int) * (*npeaks));
    peaks = NULL;
    {
        double t0 = timenow();
    permuted_sort(smooth, sizeof(float), compare_floats_desc, indx, *npeaks);
        dt_sort += timenow() - t0;
    }

    // DEBUG
    for (i=0; i<(*npeaks); i++) {
        Unused float pk = smooth[indx[i]];
        assert((indx[i] % nx) >= 1);
        assert((indx[i] % nx) <= (nx-2));
        assert((indx[i] / nx) >= 1);
        assert((indx[i] / nx) <= (ny-2));
        assert(pk >= minpeak);
        assert(pk >= smooth[indx[i]-1]);
        assert(pk >= smooth[indx[i]+1]);
        assert(pk >= smooth[indx[i]-nx]);
        assert(pk >= smooth[indx[i]+nx]);
        assert(pk >= smooth[indx[i]+nx+1]);
        assert(pk >= smooth[indx[i]+nx-1]);
        assert(pk >= smooth[indx[i]-nx+1]);
        assert(pk >= smooth[indx[i]-nx-1]);
    }
    for (i=1; i<(*npeaks); i++) {
        assert(smooth[indx[i-1]] >= smooth[indx[i]]);
    }

    if ((*npeaks) > maxnpeaks)
        *npeaks = maxnpeaks;

    fullxcen = (int *) malloc((*npeaks) * sizeof(int));
    fullycen = (int *) malloc((*npeaks) * sizeof(int));
    for (i = 0;i < (*npeaks);i++) {
        fullxcen[i] = indx[i] % nx;
        fullycen[i] = indx[i] / nx;
    }
    FREEVEC(indx);

    // DEBUG
    for (i = 0;i < (*npeaks);i++) {
        assert(fullxcen[i] >= 1);
        assert(fullxcen[i] <= nx-2);
        assert(fullycen[i] >= 1);
        assert(fullycen[i] <= ny-2);
    }


    /* 3. trim close peaks and joined peaks */
    keep = (int *) malloc(sizeof(int) * (*npeaks));

    // Fast checkpeaks results: whether peak i is connected (above its saddle level)
    // to any brighter peak.
    uint8_t* connected_to_brighter = NULL;
    anbool use_fast_check = (checkpeaks && !g_dpeaks_use_dfind2);

    if (checkpeaks && !use_fast_check) {
        mask = (int *) malloc(sizeof(int) * nx * ny);
        object = (int *) malloc(sizeof(int) * nx * ny);
    }

    if (use_fast_check) {
        int N = nx * ny;
        int* pix_order = NULL;
        uint8_t* active = NULL;
        int* parent = NULL;
        uint8_t* rank = NULL;
        int* bestpeak = NULL;
        int* peak_at_pix = NULL;
        double* levels = NULL;
        int* peak_by_level = NULL;
        int pidx = 0;
        int INF = 0x3fffffff;
        double t0;

        connected_to_brighter = (uint8_t*)calloc((size_t)(*npeaks), 1);
        peak_at_pix = (int*)malloc((size_t)N * sizeof(int));
        levels = (double*)malloc((size_t)(*npeaks) * sizeof(double));
        peak_by_level = (int*)malloc((size_t)(*npeaks) * sizeof(int));
        pix_order = (int*)malloc((size_t)N * sizeof(int));
        active = (uint8_t*)calloc((size_t)N, 1);
        parent = (int*)malloc((size_t)N * sizeof(int));
        rank = (uint8_t*)calloc((size_t)N, 1);
        bestpeak = (int*)malloc((size_t)N * sizeof(int));

        // Init arrays
        for (i = 0; i < N; i++) {
            pix_order[i] = i;
            peak_at_pix[i] = INF;
            parent[i] = i;
            bestpeak[i] = INF;
        }

        // Peak pixel mapping + per-peak level
        for (i = 0; i < (*npeaks); i++) {
            int pix = fullxcen[i] + fullycen[i] * nx;
            float pk = smooth[pix];
            double lv = (double)pk - (double)saddle * (double)sigma;
            if (lv < (double)sigma)
                lv = (double)sigma;
            if (lv > 0.99 * (double)pk)
                lv = 0.99 * (double)pk;
            levels[i] = lv;
            peak_by_level[i] = i;
            if (i < peak_at_pix[pix])
                peak_at_pix[pix] = i;
        }

        // Sort pixels by smooth value (desc)
        t0 = timenow();
        g_dpeaks_cmp_ctx.smooth = smooth;
        qsort(pix_order, (size_t)N, sizeof(int), cmp_pix_desc_by_smooth);
        dt_check_fast_sortpix += timenow() - t0;

        // Sort peaks by level (desc)
        g_dpeaks_level_ctx.level = levels;
        qsort(peak_by_level, (size_t)(*npeaks), sizeof(int), cmp_peak_desc_by_level);

        // Activate pixels in descending smooth value; union 8-connected neighbors.
        t0 = timenow();
        for (j = 0; j < (*npeaks); j++) {
            int pi = peak_by_level[j];
            double thr = levels[pi];
            while (pidx < N && (double)smooth[pix_order[pidx]] > thr) {
                int pix = pix_order[pidx];
                int x = pix % nx;
                int y = pix / nx;
                active[pix] = 1;
                parent[pix] = pix;
                rank[pix] = 0;
                bestpeak[pix] = peak_at_pix[pix];

                // Union with active neighbors (8-connected).
                for (jp = -1; jp <= 1; jp++) {
                    int yy = y + jp;
                    if (yy < 0 || yy >= ny)
                        continue;
                    for (ip = -1; ip <= 1; ip++) {
                        int xx = x + ip;
                        int npix;
                        if (ip == 0 && jp == 0)
                            continue;
                        if (xx < 0 || xx >= nx)
                            continue;
                        npix = xx + yy * nx;
                        if (active[npix])
                            uf_union(parent, rank, bestpeak, pix, npix);
                    }
                }
                pidx++;
            }
            // Query connectivity for this peak at its threshold.
            {
                int ppix = fullxcen[pi] + fullycen[pi] * nx;
                int root;
                // Peak pixel should always be active since smooth[ppix] > level[pi].
                if (!active[ppix]) {
                    // Defensive: treat as connected-to-nothing (legacy would see object == -1 -> drop).
                    connected_to_brighter[pi] = 1;
                } else {
                    root = uf_find(parent, ppix);
                    connected_to_brighter[pi] = (bestpeak[root] < pi) ? 1 : 0;
                }
            }
        }
        dt_check_fast_process += timenow() - t0;

        free(pix_order);
        free(active);
        free(parent);
        free(rank);
        free(bestpeak);
        free(peak_at_pix);
        free(levels);
        free(peak_by_level);
    }

    for (i = (*npeaks) - 1;i >= 0;i--) {
        keep[i] = 1;

        if (checkpeaks) {
            if (use_fast_check) {
                if (connected_to_brighter && connected_to_brighter[i])
                    keep[i] = 0;
            } else {
                /* look for peaks joined by a high saddle to brighter peaks */
                level = (smooth[ fullxcen[i] + fullycen[i] * nx] - saddle * sigma);
                if (level < sigma)
                    level = sigma;
                if (level > 0.99*smooth[ fullxcen[i] + fullycen[i] * nx])
                    level= 0.99*smooth[ fullxcen[i] + fullycen[i] * nx];
                {
                    double t0 = timenow();
                    for (jp = 0;jp < ny;jp++)
                        for (ip = 0;ip < nx;ip++)
                            mask[ip + jp*nx] = smooth[ip + jp * nx] > level;
                    dt_check_mask += timenow() - t0;
                }
                {
                    double t0 = timenow();
                    dfind2(mask, nx, ny, object, NULL);
                    dt_check_dfind += timenow() - t0;
                }
                {
                    double t0 = timenow();
                    for (j = i - 1;j >= 0;j--)
                        if (object[ fullxcen[j] + fullycen[j]*nx] ==
                            object[ fullxcen[i] + fullycen[i]*nx] ||
                            object[ fullxcen[i] + fullycen[i]*nx] == -1 ) {
                            keep[i] = 0;
                        }
                    dt_check_join += timenow() - t0;
                }
            }
        }

        /* look for close peaks */
        {
            double t0 = timenow();
        for (j = i - 1;j >= 0;j--) {
            dx = (float)(fullxcen[j] - fullxcen[i]);
            dy = (float)(fullycen[j] - fullycen[i]);
            if (dx*dx + dy*dy < dlim*dlim)
                keep[i] = 0;
        }
            dt_close += timenow() - t0;
        }
    }

    // Grab just the keepers.
    tmpnpeaks = 0;
    for (i=0; i < (*npeaks); i++) {
        if (!keep[i])
            continue;
        xcen[tmpnpeaks] = fullxcen[i];
        ycen[tmpnpeaks] = fullycen[i];
        tmpnpeaks++;
        if (tmpnpeaks >= maxnpeaks)
            break;
    }
    (*npeaks) = tmpnpeaks;

    FREEVEC(smooth);
    FREEVEC(keep);
    FREEVEC(object);
    FREEVEC(mask);
    FREEVEC(fullxcen);
    FREEVEC(fullycen);
    FREEVEC(connected_to_brighter);

    {
        double dt_total = timenow() - t_dpeaks0;
        if (dt_total > log_stage_thresh) {
            if (use_fast_check) {
                logverb("dpeaks: timing nx=%i ny=%i npeaks=%i smoothimage=%i checkpeaks=%i total %.3f s; smooth/copy %.3f s; findpeaks %.3f s; sort %.3f s; check(uf sortpix) %.3f s; check(uf process) %.3f s; close %.3f s\n",
                        nx, ny, *npeaks, smoothimage, checkpeaks, dt_total,
                        dt_smooth, dt_findpeaks, dt_sort, dt_check_fast_sortpix, dt_check_fast_process, dt_close);
            } else {
                logverb("dpeaks: timing nx=%i ny=%i npeaks=%i smoothimage=%i checkpeaks=%i total %.3f s; smooth/copy %.3f s; findpeaks %.3f s; sort %.3f s; check(mask) %.3f s; check(dfind2) %.3f s; check(join) %.3f s; close %.3f s\n",
                    nx, ny, *npeaks, smoothimage, checkpeaks, dt_total,
                    dt_smooth, dt_findpeaks, dt_sort, dt_check_mask, dt_check_dfind, dt_check_join, dt_close);
            }
        }
    }
    return (1);
} /* end dpeaks */
