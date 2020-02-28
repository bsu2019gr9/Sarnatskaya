#include <iostream>
#include <iomanip>
#include "arrayfunctions.h"
using namespace std;
int** createArray(int N, int M);
void freeMemory(int**& p, int N);
void initRandomArray(int** p, int N, int M, const int min , const int max);
void initArray(int** p, int N, int M, const int m );
void printArray(int** p, int N, int M);
void sortByMaxInRow(int** p, int M, int N);

/*В массиве А(N,М) расположить строки в порядке возрастания их максимальных элементов.*/

int main()
{
	int M, N;
	cout << "Enter rows,cols\n";
	cin >> M >> N;
	int** arr = createArray(M, N);
	initRandomArray(arr, M, N, -10,20);
	printArray(arr, M, N);
	cout << "\n";
	sortByMaxInRow(arr, M, N);
	printArray(arr, M, N);

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
void initRandomArray(int** p, int N, int M, const int min , const int max) {
	int d = (max - min + 1);
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++) p[i][j] = rand() % d + min;
}
void initArray(int** p, int N, int M, const int m ) {
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++) p[i][j] = m;
}
void printArray(int** p, int N, int M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++)
			cout << setw(3) << p[i][j] << ";";
		cout << '\n';
	}
}
void sortByMaxInRow(int** p,  int M,  int N)
{
	int* max = createArray(N);
	int temp = max[0];
	for (int i = 0; i < M; i++)
	{
		max[i] = p[i][0];
		for (int j = 1; j < N; j++)
			if (p[i][j] > max[i])
				max[i] = p[i][j];
	}
	for (int i = 0; i < M - 1; i++)
		for (int k = i + 1; k < M; k++)
			if (max[k] < max[i])
			{
				
				temp = max[i];
				max[i] = max[k];
				max[k] = temp;
				for (int j = 0; j < N; j++)
				{
					temp = p[i][j];
					p[i][j] = p[k][j];
					p[k][j] = temp;
				}
			}
	freeMemory(max);
}

