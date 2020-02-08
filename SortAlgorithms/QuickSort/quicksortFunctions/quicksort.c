#include "quicksort.h"
#include <stdlib.h>


void quicksort(int* arr, int min, int max)
{
    if (min < max)
    {
        int mid = partition(arr, min, max);
        quicksort(arr, min, mid - 1);
        quicksort(arr, mid + 1, max);
    }
}

int partition(int* arr, int min, int max)
{
    int x = arr[max];
    int i = min - 1;
    for (size_t j = min; j <= max - 1; j++)
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