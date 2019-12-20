#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "mergeSort.h"
#include "addCustFunc.h"


int main(int argc, char** argv) 
{
    int* sortArr = NULL;
    int size = 0;

    int minPos = 0;
    int maxPos = 0;

    printf("Please, enter array size: ");
    scanf("%d", &size);

    sortArr = getRandFillArr(size);

    printArr("Array before sorting", sortArr, size);
    
    mergeSort(sortArr, 0, size - 1);    

    printArr("Array after sorting", sortArr, size);

    free(sortArr);

    system("pause");
    return 0;
}