#include <iostream>			// стандартная библиотека ввода/вывода
#include "MyString.h"		// подключаем файл реализации
using namespace std;

int main()
{
	MyString str1;
	str1.Init("Hello, world!");
	str1.Print();

	MyString str2 = str1;
	str2();

	char* a = str2;
	a[0] = 'W';
	cout << a << endl;

	int len = str2;
	cout << len << endl;

	for (int i = 0; i < str2.MyStrLen(); i++)
		cout << str2[i] << " ";
}