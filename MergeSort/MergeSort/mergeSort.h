#pragma once


typedef struct _node 
{
    int data;
    bool end;
}node;

node* createTmpArr(int* sortArr, size_t min, size_t max, size_t tmpArrSize) 
{
     node* tmpArr = calloc(tmpArrSize + 1, sizeof(node));
    for (int i = 0; i < max; i++) {
        tmpArr[i].data = sortArr[min + i];
        tmpArr[i].end = false;
    }
    tmpArr[tmpArrSize].data = 0;
    tmpArr[tmpArrSize].end = true;

    return tmpArr;
}



void merge(int* sortArr, size_t min, size_t mid, size_t max)
{
    size_t begPart = mid - min + 1;
    size_t endPart = max - mid;

    node* lPart = createTmpArr(sortArr, min, mid, begPart);
    node* rPart = createTmpArr(sortArr, mid, max, endPart);

    int left = 0;
    int right = 0;

    for (int k = min; min <= max; k++)
    {
        if (lPart[left].data <= rPart[right].data)
        {
            sortArr[k] = lPart[left].data;
            left++;
        }
        else
        {
            sortArr[k] = rPart[right].data;
            right++;
        }
    }
    
    free(lPart);
    free(rPart);
}


void mergeSort(int* sortArr, size_t min, size_t max)
{
    if (min < max) 
    {
        size_t mid = (min + max) / 2;
        mergeSort(sortArr, min, mid);
        mergeSort(sortArr, mid + 1, max);
        merge(sortArr, min, mid, max);
    }
}