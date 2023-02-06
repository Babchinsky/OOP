#include "../var.h"

// operator==
bool var::operator==(int value) const
{
	if (varType == -1)
		return false;
	else if (varType == 0)
		return Int == value;
	else if (varType == 1)
		return Double == (double)value;
	else if (varType == 2)
	{
		char buffer[80];
		_itoa_s(value, buffer, 80, 10);
		if (Str.MyStrCmp(MyString(buffer)) == 0)
			return true;
		else
			return false;
	}
	return false;
}

bool var::operator==(double value) const
{
	if (varType == -1)
		return false;
	else if (varType == 0)
		return Int == (int)value;
	else if (varType == 1)
		return Double == value;
	else if (varType == 2)
	{
		char buffer[80];
		_itoa_s(value, buffer, 80, 10);
		if (Str.MyStrCmp(MyString(buffer)) == 0)
			return true;
		else
			return false;
	}
}

bool var::operator==(const MyString& str) const
{
	if (varType == -1)
		return false;
	else if (varType == 0)
	{
		return Int == atoi(str.MyC_Str());
	}
	else if (varType == 1)
	{
		return Double == strtod(str.MyC_Str(), nullptr);
	}
	else if (varType == 2)
	{
		if (Str.MyStrCmp(str) == 0)
			return true;
		else
			return false;
	}
}

bool var::operator==(const char* str) const
{
	return (*this == MyString(str));
}

bool var::operator==(const var& obj) const
{
	if (obj.varType == 0)
		return *this == obj.Int;
	else if (obj.varType == 1)
		return *this == obj.Double;
	else if (obj.varType == 2)
		return *this == obj.Str;
	else
		return false;
}

// operator!=
bool var::operator!=(int value) const
{
	return !(*this == value);
}

bool var::operator!=(double value) const
{
	return !(*this == value);
}

bool var::operator!=(const MyString& str) const
{
	return !(*this == str);
}

bool var::operator!=(const char* str) const
{
	return !(*this == str);
}

bool var::operator!=(const var& obj) const
{
	return !(*this == obj);
}


// operator>
bool var::operator>(int value) const
{
	if (varType == -1)
		return false;
	else if (varType == 0)
		return Int > value;
	else if (varType == 1)
		return Double > (double)value;
	else if (varType == 2)
	{
		char buffer[80];
		_itoa_s(value, buffer, 80, 10);
		if (Str.MyStrCmp(MyString(buffer)) > 0)
			return true;
		else
			return false;
	}
	return false;
}

bool var::operator>(double value) const
{
	if (varType == -1)
		return false;
	else if (varType == 0)
		return Int > (int)value;
	else if (varType == 1)
		return Double > value;
	else if (varType == 2)
	{
		char buffer[20];
		_itoa_s(int(value * 1000), buffer, 20, 10);
		buffer[strlen(buffer) - 1] = buffer[strlen(buffer) - 2];
		buffer[strlen(buffer) - 2] = buffer[strlen(buffer) - 3];
		buffer[strlen(buffer) - 3] = '.';
		if (Str.MyStrCmp(MyString(buffer)) > 0)
			return true;
		else
			return false;
	}
}

bool var::operator>(const MyString& str) const
{
	if (varType == -1)
		return false;
	else if (varType == 0)
	{
		return Int > atoi(str.MyC_Str());
	}
	else if (varType == 1)
	{
		return Double > strtod(str.MyC_Str(), nullptr);
	}
	else if (varType == 2)
	{
		if (Str.MyStrCmp(str) > 0)
			return true;
		else
			return false;
	}
}

bool var::operator>(const char* str) const
{
	return (*this == MyString(str));
}

bool var::operator>(const var& obj) const
{
	if (obj.varType == 0)
		return *this > obj.Int;
	else if (obj.varType == 1)
		return *this > obj.Double;
	else if (obj.varType == 2)
		return *this > obj.Str;
	else
		return false;
}


// operator<
bool var::operator<(int value) const
{
	return ((*this != value) && !(*this > value));
}

bool var::operator<(double value) const
{
	return ((*this != value) && !(*this > value));

}

bool var::operator<(const MyString& str) const
{
	return ((*this != str) && !(*this > str));

}

bool var::operator<(const char* str) const
{
	return ((*this != str) && !(*this > str));

}

bool var::operator<(const var& obj) const
{
	return ((*this != obj) && !(*this > obj));
}

// operator>=
bool var::operator>=(int value) const
{
	return ((*this > value) || (*this == value));
}

bool var::operator>=(double value) const
{
	return ((*this > value) || (*this == value));
}

bool var::operator>=(const MyString& str) const
{
	return ((*this > str) || (*this == str));
}

bool var::operator>=(const char* str) const
{
	return ((*this > str) || (*this == str));
}

bool var::operator>=(const var& obj) const
{
	return ((*this > obj) || (*this == obj));
}

// operator<=
bool var::operator<=(int value) const
{
	return ((*this < value) || (*this == value));
}

bool var::operator<=(double value) const
{
	return ((*this < value) || (*this == value));
}

bool var::operator<=(const MyString& str) const
{
	return ((*this < str) || (*this == str));
}

bool var::operator<=(const char* str) const
{
	return ((*this < str) || (*this == str));
}

bool var::operator<=(const var& obj) const
{
	return ((*this < obj) || (*this == obj));
}