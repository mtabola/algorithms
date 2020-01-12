void printArr(char** txt, int* arr, int arrSize)
{
    printf("%s ", txt);
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");
}