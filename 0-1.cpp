/* вычислить значение функции f(x) = arctgx + sinx
   на отрезке [a;b] с шагом h и точностью еps, 
   используя разложение в ряд тейлора  */

#include <iostream>
#include <cmath> //Подключение библиотеки математических ф-ий 
#include <clocale>
using namespace std;
void table(double, double, double, double, double);
double Sum_OfTheSinAndAtan(double, double);
double Atan(double,double);
double sin(double, double);

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, h, eps, x=1;
	cout << "Введи начало отрезка a = ";
	cin >> a;
	cout << " Введи конец отрезка b = ";
	cin >> b;
	cout << "Введи шаг h = ";
	cin >> h;
	cout << "Введи точность eps = ";
	cin >> eps;
	table(x, a, b, h, eps);
	system("pause");
	return 0;
}
void table(double x, double a, double b, double h, double eps) // таблица значений 
{
	cout << " \n";
	for (x = a; x <= b + h / 2; x += h)
	{
		cout << "x = ";
		cout.width(6); cout << x;
		cout.width(15); cout << Sum_OfTheSinAndAtan(x, eps);
		cout.width(15); cout << (atan(x) + sin(x));
		cout << "\n";
	}
}
double Atan(double x, double eps)//через ряд
{
	double n = x;
	double sum = n;
	for (int i = 3; fabs(n) > eps; i+=2)
	{
		n = n * (-1.0) * x * x / i * (i - 2);
		sum += n;
	}
	return sum;
}
double sin(double x,double eps)
{
	double n = x;
	double sum = x;
	for (int i=3; fabs(n) > eps; i+=2)
	{
		n = -1.0 * n * x * x / i / (i - 1);
		sum += n;
	} 
	return sum;
}
double Sum_OfTheSinAndAtan(double x, double eps)
{
	double sum = 0;
	sum = sin(x, eps) + Atan(x, eps);
	return sum;
}