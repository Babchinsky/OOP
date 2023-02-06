#pragma once
#include <iostream>
#include "MyString/MyString.h"


class var
{
	int Int; // целочисленное значение
	double Double; // значение с плавающей точкой
	MyString Str; // строка
	short varType; // тип переменной

public:

	/*CONSTRUCTORS*/ 
	var();
	var(int value);
	var(double value);
	var(const char* str);
	var(const MyString& str);
	var(const var& obj);

	/*OPERATORS*/

	operator int();
	operator double();
	operator const char* ();

	var& operator=(int value);
	var& operator=(double value);
	var& operator=(const MyString& str);
	var& operator=(const char* str);
	var& operator=(const var& obj);

	var operator+(int value) const;
	var operator+(double value) const;
	var operator+(const MyString& str) const;
	var operator+(const char* str) const;
	var operator+(const var& obj) const;

	var operator-(int value) const;
	var operator-(double value) const;
	var operator-(const MyString& str) const;
	var operator-(const char* str) const;
	var operator-(const var& obj) const;
	
	var operator*(int value) const;
	var operator*(double value) const;
	var operator*(const MyString& str) const;
	var operator*(const char* str) const;
	var operator*(const var& obj) const;
	
	var operator/(int value) const;
	var operator/(double value) const;
	var operator/(const MyString& str) const;
	var operator/(const char* str) const;
	var operator/(const var& obj) const;

	var& operator+=(int value);
	var& operator+=(double value);
	var& operator+=(const MyString& str);
	var& operator+=(const char* str);
	var& operator+=(const var& obj);
	
	var& operator-=(int value);
	var& operator-=(double value);
	var& operator-=(const MyString& str);
	var& operator-=(const char* str);
	var& operator-=(const var& obj);
	
	var& operator*=(int value);
	var& operator*=(double value);
	var& operator*=(const MyString& str);
	var& operator*=(const char* str);
	var& operator*=(const var& obj);
	
	var& operator/=(int value);
	var& operator/=(double value);
	var& operator/=(const MyString& str);
	var& operator/=(const char* str);
	var& operator/=(const var& obj);

	bool operator==(int value) const;
	bool operator==(double value) const;
	bool operator==(const MyString& str) const;
	bool operator==(const char* str) const;
	bool operator==(const var& obj) const;

	bool operator!=(int value) const;
	bool operator!=(double value) const;
	bool operator!=(const MyString& str) const;
	bool operator!=(const char* str) const;
	bool operator!=(const var& obj) const;

	bool operator>(int value) const;
	bool operator>(double value) const;
	bool operator>(const MyString& str) const;
	bool operator>(const char* str) const;
	bool operator>(const var& obj) const;

	bool operator<(int value) const;
	bool operator<(double value) const;
	bool operator<(const MyString& str) const;
	bool operator<(const char* str) const;
	bool operator<(const var& obj) const;

	bool operator>=(int value) const;
	bool operator>=(double value) const;
	bool operator>=(const MyString& str) const;
	bool operator>=(const char* str) const;
	bool operator>=(const var& obj) const;

	bool operator<=(int value) const;
	bool operator<=(double value) const;
	bool operator<=(const MyString& str) const;
	bool operator<=(const char* str) const;
	bool operator<=(const var& obj) const;

	

	int GetInt() const { return Int; }
	double GetDouble() const { return Double; }
	const char* GetConstChar() const 
	{
		char* buffer = new char[Str.MyStrLen() + 1];
		strcpy_s(buffer, Str.MyStrLen() + 1, Str.MyC_Str());
		return buffer;
	}
	MyString GetString() const { return Str; }

	/*OUTPUT FUNC*/
	friend std::ostream& operator<<(std::ostream& os, const var& obj);
};


				/*FUNC OPERATORS*/

/*ARITHMETIC OPERATORS*/

// global operator+
int operator+(int value, const var& obj);
double operator+(double value, const var& obj);
MyString operator+(const MyString& str, const var& obj);
const char* operator+(const char* str, const var& obj);

// global operator-
int operator-(int value, const var& obj);
double operator-(double value, const var& obj);
MyString operator-(const MyString& str, const var& obj);
const char* operator-(const char* str, const var& obj);

// global operator*
int operator*(int value, const var& obj);
double operator*(double value, const var& obj);
MyString operator*(const MyString& str, const var& obj);
const char* operator*(const char* str, const var& obj);

// global operator/
int operator/(int value, const var& obj);
double operator/(double value, const var& obj);
MyString operator/(const MyString& str, const var& obj);
const char* operator/(const char* str, const var& obj);

// global operator==
bool operator==(int value, const var& obj);
bool operator==(double value, const var& obj);
bool operator==(const MyString& str, const var& obj);
bool operator==(const char* str, const var& obj);

// global operator!=
bool operator!=(int value, const var& obj);
bool operator!=(double value, const var& obj);
bool operator!=(const MyString& str, const var& obj);
bool operator!=(const char* str, const var& obj);

// global operator>
bool operator>(int value, const var& obj);
bool operator>(double value, const var& obj);
bool operator>(const MyString& str, const var& obj);
bool operator>(const char* str, const var& obj);

// global operator<
bool operator<(int value, const var& obj);
bool operator<(double value, const var& obj);
bool operator<(const MyString& str, const var& obj);
bool operator<(const char* str, const var& obj);

// global operator>=
bool operator>=(int value, const var& obj);
bool operator>=(double value, const var& obj);
bool operator>=(const MyString& str, const var& obj);
bool operator>=(const char* str, const var& obj);

// global operator<=
bool operator<=(int value, const var& obj);
bool operator<=(double value, const var& obj);
bool operator<=(const MyString& str, const var& obj);
bool operator<=(const char* str, const var& obj);
