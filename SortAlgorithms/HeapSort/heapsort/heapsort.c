#include "heapSort.h"
#include <math.h>

size_t getParent(size_t i)
{
    return (size_t) ceil(i / 2);
}

size_t getLeft(size_t i)
{
    return (size_t)(2 * i + 1);
}

size_t getRight(size_t i)
{
    return (size_t)(2 * i + 2);
}

void exchangeElements(int* arr, size_t i, size_t j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = arr[i];
}



void maxHeapify(int* arr, size_t i)
{
    size_t right = getRight(i);
    size_t left = getLeft(i);

}
void buildMaxHeap(int* arr)
{

}


void heapsort(int* arr)
{

}
