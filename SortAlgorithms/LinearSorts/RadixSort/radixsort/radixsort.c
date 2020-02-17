#include "radixsort.h"

void countSort(int* inArr, size_t inArrSize, int exp)
{
    int max = findMaxElem(inArr, inArrSize);


    int* outArr = calloc(inArrSize, sizeof(int));
    int countArr[10] = {0};

    for (size_t i = 0; i < inArrSize; i++)
        countArr[(inArr[i]/exp) % 10]++;

    for (size_t i = 1; i < 10; i++)
        countArr[i] += countArr[i - 1];

    for (int i = inArrSize - 1; i >= 0; i--)
    {
        outArr[countArr[(inArr[i] / exp) % 10] - 1] = inArr[i];
        countArr[(inArr[i] / exp) % 10]--;
    }

    for (int i = 0; i < inArrSize; i++)
        inArr[i] = outArr[i];

    free(outArr);
}




int* radixSort(int* inpArr, size_t size)
{
    int max = findMaxElem(inpArr, size);

    for (int exp = 1; max/exp > 0; exp *= 10)
    {
        countSort(inpArr, size, exp);
    }
}