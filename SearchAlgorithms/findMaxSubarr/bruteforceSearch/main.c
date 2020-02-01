#include <stdlib.h>
#include <stdio.h>
#include "bruteforce.h"
#include "../../../addCustFunc/addCustFunc.h"

#define SIZE 16

int main(int argc, char** argv)
{    
    int* arr = getRandFillArr(SIZE, -20, 20);
    printArr("Input array: ", arr, SIZE);

    subarrData maxSubarr = brutforceFind(arr, 0, SIZE - 1);

    printf("Max sum = %d, started with - %d, ending with - %d\n", maxSubarr.sum, maxSubarr.begPos, maxSubarr.endPos);

    return 0;
}