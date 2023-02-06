#pragma once //препроцессорная директива, разработанная 
//для контроля за тем, чтобы конкретный исходный файл 
//при компиляции подключался строго один раз.

class Date	// Файл дизайна (класс+прототипы)
{
private: // Реализация
	short day;
	short month;
	short year;
	short day_limit;			// максимальное число дней в месяце

	// const, ибо не меняем объект	
	int EnterNumber()const;		// Просит ввести до тех пор, пока не введём число
	void CheckDate()const;		// Проверяет дату
public: // Интерфейс
	Date();						// Конструктор по умолчанию
	Date(short);				// Конструктор с 1 параметром (днём)
	Date(short, short);			// Конструктор с 2 параметрами (день и месяц)
	Date(short, short, short);	// Конструктор с 3 параметрами (день, месяц, год)
	~Date();					// Деструктор

	// Аксессоры
	// Геттеры
	short GetDay()const;	// const, ибо не меняем объект
	short GetMonth()const;	// Возвращает значение
	short GetYear()const;
	short GetDayLimit()const;

	// Сеттеры
	void SetDay(short);
	void SetMonth(short);	// Переназначает на параметр
	void SetYear(short);
	void SetDayLimit();		// Ищет предел дней, исходя из месяца и года

	// Ввод с клавиатуры
	void InputYear();			// Ввод года с клавиатуры(с проверкой)
	void InputMonth();			// Ввода месяца с клавиатуры(с проверкой)
	void InputDay();			// Ввода дня с клавиатуры(с проверкой)
	void Input();				// Ввода всего

	// const, ибо не меняем объект
	void Print()const;					// Вывод в консоль
};

// Операторные функции
// ++объект (сначала считаем, потом присваиваем)
Date& operator++(Date&);
// объект++	(сначала присваиваем, потом считаем)
Date operator++(Date&, int);
// --объект (сначала считаем, потом присваиваем)
Date& operator--(Date&);
// объект-- (сначала присваиваем, потом считаем)
Date operator--(Date&, int);


// дни + объект справа
Date operator+(const int, const Date&);
// дни - бъект справа
Date operator-(const int, const Date&);
// объект слева - дата из параметрова
Date operator-(const Date&, const Date&);
// объект слева += дни
Date& operator+=(Date&, const int);
// объект слева -= дни
Date& operator-=(Date&, const int);


// Сравнение дат
// объект слева > даты справа
bool operator>(const Date&, const Date&);
// объект слева < даты справа
bool operator<(const Date&, const Date&);
// объект слева >= даты справа
bool operator>=(const Date&, const Date&);
// объект слева <= даты справа
bool operator<=(const Date&, const Date&);
// true, если объект слева == даты справа
bool operator==(const Date&, const Date&);
// true, если объект слева != даты справа
bool operator!=(const Date&, const Date&);