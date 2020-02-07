#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void printArr(char* txt, int* arr, size_t arrSize);
int* getRandFillArr(size_t size, int min, int max);
void exchangeElements(int* arr, size_t i, size_t j);