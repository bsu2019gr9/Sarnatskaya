#include <iostream>
#include "functions massiv.h"
using namespace std;
int* giveMemory(int n)
{
	int* arr = new int[n];
	arr = { 0 };
	return arr;
}
void freeMemory(int arr[])
{
	if (!arr)
	{
		cout << "array is empty\n";
		return;
	}
	delete[] arr;
}
void inputArray(int* arr, const int len) {
	for (int i = 0; i < len; ++i)
		cin >> arr[i];
}
void printArr(int* arr, int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}
int findMax(int* arr, int len) {
	int max = arr[0];
	for (int i = 0; i < len; i++)if (arr[i] > max)
		max = arr[i];
	return max;
	cout << '\n';
}
int findMin(int* arr, int len) {
	int min = arr[0];
	for (int i = 0; i < len; i++)if (arr[i] < min)
		min = arr[i];
	return min;
	cout << '\n';
}
void findMaxMin(int* arr, int len, int& min, int& max) {

	for (int i = 0; i < len; i++)
	{
		if (arr[i] < min)min = arr[i];
		if (arr[i] > max)max = arr[i];
	}
	cout << '\n';
}
int findSum(int* arr, int len) {
	int s = 0;
	for (int i = 0; i < len; i++)
		s += arr[i];
	return s;
	cout << '\n';
}
int getMaxindex(int* arr, int len)
{
	int max, maxindex = 0;
	max = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxindex = i;
		}
	}
	return maxindex;
}
int getMinindex(int* arr, int len)
{
	int min, minindex = 0;
	min = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] <= min)
		{
			min = arr[i];
			minindex = i;
		}
	}
	return minindex;
}
void reverse(int* arr, int len) {
	int tmp;
	for (int i = 0; i < len / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = tmp;
	}
}
void leftShift(int* A, int* B, const int len) {
	for (int i = 0; i < len; ++i)B[i] = A[i];
	for (int i = 0; i < len - 1; ++i)swap(B[i], B[i + 1]);
	cout << "Left shifted array = ";
}
void rightShift(int* A, int* B, const int len) {
	for (int i = 0; i < len; ++i)B[i] = A[i];
	for (int i = len - 1; i > 0; --i)swap(B[i], B[i - 1]);
	cout << "Right shifted array = ";
}
void shiftkLeft(int* arr, int len, int k) {
	reverse(arr, len);
	reverse(arr, len - k);
	reverse(arr + len - k, k);
}
void randArr(int* arr, int len, int min, int max)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}
int evenSum(int* arr, int len)
{
	int sum = 0; // сумма равна 0 
	for (int i = 0; i < len; i++) // в цикле перибираем элементы массива
		// если остаток от деления элемента на 2 равен 0, то прибавляем его к сумме
		if (arr[i] % 2 == 0) sum += arr[i];
	return sum; // возвращаем сумму
}
