#include "../var.h"

// operator+
var var::operator+(int value) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = value;
	else if (temp.varType == 0)
		temp.Int = temp.Int + value;
	else if (temp.varType == 1)
		temp.Double = temp.Double + (double)value;
	else if (temp.varType == 2)
	{
		char buffer[20];
		_itoa_s(value, buffer, 20, 10);
		temp.Str.MyStrCat(buffer);
	}
	return temp;
}

var var::operator+(double value) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = value;
	else if (temp.varType == 0)
		temp.Int = temp.Int + (int)value;
	else if (temp.varType == 1)
		temp.Double = temp.Double + value;
	else if (temp.varType == 2)
	{
		char buffer[20];
		_itoa_s(int(value * 1000), buffer, 20, 10);
		buffer[strlen(buffer) - 1] = buffer[strlen(buffer) - 2];
		buffer[strlen(buffer) - 2] = buffer[strlen(buffer) - 3];
		buffer[strlen(buffer) - 3] = '.';
		temp.Str.MyStrCat(buffer);
	}
	return temp;
}

var var::operator+(const MyString& str) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = str;
	else if (temp.varType == 0)
	{
		temp.Int = temp.Int + atoi(str.MyC_Str());
	}
	else if (temp.varType == 1)
	{
		temp.Double = temp.Double + strtod(str.MyC_Str(), nullptr);
	}
	else if (temp.varType == 2)
	{
		temp.Str.MyStrCat(str);
	}
	return temp;
}

var var::operator+(const char* str) const
{
	return (*this + MyString(str));
}

var var::operator+(const var& obj) const
{
	var temp(*this);
	if (obj.varType == 0)
		temp = temp + obj.Int;
	else if (obj.varType == 1)
		temp = temp + obj.Double;
	else if (obj.varType == 2)
		temp = temp + obj.Str;

	return temp;
}

// operator-
var var::operator-(int value) const
{
	if (this->varType == 2)
		return *this;

	var temp(*this);
	if (temp.varType == -1)
		temp = value;
	else if (temp.varType == 0)
		temp.Int = temp.Int - value;
	else if (temp.varType == 1)
		temp.Double = temp.Double - (double)value;
	return temp;
}

var var::operator-(double value) const
{
	if (this->varType == 2)
		return *this;

	var temp(*this);
	if (temp.varType == -1)
		temp = value;
	else if (temp.varType == 0)
		temp.Int = temp.Int - (int)value;
	else if (temp.varType == 1)
		temp.Double = temp.Double - value;
	return temp;
}

var var::operator-(const MyString& str) const
{
	if (this->varType == 2)
		return *this;

	var temp(*this);
	if (temp.varType == -1)
		temp = str;
	else if (temp.varType == 0)
	{
		temp.Int = temp.Int - atoi(str.MyC_Str());
	}
	else if (temp.varType == 1)
	{
		temp.Double = temp.Double - strtod(str.MyC_Str(), nullptr);
	}
	return temp;
}

var var::operator-(const char* str) const
{
	return(*this - MyString(str));
}

var var::operator-(const var& obj) const
{
	var temp(*this);
	if (obj.varType == 0)
		temp = temp - obj.Int;
	else if (obj.varType == 1)
		temp = temp - obj.Double;
	else if (obj.varType == 2)
		temp = temp - obj.Str;

	return temp;
}

// operator*
var var::operator*(int value) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = value;
	else if (temp.varType == 0)
		temp.Int = temp.Int * value;
	else if (temp.varType == 1)
		temp.Double = temp.Double * (double)value;
	return temp;
}

var var::operator*(double value) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = value;
	else if (temp.varType == 0)
		temp.Int = temp.Int * (int)value;
	else if (temp.varType == 1)
		temp.Double = temp.Double * value;
	return temp;
}

var var::operator*(const MyString& str) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = str;
	else if (temp.varType == 0)
	{
		temp.Int = temp.Int * atoi(str.MyC_Str());
	}
	else if (temp.varType == 1)
	{
		temp.Double = temp.Double * strtod(str.MyC_Str(), nullptr);
	}
	else if (temp.varType == 2)
	{
		for (int i = 0; i < temp.Str.MyStrLen(); i++)
		{
			if (str.MyChr(temp.Str[i]) == -1)
			{
				temp.Str.MyDelChr(temp.Str[i]);
				i = 0;
			}
		}
	}
	return temp;
}

var var::operator*(const char* str) const
{
	return (*this * MyString(str));
}

var var::operator*(const var& obj) const
{
	var temp(*this);
	if (obj.varType == 0)
		temp = temp * obj.Int;
	else if (obj.varType == 1)
		temp = temp * obj.Double;
	else if (obj.varType == 2)
		temp = temp * obj.Str;

	return temp;
}

// operator/
var var::operator/(int value) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = value;
	else if (temp.varType == 0)
		temp.Int = temp.Int / value;
	else if (temp.varType == 1)
		temp.Double = temp.Double / (double)value;
	return temp;
}

var var::operator/(double value) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = value;
	else if (temp.varType == 0)
		temp.Int = temp.Int / (int)value;
	else if (temp.varType == 1)
		temp.Double = temp.Double / value;
	return temp;
}

var var::operator/(const MyString& str) const
{
	var temp(*this);
	if (temp.varType == -1)
		temp = str;
	else if (temp.varType == 0)
	{
		temp.Int = temp.Int / atoi(str.MyC_Str());
	}
	else if (temp.varType == 1)
	{
		temp.Double = temp.Double / strtod(str.MyC_Str(), nullptr);
	}
	else if (temp.varType == 2)
	{
		for (int i = 0; i < str.MyStrLen(); i++)
		{
			temp.Str.MyDelChr(str[i]);
		}
	}
	return temp;
}

var var::operator/(const char* str) const
{
	return (*this / MyString(str));
}

var var::operator/(const var& obj) const
{
	var temp(*this);
	if (obj.varType == 0)
		temp = temp / obj.Int;
	else if (obj.varType == 1)
		temp = temp / obj.Double;
	else if (obj.varType == 2)
		temp = temp / obj.Str;

	return temp;
}