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
    arr[j] = tmp;
}



void maxHeapify(heap* node, size_t i)
{
    size_t right = getRight(i);
    size_t left = getLeft(i);
    size_t largest = i;

    if (left <= node->heapSize && node->intArr[i] < node->intArr[left])
        largest = left;
    else if (right <= node->heapSize && node->intArr[i] < node->intArr[right])
        largest = right;
    
    if (largest != i)
    { 
        exchangeElements(node->intArr, i, largest);
        maxHeapify(node, largest);
    }
}


void buildMaxHeap(heap* node)
{
    node->heapSize = node->arrSize;
    for (size_t i = (size_t)ceil(node->arrSize / 2); i > 0; i--)
        maxHeapify(node, i);
}


void heapsort(heap* node)
{
   
}
