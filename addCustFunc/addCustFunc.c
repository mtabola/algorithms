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

    assert(!(sortArr == NULL));

    for (int i = 0; i < size; i++)
    {
        sortArr[i] = min + (rand() % (max - min));
    }
    return sortArr;
}


void exchangeElements(int* arr, int i, int j)
{
    if (i == j)
        return;

    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int findMaxElem(int* arr, size_t arrSize)
{
    int maxElem = arr[0];
    for (size_t i = 1; i < arrSize; i++)
        if (arr[i] > maxElem)
            maxElem = arr[i];
    return maxElem;
}


int findMaxGrade(int* inpArr, size_t size)
{
    int i = 0;

    while (true)
    {
        int zeroCounter = 0;
        int currentGrade = (int)pow(10, i);

        for (int j = 0; j < size; j++)
        {
            if ((inpArr[j] / currentGrade) == 0)
                zeroCounter++;
        }
        if (zeroCounter == size)
            break;
        i++;
    }

    return i - 1;
}