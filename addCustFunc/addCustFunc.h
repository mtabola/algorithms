#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

void printArr(char* txt, int* arr, size_t arrSize);
int* getRandFillArr(size_t size, int min, int max);
void exchangeElements(int* arr, int i, int j);
int findMaxElem(int* arr, size_t arrSize);
int findMaxGrade(int* inpArr, size_t size);
