#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
using namespace std;
void task(char* str, char letter);

//Определить количество слов в строке, которые начинаются на заданную букву.Вывести их на экран.

int main()
{
	char* str = nullptr;
	str = new(nothrow) char[255];
	cout << "Enter string\n";
	cin.getline(str, 255);
	char letter;
	cout << "Enter letter\n";
	cin >> letter;
	task(str, letter);
	delete[] str;
	str = nullptr;
	system("pause");
	return 0;
}
void task(char* str, char letter)
{
	char* word = strtok(str, " .,:;`*/'#&!");
	int count = 0;
	while (word != NULL) {
		if (word[0] == letter) {
			cout << word << " ";
			++count;
		}
		word = strtok(NULL, " .,:;`*/'#&!");
	}
	cout << '\n' << "Count of word starting with  letter " << letter << ", " << count << '\n';
}