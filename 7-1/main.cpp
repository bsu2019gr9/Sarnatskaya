/* 15. (6 - 7) В объекте хранится информация о движении самолётов : номер
рейса(int), пункт назначения(*char либо char[3]), информация о наличии
свободных мест(int).Разработать функции - члены класса, которые позволяют
a) Создания / удаления / редактирования рейса
b) По запросу вывести информацию об указанном рейсе.
c) Вывести список рейсов, следующих до указанного пункта
назначения
d) Распечатать по заявке пассажира билет, если есть свободные места
на указанный рейс.Предложить другой рейс, если на указанный
рейс нет билетов, или вывести сообщение о невозможности вылета
в указанный пункт. */

#define _CRT_SECURE_NO_WARNINGS
#include"plane.h"
#include <iostream>
#include "windows.h"
#include<fstream>
using namespace std;

int main() {
	int M(30), maxSize(100);
	int param;
	Plane* flight = nullptr;
	flight = new(nothrow)Plane[maxSize];
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	flight[0].setAll(23312, "Edinburgh", 4);
	flight[1].setAll(85766, "Moscow", 3);
	flight[2].setAll(58573, "Kiev", 0);
	flight[3].setAll(45356, "Antalya", 12);
	flight[4].setAll(43577, "Sydney", 1);
	flight[5].setAll(56355, "Edinburgh", 5);
	flight[6].setAll(43535, "New York", 4);
	flight[7].setAll(54623, "Las Vegas", 4);
	flight[8].setAll(96566, "Sharm El Sheikh", 4);
	flight[9].setAll(56433, "Edinburgh", 3);
	flight[10].setAll(23562, "Canberra", 2);
	flight[11].setAll(54678, "Sharm El Sheikh", 5);
	flight[12].setAll(12346, "Edinburgh", 2);
	flight[13].setAll(78563, "Edinburgh", 1);
	flight[14].setAll(75323, "Sharm El Sheikh", 1);
	flight[15].setAll(34312, "Milan", 3);
	flight[16].setAll(96566, "Berlin", 0);
	flight[17].setAll(56433, "Praga", 8);
	flight[18].setAll(46576, "Vena", 4);
	flight[19].setAll(35766, "Stambul", 22);
	flight[20].setAll(99766, "Praga", 17);
	flight[21].setAll(45623, "London", 11);
	flight[22].setAll(22245, "Madrid", 34);
	flight[23].setAll(45977, "Milan", 0);
	flight[24].setAll(87546, "Nicosia", 0);
	flight[25].setAll(83578, "Antalya", 10);
	flight[26].setAll(25657, "Madrid", 0);
	flight[27].setAll(78677, "Antalya", 0);
	flight[28].setAll(75588, "Vena", 0);
	flight[29].setAll(22222, "Berlin", 12);
	//flight[30].setAll(66666, "Madrid", 4);

	int n;
	while (1) {
		cout << "\n\nВыберите операцию: \n\n";
		cout << "0) выйти из меню\n";
		cout << "1) вывести на экран\n";
		cout << "2) иницилизировать из файла;\n";
		cout << "3) записать в файл;\n";
		cout << "4) создать рейс;\n";
		cout << "5) изменить рейс;\n";
		cout << "6) удалить рейс;\n";
		cout << "7) вывести информацию об указанном рейсе;\n";
		cout << "8) вывести список рейсов, следующих до данного направления;\n";
		cout << "9) распечатать билет;\n";
		cout << "Ваш выбор: ";
		cin >> n;
		switch (n)
		{
		case 0:
			return 0;
			break;

		case 1:
			printArr(flight, M);
			break;
		case 2:
			char way[40];
			cout << "Введите расположение файла\n";
			cin >> way;
			try {
				M = readFromFile(flight, M, way);
			}
			catch (...) { cout << "Файл не найден\n"; }

			break;
		case 3:
			cout << "Введите расположение файла\n";
			cin >> way;
			writeToFile(flight, M, way);
			break;
		case 4:
			flight = createFlight(flight, M);
			break;
		case 5:
			editFlight(flight, sizeArr(flight));
			break;
		case 6:
			flight = deleteFlight(flight, M);
			break;
		case 7:
			showInfoAboutFlight(flight, sizeArr(flight));
			break;
		case 8:
			showListOfFligtsToCertainDestination(flight, sizeArr(flight));
			break;
		case 9:
			printTicket(flight, sizeArr(flight));
			break;

		default:
			cout << "Неверные значения. Попробуйте еще раз\n";
			break;
		}
	}
}