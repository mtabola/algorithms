#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


typedef struct _SUBARR_DATA
{
    size_t left,
           right;
    int sum;
}subarrData_t;

subarrData_t findMaxCrossingSubarr(int* arr, size_t low, size_t mid, size_t high);
subarrData_t findMaxSubarr(int* arr, size_t low, size_t high);

