#include "../var.h"

// operator int
var::operator int()
{
	if (varType == -1)
		return -1;
	else if (varType == 0)
		return Int;
	else if (varType == 1)
		return (int)Double;
	else if (varType == 2)
		return atoi(Str.MyC_Str());
}

// operator double
var::operator double()
{
	if (varType == -1)
		return -1.0;
	else if (varType == 0)
		return (double)Int;
	else if (varType == 1)
		return Double;
	else if (varType == 2)
		return strtod(Str.MyC_Str(), nullptr);
}

// operator const char*
var::operator const char*()
{
	if (varType == -1)
		return nullptr;
	else if (varType == 0)
	{
		char* buffer = new char[20];
		_itoa_s(Int, buffer, 20, 10);
		return buffer;
	}
	else if (varType == 1)
	{
		char* buffer = new char[20];
		_itoa_s(int(Double * 1000), buffer, 20, 10);
		buffer[strlen(buffer) - 1] = buffer[strlen(buffer) - 2];
		buffer[strlen(buffer) - 2] = buffer[strlen(buffer) - 3];
		buffer[strlen(buffer) - 3] = '.';
		return buffer;
	}
	else if (varType == 2)
	{
		return Str.MyC_Str();
	}
}