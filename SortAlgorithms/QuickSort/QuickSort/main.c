#include <stdio.h>
#include <stdlib.h>

#include "quicksortFunctions/quicksort.h"

#define SIZE 8

int main()
{
    int a[SIZE] = {2, 8, 7, 1, 3, 5, 6, 4};
    int* arr = a;//getRandFillArr(SIZE, -10, 10);

    printArr("Before ", arr, SIZE);

    partition(arr, 0, SIZE - 1);

    printArr("After ", arr, SIZE);
    return 0;
}