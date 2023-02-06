#include "../var.h"

// global operator==
bool operator==(int value, const var& obj)
{
	return (obj == value);
}

bool operator==(double value, const var& obj)
{
	return (obj == value);
}

bool operator==(const MyString& str, const var& obj)
{
	return (obj == str);
}

bool operator==(const char* str, const var& obj)
{
	return (obj == str);
}

// global operator!=
bool operator!=(int value, const var& obj)
{
	return (obj != value);
}

bool operator!=(double value, const var& obj)
{
	return (obj != value);
}

bool operator!=(const MyString& str, const var& obj)
{
	return (obj != str);
}

bool operator!=(const char* str, const var& obj)
{
	return (obj != str);
}

// global operator>
bool operator>(int value, const var& obj)
{
	return (obj < value);
}

bool operator>(double value, const var& obj)
{
	return (obj < value);
}

bool operator>(const MyString& str, const var& obj)
{
	return (obj < str);
}

bool operator>(const char* str, const var& obj)
{
	return (obj < str);
}

// global operator<
bool operator<(int value, const var& obj)
{
	return (obj > value);
}

bool operator<(double value, const var& obj)
{
	return (obj > value);
}

bool operator<(const MyString& str, const var& obj)
{
	return (obj > str);
}

bool operator<(const char* str, const var& obj)
{
	return (obj > str);
}

// global operator>=
bool operator>=(int value, const var& obj)
{
	return (obj <= value);
}

bool operator>=(double value, const var& obj)
{
	return (obj <= value);
}

bool operator>=(const MyString& str, const var& obj)
{
	return (obj <= str);
}

bool operator>=(const char* str, const var& obj)
{
	return (obj <= str);
}

// global operator<=
bool operator<=(int value, const var& obj)
{
	return (obj >= value);
}

bool operator<=(double value, const var& obj)
{
	return (obj >= value);
}

bool operator<=(const MyString& str, const var& obj)
{
	return (obj >= str);
}

bool operator<=(const char* str, const var& obj)
{
	return (obj >= str);
}
