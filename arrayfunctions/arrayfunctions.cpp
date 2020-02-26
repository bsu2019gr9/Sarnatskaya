#include "arrayfunctions.h"
using namespace std; 

void* createArray(int n, int*& p) {
	p = new (nothrow) int[n];
	if (!p) exit(404);
}
void freeMemory(int*& arr)
{
	delete[] arr; arr = nullptr;
}
void initRandomArray(int* beg, int* end, const int m = -10, const int M = 10) {
	int d = (M - m + 1);
	for (int* p = beg; p < end; ++p)
		*p = rand() % d + m;
}
void initArray(int* beg, int* end, const int m = 0) {
	for (int* p = beg; p < end; ++p)
		*p = m;
}
void printArray(int* beg, int* end) {
	for (int* p = beg; p < end; ++p)
		cout << setw(3) << *p << ";";
	cout << '\n';
}
void reverse(int* beg, int* end) {

	for (int* p = beg, *q = end - 1; p < q; ++p, --q)
	{
		swap(*p, *q);
	}
}
int findMax(int* beg, int* end) {
	int max = *beg;
	for (int* p = beg; p < end; ++p)if (*p > max)
		max = *p;
	return max;
	cout << '\n';
}
int findMin(int* beg, int* end) {
	int min = *beg;
	for (int* p = beg; p < end; ++p) if (*p < min)
		min = *p;
	return min;
	cout << '\n';
}
void findMaxMin(int* beg, int* end, int& min, int& max) {

	for (int* p = beg; p < end; ++p)
	{
		if (*p < min)
			min = *p;
		if (*p > max)
			max = *p;
	}
	cout << '\n';
}
int findSum(int* beg, int* end) {
	int s = 0;
	for (int* p = beg; p < end; ++p)
		s += *p;
	return s;
	cout << '\n';
}
int getMaxindex(int* beg, int* end)
{
	int max, * maxindex = 0;
	max = *beg;
	for (int* p = beg; p < end; ++p)
	{
		if (*p > max)
		{
			max = *p;
			maxindex = p;
		}
	}
	return *maxindex;
}
int getMinindex(int* beg, int* end)
{
	int min, * minindex = 0;
	min = *beg;
	for (int* p = beg; p < end; ++p)
	{
		if (*p <= min)
		{
			min = *p;
			minindex = p;
		}
	}
	return *minindex;
}
void shiftkLeft(int* beg, int* end, const int& k) {
	reverse(beg, beg + k);
	reverse(beg, end);
	reverse(beg, end - k);
}
void shiftkRight(int* beg, int* end, const int& k)
{
	reverse(beg, end - k);
	reverse(beg, end);
	reverse(beg, beg + k);
}
int evenSum(int* beg, int* end)
{
	int sum = 0; // сумма равна 0 
	for (int* p = beg; p < end; ++p) // в цикле перибираем элементы массива
		// если остаток от деления элемента на 2 равен 0, то прибавляем его к сумме
		if (*p % 2 == 0) sum += *p;
	return sum; // возвращаем сумму
}
void swap(int& a, int& b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
void bubbleSort(int* beg, int* end)
{
	for (int i = 0; i < (end - beg); ++i) {
		for (int* p = beg; p < end - 1; ++p) {
			if (*p > * (p + 1))
			{
				swap(*p, *(p + 1));
			}
		}
	}
}
void insertionSort(int* beg, int* end) {
	for (int* pi = beg + 1; pi < end; ++pi) {
		int* pj = pi;
		while (pj > beg&&* (pj - 1) > * pj) {
			swap(*(pj - 1), *pj);
			pj--;
		}
	}
}
void gnomeSort(int* beg, int* end) {
	int* p = beg;
	while (p < end) {
		if (p == beg || *(p - 1) <= *p) p++;
		else swap(*(p - 1), *p), p--;
	}
}