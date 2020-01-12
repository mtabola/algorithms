#pragma once

void merge(int* sortArr, size_t min, size_t mid, size_t max)
{
    int lPart = mid - min + 1;
    int rPart = max - mid;

    int* lArr = calloc(lPart, sizeof(int));
    int* rArr = calloc(rPart, sizeof(int));

    for (int i = 0; i < lPart; i++)
    {
        lArr[i] = sortArr[min + i];
    }

    for (int j = 0; j < rPart; j++)
    {
        rArr[j] = sortArr[mid + 1 + j];
    }

    int left = 0;
    int right = 0;
    int k = min;

    for (; left < lPart && right < rPart; k++)
    {
        if (lArr[left] <= rArr[right])
        {
            sortArr[k] = lArr[left];
            left++;
        }
        else
        {
            sortArr[k] = rArr[right];
            right++;
        }
    }

    while (left < lPart)
    {
        sortArr[k] = lArr[left];
        left++;
        k++;
    }

    while (right < rPart)
    {
        sortArr[k] = rArr[right];
        right++;
        k++;
    }
}

void mergeSort(int* sortArr, size_t min, size_t max)
{
    if (min < max)
    {
        size_t mid = (min + (max - 1)) / 2;
        mergeSort(sortArr, min, mid);
        mergeSort(sortArr, mid + 1, max);
        merge(sortArr, min, mid, max);
    }
}