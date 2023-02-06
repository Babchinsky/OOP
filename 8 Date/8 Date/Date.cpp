#include <iostream>	// стандартная библиотека ввода/вывода
#include "Date.h"	// подключаем свой заголовочный файл реализации
using namespace std;// подключаем пространство имён std дабы не писать каждый раз std::

// Конструкторы, деструкторы
// Конструктор по умолчанию
Date::Date()
{
	day = 1;
	month = 1;
	year = 2022;
	this->GetDayLimit();	// присваиваем полю значение функции расчёта максимального количества дней в месяце
}
// Конструктор с 1 параметром
Date::Date(short d)
{
	day = d;
	this->GetDayLimit();		// присваиваем полю значение функции расчёта максимального количества дней в месяце
}
// Конструктор с 2 параметрами
Date::Date(short d, short m):Date(d)	// используем делегирование конструкторов
{
	month = m;
	this->GetDayLimit();		// присваиваем полю значение функции расчёта максимального количества дней в месяце
}
// Конструктор с 3 параметрами
Date::Date(short d, short m, short y):Date(d, m)	// используем делегирование конструкторов
{
	year = y;
	this->GetDayLimit();		// присваиваем полю значение функции расчёта максимального количества дней в месяце
}
// Деструктор
Date::~Date()
{
	day = 0;
	month = 0;
	year = 0;
	day_limit = 0;
}


// Аксессоры. Get
short Date::GetYear()const
{
	return year;
}
short Date::GetMonth()const
{
	return month;
}
short Date::GetDay()const
{
	return day;
}
// Аксессоры. Set
void Date::SetDay(short d)
{
	day = d;
}
void Date::SetMonth(short m)
{
	month = m;
}
void Date::SetYear(short y)
{
	year = y;
}

// Проверки
int Date::EnterNumber()const
{
	int verifiable;

	while (true)
	{
		cin >> verifiable;

		if (!cin.good())	// если ввели не число
		{
			cin.clear();	// очищаем поток cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Чистит
			cout << "Not a number. Please enter again: :\n";
		}
		else return verifiable; // если ввели число, то возвращает число
	}
}
void Date::GetDayLimit()
{
	// Cчитаем предел дня
	switch (month)
	{
	case 2:	// для февраля формула, рассчитывающая високосный или не високосный год
		day_limit = (year % 400 == 0) ? 29 : (year % 100 != 0 && year % 4 == 0) ? 29 : 28;
		break;
	case 4:	// апрель
	case 6:	// июнь
	case 9:	// август
	case 11:// ноябрь
		day_limit = 30;
		break;
	default:;// остальные месяцы
		day_limit = 31;
		break;
	}
}
void Date::CheckDate()const
{	// проверка для инициализации
	if ( (day < 1 || day > day_limit)  || 
		(month < 1 || month > 12) ) cout << "Date is incorrect!!!";
}

void Date::InputYear()
{
	cout << "Enter year: ";
	year = EnterNumber();

}
void Date::InputMonth()
{
	cout << "Enter month: ";

	while (true)		// выполняется, пока не введём правильно
	{
		month = EnterNumber();
		if (month < 1 || month > 12) cout << "Error. Enter from 1 to 12: ";
		else return;
	}
}
void Date::InputDay()
{
	this->GetDayLimit();
	cout << "Enter day: ";
	while (true)	// выполняется, пока не введём правильно
	{
		day = EnterNumber();
		if (day < 1 || day > day_limit) cout << "Error. Enter a day from 1 to: " << day_limit << ": ";
		else return;
	}
}
void Date::Input()
{
	InputYear();
	InputMonth();
	InputDay();
}


// Вывод в консоль
void Date::Print()const
{
	const short NUMBER_OF_MONTH = 12;
	const short MAX_LENGTH = 10;

	char month_arr[NUMBER_OF_MONTH][MAX_LENGTH]	// двумерный символьный массив с наименованиями месяцев
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};

	
	cout << day << " ";
	cout << month_arr[month - 1] << " "; 	// - 1 так как нумерация массива от 0
	cout << abs(year);
	if (year < 0) cout << " BC";		// Если год отрацательный, то выводим до нашей эры
	cout << "\nMax days in month: " << day_limit << endl;
	CheckDate();
}

// Операторные методы
// ++объект (сначала считаем, потом присваиваем)
Date& Date::operator++()
{
	if (day < day_limit) day++;					// если день меньше, чем дней в месяце, то увеличиваем день на 1
	else                                        // если нет, то переходим в новый месяй
	{
		day = 1;			
		if (month == 12) { month = 1; year++; }	// если месяц последний, то переходим в новый год
		else month++;
	}
	return *this;
}
// объект++	(сначала присваиваем, потом считаем)
Date Date::operator++(int)
{
	Date temp(*this); // начальное состояние	
	if (day < day_limit) day++;
	else
	{
		day = 1;
		if (month == 12) { month = 1; year++; }
		else month++;
	}
	return temp;
}
// --объект (сначала считаем, потом присваиваем)
Date& Date::operator--()
{
	if (day > 1) day--;
	else
	{
		if (month == 1) 
		{
			year--;
			month = 12;
			day = 31;
		}
		else
		{
			month--;
			this->GetDayLimit();	// обновляем максимальное количество дней в месяце
			day = day_limit;
		}
	}
	return *this;
}
// объект-- (сначала присваиваем, потом считаем)
Date Date::operator--(int)
{
	Date temp(*this); // начальное состояние	
	if (day > 1) day--;
	else
	{
		if (month == 1)
		{
			year--;
			month = 12;
			day = 31;
		}
		else
		{
			month--;
			this->GetDayLimit();// обновляем максимальное количество дней в месяце
			day = day_limit;
		}
	}
	return temp;
}

// объект слева + дни
Date Date::operator+(const int days)const
{
	Date temp(*this); // начальное состояние	
	for (size_t i = 0; i < days; i++)
	{
		if (temp.day == day_limit)
		{
			temp.day = 1; 
			if (temp.month == 12)
			{
				temp.year++;
				temp.month = 1;
			}
			else temp.month++;
		}
		else temp.day++;
		temp.GetDayLimit();// обновляем максимальное количество дней в месяце
	}
	return temp;
}
// объект слева - дни
Date Date::operator-(const int days)const
{
	Date temp(*this); // начальное состояние	
	for (size_t i = 0; i < days; i++)
	{
		if (temp.day == 1)
		{
			if (temp.month == 1)
			{
				temp.year--;
				temp.month = 12;
			}
			else temp.month--;
			temp.GetDayLimit();// обновляем максимальное количество дней в месяце
			temp.day = day_limit;
		}
		else temp.day--;
	}
	return temp;
}

// объект слева - дата из параметрова
Date Date::operator-(const Date& obj)const // a+obj
{
	Date temp(*this); // начальное состояние	
	temp.year -= obj.year;

	if (temp.month > obj.month) temp.month -= obj.month;
	else
	{
		temp.year--;
		temp.month = 12 + (temp.month - obj.month);
	}
	
	if (temp.day > obj.day) temp.day -= obj.day;
	else
	{
		if (temp.month == 1)
		{
			temp.year--;
			temp.month = 12;
		}
		else temp.month--;

		temp.GetDayLimit();// обновляем максимальное количество дней в месяце
		temp.day = day_limit + (temp.day - obj.day);
	}
	
	return temp;
}

// объект слева += дни
Date& Date::operator+=(const int days)
{
	for (size_t i = 0; i < days; i++)
	{
		if (day == day_limit)
		{
			day = 1;
			if (month == 12)
			{
				year++;
				month = 1;
			}
			else month++;
		}
		else day++;
		this->GetDayLimit();// обновляем максимальное количество дней в месяце
	}

	return *this;
}
// объект слева -= дни
Date& Date::operator-=(const int days)
{
	for (size_t i = 0; i < days; i++)
	{
		if (day == 1)
		{
			if (month == 1)
			{
				year--;
				month = 12;
			}
			else month--;
			this->GetDayLimit();// обновляем максимальное количество дней в месяце
			day = day_limit;
		}
		else day--;
	}

	return *this;
}

// Сравнение дат
// объект слева > даты справа
bool Date::operator>(const Date& obj)
{
	if (year > obj.year) return true;
	else if (year == obj.year)
	{
		if (month > obj.month) return true;
		else if (month == obj.month)
		{
			if (day > obj.day) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
// объект слева < даты справа
bool Date::operator<(const Date& obj)
{
	if (year > obj.year) return false;
	else if (year == obj.year)
	{
		if (month > obj.month) return false;
		else if (month == obj.month)
		{
			if (day >= obj.day) return false;
			else return true;
		}
		else return true;
	}
	else return true;
}
// объект слева >= даты справа
bool Date::operator>=(const Date& obj)
{
	if (year > obj.year) return true;
	else if (year == obj.year)
	{
		if (month > obj.month) return true;
		else if (month == obj.month)
		{
			if (day >= obj.day) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}	
// объект слева <= даты справа
bool Date::operator<=(const Date& obj)
{
	if (year > obj.year) return false;
	else if (year == obj.year)
	{
		if (month > obj.month) return false;
		else if (month == obj.month)
		{
			if (day > obj.day) return false;
			else return true;
		}
		else return true;
	}
	else return true;
}	
// true, если объект слева == даты справа
bool Date::operator==(const Date& obj)
{
	if (day == obj.day && month == obj.month && year == obj.year) return true;
	else return false;
}	
// true, если объект слева != даты справа
bool Date::operator!=(const Date& obj)
{
	if (day != obj.day && month != obj.month && year != obj.year) return true;
	else return false;
}