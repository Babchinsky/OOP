#include <iostream>		// cтандартная библиотеку ввода/вывода
#include "Date.h"		// подключаем свой заголовочный файл реализации
using namespace std;	// подключаем пространство имён std дабы не писать каждый раз std::

int main()
{
	Date date1(28, 2, 2019);

	date1.Print();
	cout << endl << endl;

	Date date2 = 5 + date1;                  // Работает
	date1.Print();
	cout << endl << endl;
	date2.Print();
	cout << endl << endl;
}