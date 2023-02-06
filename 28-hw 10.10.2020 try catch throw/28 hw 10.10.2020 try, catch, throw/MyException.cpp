#include "MyException.h"
#include <iostream>
using namespace std;

Base::Base() { 
	strcpy_s(str, strlen("Default") + 1, "Default");
}
Base::Base(const char* s)
	{
		strcpy_s(str, strlen(s) + 1, s);
	}
void Base::Print()
	{
		cout << str << endl;
	}

StartWithSpace::StartWithSpace() {}
StartWithSpace::StartWithSpace(const char* s) :Base(s){}
void StartWithSpace::Print() { cout << "StartWithSpace\n"; }

SizeException::SizeException() { }
SizeException::SizeException(const char* s) :Base(s) {}
void SizeException::Print()
{
	cout << "SizeException\n";
	cout << str << endl;
}
