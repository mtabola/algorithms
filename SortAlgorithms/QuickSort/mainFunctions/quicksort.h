#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../../../addCustFunc/addCustFunc.h"

void quicksort(int* arr, int min, int max);
static int partition(int* arr, int min, int max);
