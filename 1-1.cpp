//task1 В массиве размера N, заполненного случ.числами от -10 до 10, подсчитать количество элементов, встречающихся более одного раза.
//task2 В массиве размера N, заполненного случ.числами от -10 до 20, определить максимальную длину последовательности равных элементов.

#include <iostream>
#include <iomanip>
#include "arrayfunctions.h"
using namespace std;

int Task1(int*,int*);
int Task2(int*, int*);

int main()
{
	int N;
	cout << "Enter size of array : \n";
	cin >> N;
	int* array = createArray(N);
	initRandomArray(array, array + N, -10, 10);
	printArray(array, array + N);
	cout << "\n" << "counts1:" << Task1(array,array+N) << "\n";
	initRandomArray(array, array + N, -10, 20);
	printArray(array, array + N);
	cout << "\n" << "counts2:" << Task2(array,array+N) << "\n";
	freeMemory(array);
}
int Task1(int* beg, int* end) 
{
	gnomeSort(beg, end);
	printArray(beg, end);
	int element = *beg, cnt = 0, rezult = 0;
	for (int* p = beg; p < end; ++p)
	{
		if (element == *p) ++cnt;
		else
		{
			if (cnt > 1 && rezult <= cnt)rezult = cnt;
			cnt = 1; element = *p;
		}

	}
	return rezult;
}
int Task2(int* beg, int* end)
{
	int element = *beg, maxlenght = 0, cnt = 0;
	for (int* p = beg; p < end; ++p)
	{
		if (element == *p) ++cnt;
		else {
			if (maxlenght < cnt) { maxlenght = cnt; cnt = 1; }
			element = *p;
		}
	}
	return maxlenght;;
}