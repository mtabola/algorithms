#include "addCustFunc.h"


void printArr(char* txt, int* arr, size_t arrSize)
{
    printf("%s ", txt);
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int* getRandFillArr(size_t size, int min, int max) {
    srand(time(NULL));

    int* sortArr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        sortArr[i] = min + (rand() % (max - min));
    }

    return sortArr;
}