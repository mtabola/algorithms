#include "brutforce.h"

subarrData brutforceFind(int* arr, size_t begPos, size_t endPos, int step)
{
    subarrData maxElem = { 0, 0, 0 };

    for (int i = begPos; i <= endPos - step; i++)
    {
        int result = 0;
        int j = 0;

        for (j = i; j < i + step; j++)
            result += arr[j];
        
        if (maxElem.sum < result)
        {
            maxElem.sum = result;
            maxElem.begPos = j - step;
            maxElem.endPos = j - 1;
        }

    }
    return maxElem;
}