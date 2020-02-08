#include <stdio.h>
#include <stdlib.h>
#include "../../addCustFunc/addCustFunc.h"
#include "heapsortFunctions/heapsort.h"

#define SIZE 16

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

    heapsort(&node);

    printArr("After ", node.intArr, node.arrSize);

    return 0;
}