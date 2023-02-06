#include <iostream>		// cтандартная библиотеку ввода/вывода
#include "Date.h"		// подключаем свой заголовочный файл реализации
using namespace std;	// подключаем пространство имён std дабы не писать каждый раз std::

int main()
{
	Date date1(1, 2, 2013);
	//Date date2(1, 1, 2017);
	date1.Input();
	date1.Print();
	cout << endl << endl;
	//date2.Print();
	/*Date date2 = --date1;
	date2.Print();

	Date date3 = date1--;
	date3.Print();*/
	//Date date2 = date1 + 10;

	/*Date date2 = date1 - 10;
	date2.Print();*/

	/*date1 += 20;
	date1.Print();*/

	/*date1 -= 20;
	date1.Print();*/



	/*Date date3 = date1 - date2;\
	cout << endl << endl;
	date3.Print();*/

	/*bool isTrue = date1 < date2;
	cout << isTrue;*/

}