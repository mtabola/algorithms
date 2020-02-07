#include "heapSort.h"
#include <math.h>

size_t getParent(size_t i)
{
    return (size_t)ceil(i / 2);
}

size_t getLeft(size_t i)
{
    return (size_t)(2 * i + 1);
}

size_t getRight(size_t i)
{
    return (size_t)(2 * i + 2);
}




void maxHeapify(heap* node, size_t i)
{
    size_t left = getLeft(i);
    size_t right = getRight(i);
    size_t largest = i;

    if (left < node->heapSize && node->intArr[i] < node->intArr[left])
        largest = left;

    if (right < node->heapSize && node->intArr[largest] < node->intArr[right])
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
    for (int i = (int)ceil((node->arrSize - 1) / 2); i >= 0; i--)
        maxHeapify(node, (size_t)i);
}


void heapsort(heap* node)
{
    buildMaxHeap(node);
    for (size_t i = (size_t)node->arrSize - 1; i >= 1; i--)
    {
        exchangeElements(node->intArr, 0, i);
        node->heapSize--;
        maxHeapify(node, 0);
    }
}