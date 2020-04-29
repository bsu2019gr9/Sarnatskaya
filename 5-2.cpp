#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Класс парабола.Хранить коэффициенты и вершину.

class Parabola
{
private:
	float a;
	float b;
	float c;
	float vertexX;
	float vertexY;
	void findVertexX() { this->vertexX = -this->b / (2 * this->a); };
	void findVertexY() { vertexY = -(b * b - 4 * a * c) / (4 * a); };
public:
	Parabola();   //конструктор без параметров!!!!!
	Parabola(float tmp1, float tmp2, float tmp3);  //конструктор c параметрами!!!!!
	Parabola(const Parabola& other); //конструктор копирования!!!!!
	~Parabola();//деструктор

	Parabola operator=(const Parabola& rhs);    //оператор присваивания
	Parabola operator+(const Parabola& rhs) const; //сложение
	Parabola operator - (const Parabola& rh) const; //вычитание
	Parabola operator * (float number) const;
	Parabola operator / (float number) const;

	Parabola operator+=(const Parabola& rhs);
	Parabola operator -= (const Parabola& rhs);
	Parabola operator *= (float number);
	Parabola operator /= (float number);

	bool operator==(const Parabola& par) const;
	bool operator!=(const Parabola& par) const;
	friend bool operator>(const Parabola& par1, const Parabola& par2);
	friend bool operator<(const Parabola& par1, const Parabola& par2);
	friend bool operator<=(const Parabola& par1, const Parabola& par2);
	friend bool operator>=(const Parabola& par1, const Parabola& par2);

	void  seta(float number);
	void  setb(float number);
	void  setc(float number);
	void  findVertex();
	void setall(float a, float b, float c);

	float geta();
	float getb();
	float getc();
	float getVertexX();
	float getVertexY();

	friend  void operator<<(ostream& out, const Parabola& par);
	friend void operator>>(istream& in, Parabola& par);
	void intersectionOX();
	void intersectionOY();
};

Parabola fff3(Parabola& par) { return par; };

typedef Parabola myType;

//на хипе
myType* createArray(size_t n);
void freeMemory(myType*& arr);
void inputArray(myType* beg, myType* end); // ввод массива с клавиатуры
void initArray(myType* beg, myType* end, size_t m, size_t M);
void printArray(myType* beg, myType* end); // печать массива
myType findMax(myType* beg, myType* end); //возвращает максимальный элемент массива
myType findMin(myType* beg, myType* end); //возвращает минимальный элемент массива
void findMaxMin(myType* beg, myType* end, myType& min, myType& max); //находит мин и макс элементы массива
myType findSum(myType* beg, myType* end); //возвращает сумму элементов массива
void  bubbleSort(myType* beg, size_t n); // сортировка

//на стеке
void inputArr(myType* arr, size_t len);// ввод массива с клавиатуры
void printArr(myType* arr, size_t len);// печать массива
myType findMax(myType* arr, size_t len);//возвращает максимальный элемент массива
myType findMin(myType* arr, size_t len);//возвращает минимальный элемент массива
void findMaxMin(int* arr, size_t len, size_t& min, size_t& max); //находит мин и макс элементы массива
myType findSum(myType* arr, size_t len);//возвращает сумму элементов массива

int main()
{
	int n(4);
	Parabola* p = new (nothrow) Parabola[n];
	p[0].setall(5, 7, 2);
	Parabola p1(3, 5, 7);
	p[1].setall(10, 10, 10);
	Parabola p3(9, 0, 15);
	Parabola p4(1, 1, 1);
	p[2] = p1; p[3] = p3;
	cout << (p[0] + p1);
	cout << '\n';
	cout << (p[1] - p1);
	cout << '\n';
	cout << (p[1] += p1);
	cout << '\n';
	cout << (p[0] * 0);
	cout << '\n';
	cout << (p[1] / 2);
	cout << '\n';
	p[0].intersectionOX();
	cout << '\n';
	p[1].intersectionOY();
	cout << '\n';
	cout << fff3(p4);
	cout << '\n';
	printArray(p, p + n);
	cout << '\n';
	bubbleSort(p, n);
	printArray(p, p + n);
	delete[] p;
	system("pause");
	return 0;
}

Parabola::Parabola() :
	a(1),
	b(0),
	c(0),
	vertexX(0),
	vertexY(0)
{
	cout << "constructor is working \n";
};
Parabola::Parabola(float tmp1, float tmp2 = 0, float tmp3 = 0) :
	a(tmp1),
	b(tmp2),
	c(tmp3),
	vertexX(0),
	vertexY(0)
{
	if (a == 0)
	{
		cout << "This parabola doesn't exist\n";
		a = 1;
	}
	findVertexX();
	findVertexY();
	cout << "constructor is working \n";
};
Parabola::Parabola(const Parabola& other)
{
	this->a = other.a;
	this->b = other.b;
	this->c = other.c;
	cout << "copy constructor is working \n";
};
Parabola:: ~Parabola()
{
	cout << "destructor is working ...\n";
};
Parabola Parabola :: operator=(const Parabola& rhs)
{
	cout << "= working \n";
	this->a = rhs.a;
	this->b = rhs.b;
	this->c = rhs.c;
	findVertexX();
	findVertexY();
	return *this;
}
Parabola Parabola :: operator+(const Parabola& rhs) const
{
	return Parabola(a + rhs.a, b + rhs.b, c + rhs.a);
}
Parabola Parabola :: operator-(const Parabola& rhs) const
{
	return Parabola(a - rhs.a, b - rhs.b, c - rhs.c);
}
Parabola Parabola :: operator * (float number) const
{
	return Parabola(a * number, b * number, c * number);
}
Parabola Parabola :: operator / (float number) const
{
	return Parabola(a / number, b / number, c / number);
}
Parabola Parabola :: operator+=(const Parabola& rhs)
{
	this->a += rhs.a;
	this->b += rhs.b;
	this->c += rhs.c;
	findVertexX();
	findVertexY();
	return *this;
}
Parabola Parabola :: operator -= (const Parabola& rhs)
{
	this->a -= rhs.a;
	this->b -= rhs.b;
	this->c -= rhs.c;
	findVertexX();
	findVertexY();
	return *this;
}
Parabola Parabola :: operator *= (float number)
{
	this->a *= number;
	this->b *= number;
	this->c *= number;
	findVertexX();
	findVertexY();
	return *this;
}
Parabola Parabola :: operator /= (float number)
{
	if (!number) {
		cout << "This parabola doesn't exist\n";
		return Parabola(a, b, c);
	}
	this->a /= number;
	this->b /= number;
	this->c /= number;
	findVertexX();
	findVertexY();
	return *this;
}
bool Parabola::operator==(const Parabola& par) const {
	return a == par.a && b == par.b && c == par.c;
}
bool Parabola::operator!=(const Parabola& par) const {
	return !(par == *this);
}
bool operator>(const Parabola& par1, const Parabola& par2)
{
	if ((par1.vertexX > par2.vertexX&& par1.vertexY > par2.vertexY) || (par1.vertexX == par2.vertexX && par1.vertexY > par2.vertexY) || (par1.vertexX > par2.vertexX&& par1.vertexY == par2.vertexY))return true;
	else return false;
}
bool operator<(const Parabola& par1, const Parabola& par2)
{
	if ((par1.vertexX < par2.vertexX && par1.vertexY < par2.vertexY) || (par1.vertexX == par2.vertexX && par1.vertexY < par2.vertexY) || (par1.vertexX < par2.vertexX && par1.vertexY == par2.vertexY))return true;
	else return false;
}
bool operator>=(const Parabola& par1, const Parabola& par2)
{
	if ((par1.vertexX > par2.vertexX&& par1.vertexY > par2.vertexY) || (par1.vertexX == par2.vertexX && par1.vertexY > par2.vertexY) || (par1.vertexX > par2.vertexX&& par1.vertexY == par2.vertexY) || (par1.vertexX == par2.vertexX && par1.vertexY == par2.vertexY))return true;
	else return false;
}
bool operator<=(const Parabola& par1, const Parabola& par2)
{
	if ((par1.vertexX < par2.vertexX && par1.vertexY < par2.vertexY) || (par1.vertexX == par2.vertexX && par1.vertexY < par2.vertexY) || (par1.vertexX < par2.vertexX && par1.vertexY == par2.vertexY) || (par1.vertexX == par2.vertexX && par1.vertexY == par2.vertexY))return true;
	else return false;
}
void Parabola::seta(float number) {
	a = number;
	if (!a) {
		cout << "This parabola doesn't exist\n";
		a = 1;
	}
};

void Parabola::setb(float number) { b = number; };

void Parabola::setc(float number) { c = number; };

void  Parabola::findVertex()
{
	findVertexX();
	findVertexY();
};

void Parabola::setall(float a, float b, float c) {
	this->a = a;
	if (!a) {
		cout << "This parabola doesn't exist\n";
		a = 1;
	}
	this->b = b;
	this->c = c;
}


float Parabola::geta() {
	return a;
};

float Parabola::getb()
{
	return b;
};

float Parabola::getc()
{
	return c;
};

float Parabola::getVertexX()
{
	return vertexX;
};

float Parabola::getVertexY()
{
	return vertexY;
};
void operator<<(ostream& out, const Parabola& par)
{
	out << "(" << par.a << ';' << par.b << ';' << par.c << ")";
};
void operator>>(istream& in, Parabola& par)
{
	in >> par.a;
	in >> par.b;
	in >> par.c;
}
void Parabola::intersectionOX()
{
	float D = 0, x1(0), x2(0);
	D = b * b - 4 * a * c;
	if (D > 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << "Intersection points are " << "(" << x1 << ",0)" << ";" << "(" << x2 << ", 0)" << '\n';

	}
	else if (D == 0)
	{
		x1 = -b / (2 * a);
		cout << "Intersection point is" << "(" << x1 << "," << "0)" << '\n';
	}
	else
		cout << "Parabola does't intersect OX\n";

};
void Parabola::intersectionOY()
{
	float  y(0), x = 0;
	y = a * x * x + b * x + c;
	cout << "Intersection point is" << "(0," << y << ")" << '\n';

};


// на хипе

myType* createArray(size_t n)
{
	myType* arr = nullptr;
	arr = new myType[n];
	return arr;
}

void* createArray(size_t n, myType*& p) {
	p = new (nothrow) myType[n];
	if (!p) exit(404);
}
void freeMemory(myType*& arr)
{
	delete[] arr; arr = nullptr;
}
void initArray(myType* beg, myType* end, size_t m, size_t M) {
	srand(time(NULL));
	size_t d = (M - m + 1);
	for (myType* p = beg; p < end; ++p)
		*p = rand() / d + m;
}
void inputArray(myType* beg, myType* end) {
	for (myType* p = beg; p < end; ++p)
		cin >> *p;
}
void printArray(myType* beg, myType* end) {
	for (myType* p = beg; p < end; ++p)
		cout << *p; cout << ";";
	cout << '\n';
}
myType findMax(myType* beg, myType* end) {
	myType max = *beg;
	for (myType* p = beg; p < end; ++p)
		if (*p > max) max = *p;
	return max;
	cout << '\n';
}
myType findMin(myType* beg, myType* end) {
	myType min = *beg;
	for (myType* p = beg; p < end; ++p) if (*p < min)
		min = *p;
	return min;
	cout << '\n';
}
void findMaxMin(myType* beg, myType* end, myType& min, myType& max) {

	for (myType* p = beg; p < end; ++p)
	{
		if (*p < min)
			min = *p;
		if (*p > max)
			max = *p;
	}
	cout << '\n';
}
myType findSum(myType* beg, myType* end) {
	myType s = 0;
	for (myType* p = beg; p < end; ++p)
		s += *p;
	return s;
	cout << '\n';
}
void bubbleSort(myType* beg, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		for (myType* p = beg; p < beg + n - 1; ++p) {
			if (*p > * (p + 1))
			{
				swap(*p, *(p + 1));
			}
		}
	}
}



//на стеке
void inputArr(myType* arr, size_t len) {
	for (size_t i = 0; i < len; ++i)
		cin >> arr[i];
}
void printArr(myType* arr, size_t len) {
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i]; cout << " ";
	}
	cout << '\n';
}
myType findMax(myType* arr, size_t len) {
	myType max = arr[0];
	for (size_t i = 0; i < len; i++)if (arr[i] > max)
		max = arr[i];
	return max;
	cout << '\n';
}
myType findMin(myType* arr, size_t len) {
	myType min = arr[0];
	for (size_t i = 0; i < len; i++)if (arr[i] < min)
		min = arr[i];
	return min;
	cout << '\n';
}
void findMaxMin(int* arr, size_t len, size_t& min, size_t& max) {

	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] < min)min = arr[i];
		if (arr[i] > max)max = arr[i];
	}
	cout << '\n';
}
myType findSum(myType* arr, size_t len) {
	myType s = 0;
	for (size_t i = 0; i < len; i++)
		s += arr[i];
	return s;
	cout << '\n';
}