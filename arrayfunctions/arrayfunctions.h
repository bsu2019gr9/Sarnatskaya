#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
int* createArray( const int n);
void* createArray(int n, int*& p);
void freeMemory(int*& arr);
void initRandomArray(int* beg, int* end, const int m = -10, const int M = 10);
void initArray(int* beg, int* end, const int m = 0);
void printArray(int* beg, int* end);
void reverse(int* beg, int* end);
int findMax(int* beg, int* end);
int findMin(int* beg, int* end);
void findMaxMin(int* beg, int* end, int& min, int& max);
int findSum(int* beg, int* end);
int getMaxindex(int* beg, int* end);
int getMinindex(int* beg, int* end);
void shiftkLeft(int* beg, int* end, const int& k);
void shiftkRight(int* beg, int* end, const int& k);
int evenSum(int* beg, int* end);
void swap(int& a, int& b);
void bubbleSort(int* beg, int* end);
void insertionSort(int* beg, int* end);
void gnomeSort(int* beg, int* end);
