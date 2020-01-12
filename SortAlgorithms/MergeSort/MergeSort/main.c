#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "mergeSort.h"
#include "addCustFunc.h"

#define SIZE 10

int main(int argc, char** argv) 
{
    int* sortArr = getRandFillArr(SIZE);

    printArr("Array before sorting", sortArr, SIZE);
    
    mergeSort(sortArr, 0, SIZE - 1);    

    printArr("Array after sorting", sortArr, SIZE);

    free(sortArr);

    system("pause");
    return 0;
}