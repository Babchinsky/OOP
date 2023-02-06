#include "var.h"

/*CONSTRUCTORS*/

var::var() : Int(0), Double(0.0), Str('\0'), varType(2) {}

var::var(int value) : var()
{
	varType = 0;
	Int = value;
}

var::var(double value) : var()
{
	varType = 1;
	Double = value;
}

var::var(const char* str) : var()
{
	varType = 2;
	Str = str;
}

var::var(const MyString& str) : var()
{
	varType = 2;
	Str = str;
}

var::var(const var& obj)
{
	Int = obj.Int;
	Double = obj.Double;
	Str = obj.Str;
	varType = obj.varType;
}