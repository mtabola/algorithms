#pragma once
#include <assert.h>
#include <stdlib.h>

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



void maxHeapify(int* arr, size_t i);
void buildMaxHeap(int* arr);
void heapsort(int* arr);
