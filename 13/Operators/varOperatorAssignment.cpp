#include "../var.h"

/*ASSIGNMENT OPERATORS*/

var& var::operator=(int value)
{
	Int = value;
	Double = 0;
	Str = "\0";
	varType = 0;
	return *this;
}

var& var::operator=(double value)
{
	Double = value;
	Int = 0;
	Str = "\0";
	varType = 1;
	return *this;
}

var& var::operator=(const char* str)
{
	Str = str;
	Int = 0;
	Double = 0;
	varType = 2;
	return *this;
}

var& var::operator=(const MyString& str)
{
	Str = str;
	Int = 0;
	Double = 0;
	varType = 2;
	return *this;
}

var& var::operator=(const var& obj)
{
	if (this == &obj || this->varType == -1)
		return *this;

	Int = obj.Int;
	Double = obj.Double;
	Str = obj.Str;
	varType = obj.varType;
	return *this;
}