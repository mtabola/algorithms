#pragma once
#include <assert.h>
#include <stdlib.h>

#include "../../../addCustFunc/addCustFunc.h"

typedef struct _heapStruct
{
    int* intArr;
    size_t arrSize;
    size_t heapSize;
} heap;



size_t getParent(size_t i);
size_t getLeft(size_t i);
size_t getRight(size_t i);
void exchangeElements(int* arr, size_t i, size_t j);



void maxHeapify(heap* node, size_t i);
void buildMaxHeap(heap* node);
void heapsort(heap* node);
