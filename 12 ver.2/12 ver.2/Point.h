#pragma once
#include <iostream>

class Point
{
	int x;
	int y;

public:
	// Конструкторы, деструктор
	Point();
	Point(int x);
	Point(int x, int y);

	// Копирование
	Point& operator=(int);

	// Арифметические операции
	Point operator+(int) const;
	Point operator-(int) const;
	Point operator*(int) const;
	Point operator/(int) const;
	Point operator-() const;

	// Операторы сравнения
	bool operator>(const Point&) const;
	bool operator<(const Point&) const;
	bool operator>=(const Point&) const;
	bool operator<=(const Point&) const;

	// Геттеры
	int GetX() const { return x; }
	int GetY() const { return y; }
	
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

/*Пергрезка функций*/
Point operator+(int, const Point&);
Point operator-(int, const Point&);
Point operator*(int, const Point&);
Point operator/(int, const Point&);
