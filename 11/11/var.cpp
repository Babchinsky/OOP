#include "var.h"
#include <iostream>
//#include <typeinfo>


using namespace std;

var::var()
{
	typeID = -1;
	_int = NULL;
	_double = NULL;
	_string = nullptr;
}
var::var(const int i)
{
	typeID = 0;
	_int = i;
	_double = NULL;
	_string = nullptr;
}
var::var(const double d)
{
	typeID = 1;
	_int = NULL;
	_double = d;
	_string = nullptr;
}
var::var(const char* s)
{
	typeID = 2;
	_int = NULL;
	_double = NULL; 
	_string = new char[strlen(s) + 1];
	strcpy_s(_string, strlen(s) + 1, s);
}
var::var(const var& obj)
{
	typeID = obj.typeID;
	_int = obj._int;
	_double = obj._double;
	
	if (obj._string != nullptr)
	{
		_string = new char[strlen(obj._string) + 1];
		strcpy_s(_string, strlen(obj._string) + 1, obj._string);
	}
	else _string = nullptr;
}
var::~var()
{
	delete[] _string;
}
void var::Print() const
{
	if (_int != NULL) cout << _int << endl;
	if (_double != NULL) cout << _double << endl;
	if (_string != nullptr) cout << _string << endl;
}

// Set
void var::SetInt(const int i)
{
	typeID = 0;
	_int = i;
	_double = NULL;
	if (_string != nullptr) delete[] _string;
}
void var::SetDouble(const double d)
{
	typeID = 1;
	_int = NULL;
	_double = d;
	if (_string != nullptr) delete[] _string;
}
void var::SetString(const char* s)
{
	typeID = 3;
	_int = NULL;
	_double = NULL;
	if (_string != nullptr) delete[] _string;

	_string = new char[strlen(s) + 1];
	strcpy_s(_string, strlen(s) + 1, s);
}

// Get
int var::GetInt()const
{
	return _int;
}
double var::GetDouble()const
{
	return _double;
}
char* var::GetString()const
{
	return _string;
}

//var& var::operator=(const var& obj)
//{
//	if (this == &obj) return *this;						// если справа тот же объект, то сразу возвращаем
//	if (_string != nullptr) delete[]_string;	// если заполнено, очищаем кучу
//
//	_string = new char[strlen(obj._string) + 1];		// выделяем память
//
//	// глубокое копирование 
//	strcpy_s(_string, strlen(obj._string) + 1, obj._string);
//
//	_int = obj._int;
//	_double = obj._double;
//
//	return *this; // a = b = c; 
//}

//var var::operator+(const int param)const
//{
//	var temp(*this);
//
//	if (_int != NULL) temp._int = temp._int + param;
//	if (_double != NULL) temp._double = temp._double + param;
//
//	if (_string != nullptr)
//	{
//		char buf[100];
//		delete[] temp._string;
//
//		_itoa_s(param, buf, 10);
//
//		temp._string = new char[strlen(_string) + 1]; // + 1 для нуль-терминатора
//		strcpy_s(temp._string, strlen(_string) + 1, _string);
//		strcat_s(temp._string, 16, buf);
//
//		delete[]buf;
//	}
//
//	return temp;
//}