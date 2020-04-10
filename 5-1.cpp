#include <iostream>
#include <iomanip>
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
	Parabola operator+=(const Parabola& rhs); //сложение
	Parabola operator -= (const Parabola& other); //вычитание
	Parabola operator *= (float t);
	Parabola operator /= (float t);
	void  seta(float t);
	void  setb(float t);
	void  setc(float t);
	void  findVertex();
	void setall(float t, float m, float p);
	float geta();
	float getb();
	float getc();
	float getVertexX();
	float getVertexY();
	friend  void operator<<(ostream& out, const Parabola& par);
	friend void operator>>(istream& in, Parabola& par);
};
Parabola fff1(Parabola par) { return par; };
Parabola* fff2(Parabola* par) { return par; };
Parabola fff3(Parabola& par) { return par; };


int main()
{
	Parabola* p = new (nothrow) Parabola[5];
	(*p).setall(5, 7, 2);
	Parabola p1(3, 5, 7);
	(*(p + 1)).setall(10, 10, 10);
	Parabola p2(1, 4, 6);
	Parabola p3(9, 0, 15);
	Parabola p4(1, 1, 1);
	cout << (*p + p1);
	cout << '\n';
	cout << (*(p + 1) - p1);
	cout << '\n';
	cout << (*p * 0);
	cout << '\n';
	cout << (*(p + 1) / 2);
	cout << '\n';
	cout << fff1(p3);
	cout << '\n';
	cout << fff2(p);
	cout << '\n';
	cout << fff3(p4);
	cout << '\n';
	cout << setprecision(1) << "The vertex is: " << p2.getVertexX() << " " << p2.getVertexY() << '\n';
	p2.setb(10);
	p2.findVertex();
	cout << setprecision(1) << "The vertex is: " << p2.getVertexX() << " " << p2.getVertexY() << '\n';
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
Parabola Parabola :: operator+=(const Parabola& rhs)
{
	this->a += rhs.a;
	if (!this->a) {
		cout << "This parabola doesn't exist\n";
		a = 1;
	}
	this->b += rhs.b;
	this->c += rhs.c;
	findVertexX();
	findVertexY();
	return Parabola(a, b, c);
}
Parabola Parabola :: operator -= (const Parabola& rhs)
{
	this->a -= rhs.a;
	if (!this->a) {
		cout << "This parabola doesn't exist\n";
		a = 1;
	}
	this->b -= rhs.b;
	this->c -= rhs.c;
	findVertexX();
	findVertexY();
	return Parabola(a, b, c);
}
Parabola Parabola :: operator *= (float t)
{
	this->a *= t;
	if (!this->a) {
		cout << "This parabola doesn't exist\n";
		a = 1;
	}
	this->b *= t;
	this->c *= t;
	findVertexX();
	findVertexY();
	return Parabola(a, b, c);
}
Parabola Parabola :: operator /= (float t)
{
	if (!t) {
		cout << "This parabola doesn't exist\n";
		return Parabola(a, b, c);
	}
	this->a /= t;
	this->b /= t;
	this->c /= t;
	findVertexX();
	findVertexY();
	return Parabola(a, b, c);
}
void Parabola::seta(float t) {
	a = t;
	if (!a) {
		cout << "This parabola doesn't exist\n";
		a = 1;
	}
};

void Parabola::setb(float t) { b = t; };

void Parabola::setc(float t) { c = t; };

void  Parabola::findVertex()
{
	findVertexX();
	findVertexY();
};

void Parabola::setall(float t, float m, float p) {
	a = t;
	if (!a) {
		cout << "This parabola doesn't exist\n";
		a = 1;
	}
	b = m;
	c = p;
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
