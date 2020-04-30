/*Count sort*/

#include <stdio.h>
#include <stdlib.h>
#include "countsort/countsort.h"

#include "../../addCustFunc/addCustFunc.h"

#define SIZE 16

int main()
{
    int* arr = getRandFillArr(SIZE, 0, 20);
    printArr("In array: ", arr, SIZE);
    
    countSort(arr, SIZE);

    printArr("Out array: ", arr, SIZE);


    free(arr);


    return 0;
}
