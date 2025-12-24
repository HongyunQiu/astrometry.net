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

// 3-way partition (Dutch national flag): partitions arr[left..right] into
//   [left..lt-1] < pivot, [lt..gt] == pivot, [gt+1..right] > pivot
// This avoids quickselect degeneration when there are many values equal to the pivot
// (common in quantized / low-dynamic-range / low-SNR images).
static void dselip_partition3(float* arr, size_t left, size_t right, float pivot_value,
                             size_t* out_lt, size_t* out_gt) {
    size_t lt = left;
    size_t i  = left;
    size_t gt = right;

    while (i <= gt) {
        const float v = arr[i];
        if (v < pivot_value) {
            DSELIP_SWAP(arr[lt], arr[i]);
            lt++;
            i++;
        } else if (v > pivot_value) {
            DSELIP_SWAP(arr[i], arr[gt]);
            if (gt == 0)
                break;
            gt--;
            // don't advance i: swapped-in element from the right is unclassified
        } else {
            i++;
        }
    }
    *out_lt = lt;
    *out_gt = gt;
}

static float dselip_select_kth(float* arr, size_t n, size_t k) {
    // Iterative quickselect. Returns the kth smallest element (0-based).
    // Uses 3-way partitioning to keep performance robust when many values are equal.
    size_t left = 0;
    size_t right = n - 1;

    while (1) {
        if (left == right)
            return arr[left];

        size_t mid = left + (right - left) / 2;
        size_t pivot_i = dselip_median3_index(arr, left, mid, right);
        const float pivot_value = arr[pivot_i];

        size_t lt, gt;
        dselip_partition3(arr, left, right, pivot_value, &lt, &gt);

        if (k < lt) {
            if (lt == 0)
                return arr[0];
            right = lt - 1;
        } else if (k > gt) {
            left = gt + 1;
        } else {
            // k is within the "equal to pivot" band
            return pivot_value;
        }
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
