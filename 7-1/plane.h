#pragma once
#include <iostream>
using namespace std;

class Plane {
private:
	int flightNumber;
	char* destination;
	unsigned int freePlace;
public:
	Plane(); //конструктор без парметров
	Plane(int, const char*, int); //конструктор с параметрами
	Plane(const Plane& other);	//конструктор копирования
	~Plane();	//деструктор

	Plane operator=(const Plane& rhs); //оператор присваивания
	friend ostream& operator << (ostream& out, const Plane& plane);
	friend istream& operator >> (istream& in, Plane& plane);


	void setFlightNumber(int); //задать номер рейса
	void setDestination(const char*); // задать пункт назначения
	void setFreePlace(unsigned int); //задать кол-во свободных мест
	void setAll(int, const char*, unsigned int); //задать рейс

	int getFlightNumber(); //вывести номер рейса
	const char* getDestination(); //вывести пункт назначения
	unsigned int getFreePlace(); //вывести кол-во свободных мест
	void getAll(); //вывести рейс

	friend void editFlight(Plane* arr, int n);

	friend void showInfoAboutFlight(Plane* arr, int n);
	friend void showListOfFligtsToCertainDestination(Plane* arr, int n);
	friend void printTicket(Plane* arr, int n);
};

Plane* createFlight(Plane* arr, int& M);
Plane* deleteFlight(Plane*, int&); // удалить рейс
void freeMemory(Plane* arr, int n);
int readFromFile(Plane* arr, int N, const char way[50]);
void writeToFile(Plane* arr, int N, const char way[50]);
void printArr(Plane* arr, int M);
int sizeArr(Plane* arr);
