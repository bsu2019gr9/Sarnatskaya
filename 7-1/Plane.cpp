#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include<fstream>
#include <cstring>
#include<iomanip>
#include"plane.h"
using namespace std;
const int Buff{ 100 };


Plane::Plane() {
	flightNumber = 0;
	destination = (new(nothrow)char[13]);
	if (!destination) { cout << "error"; exit(1); }
	strcpy(destination, "незаполнено");
	freePlace = 0;
	//cout << "Constructor without params\n";
}
Plane::Plane(int flightNumber, const char* Destination, int freePlace) :
	flightNumber(flightNumber),
	destination(new (nothrow) char[strlen(Destination) + 1]),
	freePlace(freePlace)
{
	strcpy(destination, Destination);
	//cout << "Constructor with params\n";
}
Plane::Plane(const Plane& plane) :
	flightNumber(plane.flightNumber),
	destination(new (nothrow) char[strlen(plane.destination) + 1]),
	freePlace(plane.freePlace)
{
	strcpy(destination, plane.destination);
	//cout << "copy constructor\n";
}
Plane:: ~Plane() {
	if (destination) {
		delete[]destination;
		destination = nullptr;
		//cout << "work destruktor\n";
	}
}


Plane Plane::operator=(const Plane& plane) {
	flightNumber = plane.flightNumber;
	if (destination) delete[]destination;
	destination = nullptr;
	destination = new(nothrow) char[strlen(plane.destination) + 1];
	strcpy(destination, plane.destination);
	freePlace = plane.freePlace;
	return *this;
}
ostream& operator << (ostream& out, const Plane& plane) {
	if (plane.destination != nullptr)
		//out.setf(ios::left);
		out << setw(7) << plane.flightNumber << "|" << setw(17) << plane.destination << "|" << setw(7) << plane.freePlace << "|" << " \n";
	else out << setw(7) << plane.flightNumber << "|" << setw(17) << " " << "|" << setw(7) << plane.freePlace << "|" << " \n";
	return out;
}
istream& operator >> (istream& in, Plane& plane)
{
	in >> plane.flightNumber;
	char destination[20];
	in >> destination;
	plane.setDestination(destination);
	in >> plane.freePlace;
	return in;
}


void Plane::setFlightNumber(int flightNumber) {
	if (flightNumber > 100000) throw "bad data";
	else this->flightNumber = flightNumber;
}
void Plane::setDestination(const char Destination[20]) {
	if (destination) { delete[] destination; destination = nullptr; }
	destination = new (nothrow) char[strlen(Destination) + 1];
	strcpy(destination, Destination);
}
void Plane::setFreePlace(unsigned int freePlace) {
	if (freePlace > 500) throw "bad data";
	this->freePlace = freePlace;
}
void Plane::setAll(int flightNumber, const char* destination, unsigned int freePlace) {
	setFlightNumber(flightNumber);
	setDestination(destination);
	setFreePlace(freePlace);
}


int Plane::getFlightNumber() {
	if (this->flightNumber) //cout << "не определено\n ";
		return flightNumber;
}
const char* Plane::getDestination() {
	if (this->destination)  //cout << "не определено \n";
		return destination;
}
unsigned int Plane::getFreePlace() {
	if (this->freePlace)  // cout << "не определено\n ";
		return freePlace;
}
void Plane::getAll() {
	if (this->flightNumber || this->destination || this->freePlace) {

		if (!this->flightNumber)cout << "не определено\n ";
		if (!this->destination)cout << "не определено\n ";
		if (!this->freePlace) cout << "не определено\n ";
		cout << "\n";
	}
}


void editFlight(Plane* arr, int n) //редактировать  рейс
{
tryAgain:
	int tmp;
	int a;
	int count = 0;
	char buff[Buff];
	cout << "Введите номер рейса \n";
	int number;
	cin >> number;
	for (int i = 0; i < n; i++) {
		if (arr[i].flightNumber == number)
		{
			cout << arr[i];
			++count;
			cout << "\n\nВыберите операцию: \n\n";
			cout << "1)изменить номер рейса ;\n";
			cout << "2) изменить пункт назначения;\n";
			cout << "3)изменить количество свободных мест;\n";
			cout << "Ваш выбор: ";
			cin >> a;
			switch (a)
			{
			case 1:
				cout << " Номер рейса " << arr[i].flightNumber << " \n Введите новый номер рейса \n";
				cin >> tmp;
				arr[i].flightNumber = tmp;
				cout << arr[i];
				break;
			case 2:
				cout << "Пункт назначения" << arr[i].destination << "\n Введите новый пункт назначения \n";
				cin.ignore();
				cin.getline(buff, Buff);
				arr[i].destination = buff;
				cout << arr[i];
				break;
			case 3:
				cout << " Количество свободных мест " << arr[i].freePlace << " \n Введите новое количество свободных мест \n";
				cin >> tmp;
				arr[i].freePlace = tmp;
				cout << arr[i];
				break;
			default:
				cout << "Неверно. Введите заново \n";
				break;
			}
		}
	}
	if (count == 0)
	{
		cout << "Неверно введен номер рейса. Попробуйте еще раз\n";
		goto tryAgain;
	}
}


void showInfoAboutFlight(Plane* arr, int n) { //вывести инфо о рейсе
tryAgain:
	cout << "Введите номер рейса \n";
	int count = 0;
	int number;
	cin >> number;
	for (int i = 0; i < n; i++) {
		if (arr[i].flightNumber == number)
		{
			cout << arr[i];
			++count;
		}
	}

	if (count == 0)
	{
		cout << "Неверно введен номер рейса. Попробуйте еще раз\n";
		goto tryAgain;
	}
}
void showListOfFligtsToCertainDestination(Plane* arr, int n) //список рейсов до указанного места
{
tryAgain:
	int count = 0;
	cout << "Введите пункт назначения \n";
	char* Destination = nullptr;
	Destination = new(nothrow) char[255];
	cin >> Destination;
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(arr[i].destination, Destination))
		{
			cout << arr[i];
			++count;
		}
	}
	if (count == 0)
	{
		cout << "Нет такого направления. Попробуйте еще раз\n";
		goto tryAgain;
	}
}
 void printTicket(Plane* arr, int n) {//напечатать билет
tryAgain:
	cout << "Введите номер рейса \n";
	int count = 0;
	int number;
	cin >> number;
	for (int i = 0; i < n; i++) {

		if (arr[i].flightNumber == number)
		{
			if (arr[i].freePlace > 0)
			{
				char* surname = nullptr;
				surname = new(nothrow) char[255];
				cout << "Введите фамилию \n";
				cin >> surname;
				char* name = nullptr;
				name = new(nothrow) char[255];
				cout << "Введите имя\n";
				cin >> name;
				cout << "Ваш билет\n" << surname << " ";
				cout << name << "\n";
				cout << arr[i];
				++count;

			}

			else
			{
				cout << "Нет свобоных мест. Выберете другой рейс\n";
				goto tryAgain;
			}

		}
	}

	if (count == 0)
	{
		cout << "Неверно введен номер рейса. Попробуйте еще раз\n";
		goto tryAgain;
	}

}


Plane* createFlight(Plane* arr, int& M) {
	 cout << "Введите значения рейса:\n";
	 cin >> arr[M];
	 M++;
	 return  arr;
 }
Plane* deleteFlight(Plane* arr, int& n) {

	cout << "Введите номер рейса, который хотите удалить:";
	int number;
	cin >> number;
	if (number >= n || number < 0) {
		"Такого номера не существует!\n"; return arr;
	}
	swap(arr[number], arr[n - 1]);
	Plane* tmp = new(nothrow)Plane[n - 1];
	for (int i = 0; i < n - 1; ++i) tmp[i] = arr[i];
	freeMemory(arr, n);
	n--;
	return tmp;
	cout << "готово";
}
void freeMemory(Plane* arr, int n)
{
	if (arr) { delete[] arr;	arr = nullptr; }
}


int readFromFile(Plane* arr, int N, const char way[50])
{
	ifstream From(way, ios::binary);
	if (!From) { cout << "Не могу найти файл!\n"; return 0; }
	char buff[40]; size_t size;
	int flightNumber;
	unsigned int freePlace;

	int i = 0;
	while (i < N)
	{
		if (From.eof())break;
		From.read((char*)&flightNumber, sizeof(int));
		arr[i].setFlightNumber(flightNumber);


		From.read((char*)&size, sizeof(size_t));
		From.read((char*)&buff, size);
		arr[i].setDestination(buff);

		From.read((char*)&freePlace, sizeof(unsigned int));
		arr[i].setFreePlace(freePlace);

		i++;
		cout << arr[i];
	}cout << "\nВыполнено успешо\n";
	From.close();
	return i;

}
void writeToFile(Plane* arr, int N, const char way[50])
{
	if (!N) { cout << "Нечего записывать...\n"; return; }
	ofstream Into(way, ios::binary);
	char buff[40];
	int flightNumber;
	size_t size;
	unsigned int freePlace;
	for (int i = 0; i < N; ++i)
	{
		flightNumber = arr[i].getFlightNumber();
		Into.write((char*)&flightNumber, sizeof(int));


		strcpy(buff, arr[i].getDestination());
		size = strlen(buff) + 1;
		Into.write((char*)&size, sizeof(size_t));
		Into.write((char*)&buff, size);

		freePlace = arr[i].getFreePlace();
		Into.write((char*)&freePlace, sizeof(int));

	}
	Into.close();
	cout << "готово";
}


void printArr(Plane* arr, int M) {
	for (int i = 0; i < M; ++i) {
		cout << setw(5) << i << "|" << arr[i];
		cout << '\n';
	}


}
int sizeArr(Plane* arr) {
	return *((size_t*)arr - 1);
}