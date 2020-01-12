#include <stdlib.h>
#include <stdio.h>
#include "brutforce.h"
#include "addCustFunc/addCustFunc.h"

#define SIZE 16

int main(int argc, char** argv)
{    
    int* arr = getRandFillArr(SIZE, -10, 10);
    printArr("Input array: ", arr, SIZE);

    subarrData maxSubarr = brutforceFind(arr, 0, SIZE - 1, 4);

    printf("Max sum = %d, started with - %d, ending with - %d\n", maxSubarr.sum, maxSubarr.begPos, maxSubarr.endPos);

    return 0;
}