/*
 # This file is part of the Astrometry.net suite.
 # Licensed under a 3-clause BSD style license - see LICENSE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

// for compare_floats_asc
#include "permutedsort.h"
// for QSORT_R
#include "os-features.h"
#include "an-bool.h"

#define DSELIP_SWAP(a,b) do { float _t = (a); (a) = (b); (b) = _t; } while (0)

static anbool g_dselip_use_qsort = FALSE;

void dselip_set_use_qsort(anbool use_qsort) {
    g_dselip_use_qsort = use_qsort;
}

static size_t dselip_median3_index(const float* arr, size_t a, size_t b, size_t c) {
    // Return the index of the median of arr[a], arr[b], arr[c].
    const float va = arr[a];
    const float vb = arr[b];
    const float vc = arr[c];
    // Assumes no NaNs (callers filter non-finite values).
    if (va < vb) {
        if (vb < vc)
            return b;           // va < vb < vc
        if (va < vc)
            return c;           // va < vc <= vb
        return a;               // vc <= va < vb
    } else {
        if (va < vc)
            return a;           // vb <= va < vc
        if (vb < vc)
            return c;           // vb < vc <= va
        return b;               // vc <= vb <= va
    }
}

static size_t dselip_partition(float* arr, size_t left, size_t right, size_t pivot_index) {
    const float pivot_value = arr[pivot_index];
    size_t store_index = left;

    // move pivot to end
    DSELIP_SWAP(arr[pivot_index], arr[right]);
    for (size_t i = left; i < right; i++) {
        if (arr[i] < pivot_value) {
            DSELIP_SWAP(arr[store_index], arr[i]);
            store_index++;
        }
    }
    // move pivot to its final place
    DSELIP_SWAP(arr[right], arr[store_index]);
    return store_index;
}

static float dselip_select_kth(float* arr, size_t n, size_t k) {
    // Iterative quickselect. Returns the kth smallest element (0-based).
    size_t left = 0;
    size_t right = n - 1;

    while (1) {
        if (left == right)
            return arr[left];

        size_t mid = left + (right - left) / 2;
        size_t pivot_index = dselip_median3_index(arr, left, mid, right);
        pivot_index = dselip_partition(arr, left, right, pivot_index);

        if (k == pivot_index)
            return arr[k];
        if (k < pivot_index)
            right = pivot_index - 1;
        else
            left = pivot_index + 1;
    }
}

#ifdef SIMPLEXY_REENTRANT

// this is slower, because each call needs to malloc, but it is reentrant
float dselip(unsigned long k, unsigned long n, const float *arr) {
    float* sorted_data = malloc(sizeof(float) * n);
    memcpy(sorted_data, arr, sizeof(float)*n);
    assert(k < n);
    float kth_item;
    if (g_dselip_use_qsort) {
        QSORT_R(sorted_data, n, sizeof(float), NULL, compare_floats_asc_r);
        kth_item = sorted_data[k];
    } else {
        kth_item = dselip_select_kth(sorted_data, (size_t)n, (size_t)k);
    }
    free(sorted_data);
    return kth_item;
}

void dselip_cleanup() {
}

#else

static int high_water_mark = 0;
static float* past_data = NULL;

float dselip(unsigned long k, unsigned long n, float *arr) {
    if (n > high_water_mark) {
        free(past_data);
        past_data = malloc(sizeof(float) * n);
        high_water_mark = n;
        //printf("dselip watermark=%lu\n",n);
    }
    memcpy(past_data, arr, sizeof(float) * n);
    assert(k < n);
    if (g_dselip_use_qsort) {
        qsort(past_data, n, sizeof(float), compare_floats_asc);
        return past_data[k];
    }
    return dselip_select_kth(past_data, (size_t)n, (size_t)k);
}

void dselip_cleanup() {
    free(past_data);
    past_data = NULL;
    high_water_mark = 0;
}

#endif
