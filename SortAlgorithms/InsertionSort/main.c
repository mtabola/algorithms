#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertionSort.h"
#include "addCustFunc.h"




int main(int argc, char** argv) 
{
    srand(time(NULL));
    
    int size = 0;
    
    printf("Please, enter array size: ");
    scanf("%d", &size);

    int* sortArr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        sortArr[i] = (rand() % (size + 1));
    
    printArr("Entering array:", sortArr, size);

    sortArr = insertSort(sortArr, size);

    printArr("Outgoing array:", sortArr, size);

    return 0;
}