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
	SetDayLimit();		// присваиваем полю значение функции расчёта максимального количества дней в месяце
}
// Конструктор с 1 параметром
Date::Date(short d)
{
	day = d;
	SetDayLimit();		// присваиваем полю значение функции расчёта максимального количества дней в месяце
}
// Конструктор с 2 параметрами
Date::Date(short d, short m) :Date(d)	// используем делегирование конструкторов
{
	month = m;
	SetDayLimit();		// присваиваем полю значение функции расчёта максимального количества дней в месяце
}
// Конструктор с 3 параметрами
Date::Date(short d, short m, short y) :Date(d, m)	// используем делегирование конструкторов
{
	year = y;
	SetDayLimit();		// присваиваем полю значение функции расчёта максимального количества дней в месяцесяце
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
short Date::GetDayLimit()const
{
	return day_limit;
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
void Date::SetDayLimit()
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
void Date::CheckDate()const
{	// проверка для инициализации
	if ((day < 1 || day > day_limit) ||
		(month < 1 || month > 12)) cout << "Date is incorrect!!!";
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
	SetDayLimit();  // присваиваем полю значение функции расчёта максимального количества дней в месяце		// присваиваем полю значение функции расчёта максимального количества дней в месяце
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


// Операторные функции
// ++объект (сначала считаем, потом присваиваем)
Date& operator++(Date& obj)
{
	cout << "LOL" << endl;
	if (obj.GetDay() < obj.GetDayLimit()) obj.SetDay(obj.GetDay() + 1);	// если день меньше, чем дней в месяце, то увеличиваем день на 1
	else											// если нет, то переходим в новый месяй
	{
		obj.SetDay(1);
		if (obj.GetMonth() == 12)
		{
			obj.SetMonth(1);
			obj.SetYear(obj.GetYear() + 1); // если месяц последний, то переходим в новый год
		}
		else obj.SetMonth(obj.GetMonth() + 1);
	}
	obj.SetDayLimit();
	return obj;
}
// объект++	(сначала присваиваем, потом считаем)
Date operator++(Date& obj, int)
{
	cout << "KEK" << endl;
	Date temp(obj); // начальное состояние
	if (obj.GetDay() < obj.GetDayLimit()) obj.SetDay(obj.GetDay() + 1);
	else
	{
		obj.SetDay(1);
		if (obj.GetMonth() == 12)
		{
			obj.SetMonth(1);
			obj.SetYear(obj.GetYear() + 1);
		}
		else obj.SetMonth(obj.GetMonth() + 1);
	}
	obj.SetDayLimit();
	return temp;
}
// --объект (сначала считаем, потом присваиваем)
Date& operator--(Date& obj)
{
	if (obj.GetDay() > 1) obj.SetDay(obj.GetDay() - 1);
	else
	{
		if (obj.GetMonth() == 1)
		{
			obj.SetYear(obj.GetYear() - 1);
			obj.SetMonth(12);
			obj.SetDay(31);
		}
		else
		{
			obj.SetMonth(obj.GetDay() - 1);
			obj.SetDayLimit();
			obj.SetDay(obj.GetDayLimit());// обновляем максимальное количество дней в месяце
		}
	}
	return obj;
}
// объект-- (сначала присваиваем, потом считаем)
Date operator--(Date& obj, int)
{
	Date temp(obj); // начальное состояние	
	if (obj.GetDay() > 1) obj.SetDay(obj.GetDay() - 1);
	else
	{
		if (obj.GetMonth() == 1)
		{
			obj.SetYear(obj.GetYear() - 1);
			obj.SetMonth(12);
			obj.SetDay(31);
		}
		else
		{
			obj.SetMonth(obj.GetMonth() - 1);
			obj.SetDayLimit();
			obj.SetDay(obj.GetDayLimit());// обновляем максимальное количество дней в месяце
		}
	}
	return temp;
}

// дни + объект справа
Date operator+(const int days, const Date& obj)
{
	Date temp(obj);
	for (size_t i = 0; i < days; i++)
	{
		if (temp.GetDay() == temp.GetDayLimit())
		{
			temp.SetDay(1);
			if (temp.GetMonth() == 12)
			{
				temp.SetYear(temp.GetYear() + 1);
				temp.SetMonth(1);
			}
			else temp.SetMonth(temp.GetMonth() + 1);
		}
		else temp.SetDay(temp.GetDay() + 1);
		temp.SetDayLimit();// обновляем максимальное количество дней в месяце
	}
	return temp;
}
// дни - бъект справа
Date operator-(const int days, const Date& obj)
{
	Date temp(obj);
	for (size_t i = 0; i < days; i++)
	{
		if (temp.GetDay() == 1)
		{
			if (temp.GetMonth() == 1)
			{
				temp.SetYear(temp.GetYear() - 1);
				temp.SetMonth(12);
			}
			else temp.SetMonth(temp.GetMonth() - 1);
			temp.SetDayLimit();
			temp.SetDay(temp.GetDayLimit());// обновляем максимальное количество дней в месяце
		}
		else temp.SetDay(temp.GetDay() - 1);
	}
	return temp;
}
// объект слева - дата из параметрова
Date operator-(const Date& obj1, const Date& obj2) // obj1 - obj2
{
	Date temp(obj1);

	temp.SetYear(temp.GetYear() - obj2.GetYear());

	if (temp.GetMonth() > obj2.GetMonth()) temp.SetMonth(temp.GetMonth() - obj2.GetMonth());
	else
	{
		temp.SetYear(temp.GetYear() - 1);
		temp.SetMonth(12 + (temp.GetMonth() - obj2.GetMonth()));
	}

	if (temp.GetDay() > obj2.GetDay()) temp.SetDay(temp.GetDay() - obj2.GetDay());
	else
	{
		if (temp.GetMonth() == 1)
		{
			temp.SetYear(temp.GetYear() - 1);
			temp.SetMonth(12);
		}
		else temp.SetMonth(temp.GetMonth() - 1);

		temp.SetDayLimit();
		temp.SetDay(temp.GetDayLimit() + (temp.GetDay() - obj2.GetDay()));// обновляем максимальное количество дней в месяц
	}

	return temp;
}
// объект слева += дни
Date& operator+=(Date& obj, const int days)
{
	for (size_t i = 0; i < days; i++)
	{
		if (obj.GetDay() == obj.GetDayLimit())
		{
			obj.SetDay(1);
			if (obj.GetMonth() == 12)
			{
				obj.SetYear(obj.GetYear() + 1);
				obj.SetMonth(1);
			}
			else obj.SetMonth(obj.GetMonth() + 1);
		}
		else obj.SetDay(obj.GetDay() + 1);

		obj.SetDayLimit();
	}

	return obj;
}
// объект слева -= дни
Date& operator-=(Date& obj, const int days)
{
	for (size_t i = 0; i < days; i++)
	{
		if (obj.GetDay() == 1)
		{
			if (obj.GetMonth() == 1)
			{
				obj.SetYear(obj.GetYear() - 1);
				obj.SetMonth(12);
			}
			else obj.SetMonth(obj.GetMonth() - 1);
			obj.SetDayLimit();
			obj.SetDay(obj.GetDayLimit());// обновляем максимальное количество дней в месяце
		}
		else obj.SetDay(obj.GetDay() - 1);
	}

	return obj;
}


// Сравнение дат
// объект слева > даты справа
bool operator>(const Date& obj1, const Date& obj2)
{
	if (obj1.GetYear() > obj2.GetYear()) return true;
	else if (obj1.GetYear() == obj2.GetYear())
	{
		if (obj1.GetMonth() > obj2.GetMonth()) return true;
		else if (obj1.GetMonth() == obj2.GetMonth())
		{
			if (obj1.GetDay() > obj2.GetDay()) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
// объект слева < даты справа
bool operator<(const Date& obj1, const Date& obj2)
{
	if (obj1.GetYear() > obj2.GetYear()) return false;
	else if (obj1.GetYear() == obj2.GetYear())
	{
		if (obj1.GetMonth() > obj2.GetMonth()) return false;
		else if (obj1.GetMonth() == obj2.GetMonth())
		{
			if (obj1.GetDay() >= obj2.GetDay()) return false;
			else return true;
		}
		else return true;
	}
	else return true;
}
// объект слева >= даты справа
bool operator>=(const Date& obj1, const Date& obj2)
{
	if (obj1.GetYear() > obj2.GetYear()) return true;
	else if (obj1.GetYear() == obj2.GetYear())
	{
		if (obj1.GetMonth() > obj2.GetMonth()) return true;
		else if (obj1.GetMonth() == obj2.GetMonth())
		{
			if (obj1.GetDay() >= obj2.GetDay()) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
// объект слева <= даты справа
bool operator<=(const Date& obj1, const Date& obj2)
{
	if (obj1.GetYear() > obj2.GetYear()) return false;
	else if (obj1.GetYear() == obj2.GetYear())
	{
		if (obj1.GetMonth() > obj2.GetMonth()) return false;
		else if (obj1.GetMonth() == obj2.GetMonth())
		{
			if (obj1.GetDay() > obj2.GetDay()) return false;
			else return true;
		}
		else return true;
	}
	else return true;
}
// true, если объект слева == даты справа
bool operator==(const Date& obj1, const Date& obj2)
{
	if (obj1.GetDay() == obj2.GetDay() && obj1.GetMonth() == obj2.GetMonth() && obj1.GetYear() == obj2.GetYear()) return true;
	else return false;
}
// true, если объект слева != даты справа
bool operator!=(const Date& obj1, const Date& obj2)
{
	if (obj1.GetDay() == obj2.GetDay() && obj1.GetMonth() == obj2.GetMonth() && obj1.GetYear() == obj2.GetYear()) return false;
	else return true;
}