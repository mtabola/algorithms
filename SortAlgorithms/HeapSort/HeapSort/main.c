#include <stdio.h>
#include <stdlib.h>
#include "../../../addCustFunc/addCustFunc.h"
#include "heapsort/heapSort.h"

#define SIZE 10

void heapFill(heap* node)
{
    node->intArr = getRandFillArr(SIZE, 0, 50);
    node->arrSize = SIZE;
    node->heapSize = 0;
}




int main(int argc, char** argv)
{
    heap node;
    heapFill(&node, 0);

    printArr("Before ", node.intArr, node.arrSize);

    buildMaxHeap(&node);

    printArr("After ", node.intArr, node.arrSize);

    

    return 0;
}