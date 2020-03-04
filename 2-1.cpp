#include <iostream>
#include <iomanip>
#include "arrayfunctions.h"
using namespace std;
int** createArray(int N, int M);
void freeMemory(int**& p, int N);
void initRandomArray(int** p, int N, int M, const int min, const int max);
void initArray(int** p, int N, int M, const int m);
void printArray(int** p, int N, int M);
void findMaxInRow(int** p, int N, int M, int* maxarray);
void sortByMaxInRow(int** p, int N, int M);

//В массиве А(N, М) расположить строки в порядке возрастания их максимальных элементов.

int main()
{
	int M, N;
	cout << "Enter rows,cols\n";
	cin >> N >> M;
	int** A = createArray(N, M);
	initRandomArray(A, N, M, -10, 10);
	printArray(A, N, M);
	cout << "\n";
	sortByMaxInRow(A, N, M);
	cout << "\n";
	printArray(A, N, M);
	freeMemory(A, N);

}
int** createArray(int N, int M) {
	int** p = new (nothrow) int* [N];
	if (!p) exit(404);
	for (size_t i = 0; i < N; i++) {
		p[i] = new (nothrow) int[M];
		if (!p[i]) exit(404);
	}
	return p;
}
void freeMemory(int**& p, int N) {
	for (size_t i = 0; i < N; i++) delete[] p[i];
	delete[] p;
	p = nullptr;
}
void initRandomArray(int** p, int N, int M, const int min, const int max) {
	int d = (max - min + 1);
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++) p[i][j] = rand() % d + min;
}
void initArray(int** p, int N, int M, const int m) {
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++) p[i][j] = m;
}
void printArray(int** p, int N, int M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++)
			cout << setw(3) << p[i][j] << " ";
		cout << '\n';
	}
}
void findMaxInRow(int** p, int N, int M, int*maxarray)
{
	int max = **p;
	for (size_t i = 0; i <N ; i++)
	{
		max = p[i][0];
		for (size_t j = 0; j < M; j++)
		{
			if (max < p[i][j])
				max = p[i][j];

		}
		maxarray[i] = max;
		cout <<"\n max element: " << max <<"\n";
	}
}
void sortByMaxInRow(int** p, int N, int M)
{
	int* maxarray = createArray(N);
	findMaxInRow(p, N, M, maxarray);
	cout << '\n';
	for (int i = 0; i < N; ++i)
	{
		for( int j=0;j<N - 1;++j)
			if (maxarray[j] > maxarray[j + 1])
			{
				swap(maxarray[j], maxarray[j + 1]);	
				swap(p[j], p[j + 1]);

			}
	}
}
