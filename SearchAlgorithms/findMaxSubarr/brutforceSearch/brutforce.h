#pragma once
#include <stdlib.h>
#include <stdio.h>


typedef struct _SUBARR_DATA
{
    size_t begPos, endPos;
    int sum;
}subarrData;

subarrData brutforceFind(int* arr, size_t begPos, size_t endPos, int step);
