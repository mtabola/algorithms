#include "quicksort.h"
#include <stdlib.h>


void quicksort(int* arr, size_t min, size_t max)
{
    if (min < max)
    {
        size_t mid = partition(arr, min, max);
        quicksort(arr, min, mid - 1);
        quicksort(arr, mid + 1, max);
    }
}

int partition(int* arr, size_t min, size_t max)
{
    int x = arr[max];
    size_t i = min - 1;
    for (size_t j = min; j < max - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            exchangeElements(arr, i, j);
        }
    }
    exchangeElements(arr, i + 1, max);
    return i + 1;
}