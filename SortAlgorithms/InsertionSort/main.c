#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mainFunctions/insertionSort.h"
#include "../../addCustFunc/addCustFunc.h"




int main(int argc, char** argv)
{
    srand(time(NULL));

    size_t size = 0;

    printf("Please, enter array size: ");
    scanf("%d", &size);

    int* sortArr = getRandFillArr(size, -50, 50);

    printArr("Entering array:", sortArr, size);

    sortArr = insertSort(sortArr, size);

    printArr("Outgoing array:", sortArr, size);

    free(sortArr);

    return 0;
}