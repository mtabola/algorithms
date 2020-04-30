#include "divideAndConquer.h"

subarrData_t findMaxCrossingSubarr(int* arr, size_t low, size_t mid, size_t high)
{
    static subarrData_t subarrData;

    int leftSum = 0,
        rightSum = 0,
        sum = 0;

    size_t i = 0;

    for (i = mid; i > low; i--)
    { 
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            subarrData.left = i;
        }
    }

    sum = 0;

    for (i = mid + 1; i < high; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            subarrData.right = i;
        }
    }
    subarrData.sum = rightSum + leftSum;

    return subarrData;
}


subarrData_t findMaxSubarr(int* arr, size_t low, size_t high)
{
    subarrData_t subarrData;
    if (low == high)
    {
        subarrData.left = subarrData.right = low;
        subarrData.sum = arr[low];
        return subarrData;
    }
    else
    {
        subarrData_t leftSubarr,
                    rightSubarr,
                    crossSubarr;

        size_t mid = floor((low + high) / 2);



        leftSubarr = findMaxSubarr(arr, low, mid);
        rightSubarr = findMaxSubarr(arr, mid + 1, high);
        crossSubarr = findMaxCrossingSubarr(arr, low, mid, high);

        if ((leftSubarr.sum >= rightSubarr.sum) && (leftSubarr.sum >= crossSubarr.sum))
            return leftSubarr;
        else if ((rightSubarr.sum >= leftSubarr.sum) && (rightSubarr.sum >= crossSubarr.sum))
            return rightSubarr;
        else
            return crossSubarr;
    }
}