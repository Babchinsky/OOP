#include "../var.h"

// global operator+
int operator+(int value, const var& obj)
{
	var temp = value;
	temp = temp + obj;
	return temp.GetInt();
}

double operator+(double value, const var& obj)
{
	var temp = value;
	temp = temp + obj;
	return temp.GetDouble();
}

MyString operator+(const MyString& str, const var& obj) 
{
	var temp = str;
	temp = temp + obj;
	return temp.GetString();
}

const char* operator+(const char* str, const var& obj)
{
	var temp = str;
	temp = temp + obj;
	return temp.GetConstChar();
}

// global operator-
int operator-(int value, const var& obj)
{
	var temp = value;
	temp = temp - obj;
	return temp.GetInt();
}

double operator-(double value, const var& obj)
{
	var temp = value;
	temp = temp - obj;
	return temp.GetDouble();
}

MyString operator-(const MyString& str, const var& obj)
{
	var temp = str;
	temp = temp - obj;
	return temp.GetString();
}

const char* operator-(const char* str, const var& obj)
{
	var temp = str;
	temp = temp - obj;
	return temp.GetConstChar();
}

// global operator*
int operator*(int value, const var& obj)
{
	var temp = value;
	temp = temp * obj;
	return temp.GetInt();
}

double operator*(double value, const var& obj)
{
	var temp = value;
	temp = temp * obj;
	return temp.GetDouble();
}

MyString operator*(const MyString& str, const var& obj)
{
	var temp = str;
	temp = temp * obj;
	return temp.GetString();
}

const char* operator*(const char* str, const var& obj)
{
	var temp = str;
	temp = temp * obj;
	return temp.GetConstChar();
}

// global operator/
int operator/(int value, const var& obj)
{
	var temp = value;
	temp = temp / obj;
	return temp.GetInt();
}

double operator/(double value, const var& obj)
{
	var temp = value;
	temp = temp / obj;
	return temp.GetDouble();
}

MyString operator/(const MyString& str, const var& obj)
{
	var temp = str;
	temp = temp / obj;
	return temp.GetString();
}

const char* operator/(const char* str, const var& obj)
{
	var temp = str;
	temp = temp / obj;
	return temp.GetConstChar();
}