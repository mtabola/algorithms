#pragma once

void* insertSort(int* sortArr, int size) 
{
    for (int i = 1; i < size; i++)
    {
        int key = sortArr[i];
        int j = i - 1;
        while ((j >= 0) && (sortArr[j] > key))
        {
            sortArr[j + 1] = sortArr[j];
            j--;
            sortArr[j + 1] = key;
        }
    }
   return sortArr;
}
