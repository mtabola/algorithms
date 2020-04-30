#include "mainFunctions/quicksort.h"

#define SIZE 16

int main()
{
    int* arr = getRandFillArr(SIZE, -20, 40);

    printArr("Before ", arr, SIZE);

    quicksort(arr, 0, SIZE - 1);

    printArr("After ", arr, SIZE);
    return 0;
}