/*
 # This file is part of the Astrometry.net suite.
 # Licensed under a 3-clause BSD style license - see LICENSE
 */

#ifndef DIMAGE_H
#define DIMAGE_H

#include <stdint.h>
#include "astrometry/an-bool.h"

// this is only really included here so that it can be tested :)
typedef int32_t dimage_label_t;
#define LABEL_MAX INT32_MAX

dimage_label_t collapsing_find_minlabel(dimage_label_t label, dimage_label_t *equivs);

int dfind2(const int* image, int nx, int ny, int* objectimg, int* p_nobjects);
int dfind2_u8(const unsigned char* image, int nx, int ny, int* objectimg, int* p_nobjects);

float dselip(unsigned long k, unsigned long n, const float *arr);
void dselip_cleanup(void);
// For benchmarking/validation: choose selection method used by dselip().
// Default is FALSE (use quickselect-style selection). TRUE forces legacy full-sort (qsort/QSORT_R).
void dselip_set_use_qsort(anbool use_qsort);

int dsmooth(float *image, int nx, int ny, float sigma, float *smooth);

void dsmooth2(float *image, int nx, int ny, float sigma, float *smooth);
void dsmooth2_u8(uint8_t *image, int nx, int ny, float sigma, float *smooth);
void dsmooth2_i16(int16_t *image, int nx, int ny, float sigma, float *smooth);

int dobjects(float *image, int nx, int ny, float limit,
             float dpsf, int *objects);

int dmask(float *image, int nx, int ny, float limit,
          float dpsf, uint8_t* mask);

int dpeaks(float *image, int nx, int ny, int *npeaks, int *xcen,
           int *ycen, float sigma, float dlim, float saddle, int maxnpeaks,
           int smooth, int checkpeaks, float minpeak);

// For benchmarking/validation: choose checkpeaks implementation in dpeaks().
// Default is FALSE (use faster union-find based check). TRUE forces legacy per-peak dfind2().
void dpeaks_set_use_dfind2(anbool use_dfind2);

int dcen3x3(float *image, float *xcen, float *ycen);

int dsigma(float *image, int nx, int ny, int sp, int gridsize, float *sigma);
int dsigma_u8(uint8_t *image, int nx, int ny, int sp, int gridsize, float *sigma);

int dmedsmooth(const float *image, const uint8_t *masked,
               int nx, int ny, int halfbox, float *smooth);

int dallpeaks(float *image, int nx, int ny, int *objects, float *xcen,
              float *ycen, int *npeaks, float dpsf, float sigma,
              float dlim, float saddle,
              int maxper, int maxnpeaks, float minpeak, int maxsize);
int dallpeaks_u8(uint8_t *image, int nx, int ny, int *objects, float *xcen,
                 float *ycen, int *npeaks, float dpsf, float sigma,
                 float dlim, float saddle,
                 int maxper, int maxnpeaks, float minpeak, int maxsize);
int dallpeaks_i16(int16_t *image, int nx, int ny, int *objects, float *xcen,
                  float *ycen, int *npeaks, float dpsf, float sigma,
                  float dlim, float saddle,
                  int maxper, int maxnpeaks, float minpeak, int maxsize);

#endif
