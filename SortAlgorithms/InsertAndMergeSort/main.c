#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertionSort.h"
#include "mergeSort.h"
#include "addCustFunc.h"

const size_t size = 10;

int main(int argc, char** argv)
{
    int* sortArr = getRandFillArr(size);

    printArr("Array before sorting", sortArr, size);

    mergeSort(sortArr, 0, size - 1);

    printArr("Array after sorting", sortArr, size);

    free(sortArr);

    system("pause");

    return 0;
}