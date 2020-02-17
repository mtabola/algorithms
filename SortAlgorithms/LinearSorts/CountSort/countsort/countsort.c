#include "countsort.h"

void countSort(int* inArr, size_t inArrSize)
{
    int max = findMaxElem(inArr, inArrSize);


    int* outArr = calloc(inArrSize, sizeof(int));
    int* countArr = calloc(max + 1, sizeof(int));

    memset(countArr, 0, max + 1);

    for (size_t i = 0; i < inArrSize; i++)
        countArr[inArr[i]] += 1;

    for (size_t i = 1; i <= max; i++)
        countArr[i] += countArr[i - 1];

    for (int i = inArrSize - 1; i >= 0; i--)
    {
        outArr[countArr[inArr[i]] - 1] = inArr[i];
        countArr[inArr[i]]-= 1;
    }

    for (int i = 0; i < inArrSize; i++)
        inArr[i] = outArr[i];

    free(countArr);
    free(outArr);
}