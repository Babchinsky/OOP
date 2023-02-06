#pragma once

class Base
{
protected:
	char str[100];
public:
	Base();
	Base(const char* s);
	virtual void Print();
};
class StartWithSpace : public Base
{
public:
	StartWithSpace();
	StartWithSpace(const char* s);
	void Print();
};
class SizeException : public Base
{
public:
	SizeException();
	SizeException(const char* s);
	void Print();
};

//#include <exception>
//using namespace std;
//class MyException :public exception
//{
//private:
//	int dataState;
//public:
//	MyException(const char* msg, const int dataState);
//	int GetDataState();
//};

