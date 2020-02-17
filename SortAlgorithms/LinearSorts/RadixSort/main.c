#include "radixsort/radixsort.h"

#define SIZE 16


int main()
{
    int* arr = getRandFillArr(SIZE, 0, 50);
    
    printArr("Before:", arr, SIZE);
    
    radixSort(arr, SIZE);

    printArr("After:", arr, SIZE);

    return 0;
}