#include "../var.h"

// operator+=
var& var::operator+=(int value)
{
	*this = *this + value;
	return *this;
}

var& var::operator+=(double value)
{
	*this = *this + value;
	return *this;
}

var& var::operator+=(const MyString& str)
{
	*this = *this + str;
	return *this;
}

var& var::operator+=(const char* str)
{
	*this = *this + str;
	return *this;
}

var& var::operator+=(const var& obj)
{
	*this = *this + obj;
	return *this;
}

// operator-=
var& var::operator-=(int value)
{
	*this = *this - value;
	return *this;
}

var& var::operator-=(double value)
{
	*this = *this - value;
	return *this;
}

var& var::operator-=(const MyString& str)
{
	*this = *this - str;
	return *this;
}

var& var::operator-=(const char* str)
{
	*this = *this - str;
	return *this;
}

var& var::operator-=(const var& obj)
{
	*this = *this - obj;
	return *this;
}

// operator*=
var& var::operator*=(int value)
{
	*this = *this * value;
	return *this;
}

var& var::operator*=(double value)
{
	*this = *this * value;
	return *this;
}

var& var::operator*=(const MyString& str)
{
	*this = *this * str;
	return *this;
}

var& var::operator*=(const char* str)
{
	*this = *this * str;
	return *this;
}

var& var::operator*=(const var& obj)
{
	*this = *this * obj;
	return *this;
}

// operator/=
var& var::operator/=(int value)
{
	*this = *this / value;
	return *this;
}

var& var::operator/=(double value)
{
	*this = *this / value;
	return *this;
}

var& var::operator/=(const MyString& str)
{
	*this = *this / str;
	return *this;
}

var& var::operator/=(const char* str)
{
	*this = *this / str;
	return *this;
}

var& var::operator/=(const var& obj)
{
	*this = *this / obj;
	return *this;
}
