#include<iostream>
#include<fstream>                      // подключение библиотеки файлового ввода/вывода через потоки
using namespace std;
struct color { unsigned char R; unsigned char G; unsigned char B;} c;
struct tmp { float R; float G; float B; } t;
int main() {
	ifstream fffff("d:\\1.bmp", ios::binary); // отсюда читаем (поток типа ifstream= input file stream)
	ofstream ggggg("d:\\rez.bmp", ios::binary);//сюда пишем (поток типа ofstream= output file stream)
	if (!fffff) { cout << "No file d:\\paint.bmp Can't open\n"; exit(1); }
	if (!ggggg) { cout << "   file d:\\rez.bmp Can't create\n"; exit(1); }
	char buf[30];// куда читать байты
	color c;
	tmp t;
	unsigned int width, height;//надеемся. что тут 4 байта

	float R1, G1, B1;//компоненты цвета
	cout << "Enter params of first color:\n";
	cin >> R1>>G1>>B1;
	cout << "Enter params of second color:\n";
	float R2, G2, B2;
	cin >> R2 >> G2 >> B2;
	float step = 0;
	cout << "Enter step:";
	cin >> step;

	fffff.read((char*)&buf, 18); //читаем куда,сколько
	ggggg.write((char*)&buf, 18);// запись 18 байт
	fffff.read((char*)&width, 4); cout << " width is :" << width;
	fffff.read((char*)&height, 4); cout << "\n height is :" << height;

	width = 400; ggggg.write((char*)&width, 4);
	height =  400; ggggg.write((char*)&height, 4);

	fffff.read((char*)&buf, 28); //читаем куда,сколько
	ggggg.write((char*)&buf, 28);// запись 28 байт
	
	float stepR = (float)((R2 - R1) / step);
	float stepG = (float)((G2 - G1) / step);
	float stepB = (float)((B2 - B1) / step);
	c.R = R1; c.G = G1; c.B = B1; 
	t.R = R1; t.G = G1; t.B = B1;

	int n;
	cout << "\n Choose: 1-horizontal gradient, 2-vertical gradient \n";
	cin >> n;
	switch (n) {
		case 1: 
		{
			if (step > width) step = width;
			float colorstep = width / step;
			float tmpstep = colorstep;
			for (unsigned int i = 1; i <= height; ++i)
			{
				for (unsigned int j = 1; j <= width; ++j)
				{
					if (j == colorstep) 
					{
						colorstep += tmpstep;
						t.R += stepR;
						t.G += stepG;
						t.B += stepB;
					}
					c.R = (unsigned char)t.R;
					c.G = (unsigned char)t.G;
					c.B = (unsigned char)t.B;
					ggggg.write((char*)&c.B, 1);// запись 28 байт
					ggggg.write((char*)&c.G, 1);// запись 28 байт
					ggggg.write((char*)&c.R, 1);// запись 28 байт
				}
				t.R = R1;
				t.G = G1;
				t.B = B1;
				colorstep = tmpstep;
			}
			break;
		}
		case 2: 
		{
			if (step > height) step = height;
			float colorstep =  height / step;
			float tmpstep = colorstep;
			for (unsigned int i = 1; i <= height; i++)
			{
				for (unsigned int j = 1; j <= width; j++)
				{
					c.R = (unsigned char)t.R;
					c.G = (unsigned char)t.G;
					c.B = (unsigned char)t.B;
					ggggg.write((char*)&c.B, sizeof(c.B));// запись 28 байт
					ggggg.write((char*)&c.G, sizeof(c.G));// запись 28 байт
					ggggg.write((char*)&c.R, sizeof(c.R));// запись 28 байт
				}
				if (i == colorstep) 
				{
					t.R += stepR;
					t.G += stepG;
					t.B += stepB;
					colorstep += tmpstep;
				}
				c.R = R1;
				c.G = G1;
				c.B = B1;
			}
			break;
		}
	}

	fffff.close();//закрыли файл
	ggggg.close();//закрыли файл
}
