#include "bruteforce.h"

subarrData brutforceFind(int* arr, size_t begPos, size_t endPos)
{
    subarrData maxElem = { 0, 0, 0 };

    for (int i = begPos; i <= endPos; i++)
    {
        int result = 0;
        int j = 0;

        for (j = i; j < endPos; j++)
        {
            result += arr[j];
            if (result > maxElem.sum)
            {
                maxElem.sum = result;
                maxElem.begPos = i;
                maxElem.endPos = j;
            }
        }

    }
    return maxElem;
}