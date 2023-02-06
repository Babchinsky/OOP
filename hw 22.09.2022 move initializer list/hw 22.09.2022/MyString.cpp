#include "MyString.h"
#include <iostream>

using namespace std;

int MyString::count = 0;

// default constructor
MyString::MyString()
{
	count++;
	str = new char[80];
	str[0] = '\0';
	length = 0;
}

// get a param of string length
MyString::MyString(int length)
{
	count++;
	this->length = length;
	str = new char[length + 1];
	str[0] = '\0';
}

// get string to write
MyString::MyString(const char* str)
{
	count++;
	length = strlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->str[i] = str[i];
	this->str[length] = '\0';
}

// copy constructor
MyString::MyString(const MyString& obj)
{
	count++;
	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = obj.str[i];
	str[length] = '\0';
}

// destructor
MyString::~MyString()
{
	count--;
	delete[] str;
}

// assignment
MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj)
		return *this;

	delete[]str;

	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = obj.str[i];
	str[length] = '\0';

	return *this;
}

// assignment
MyString& MyString::operator=(const char* str)		// last added code
{
	length = strlen(str);
	delete[]this->str;
	this->str = new char[length + 1];
	for (int i = 0; i < length + 1; i++)
		this->str[i] = str[i];
	this->str[length] = '\0';
	return *this;
}

// last added code
// output string by using cout
void MyString::operator()() const
{
	std::cout << str;
}

// return char by index
char MyString::operator[](int index) const
{
	if (index >= 0 && index < length)
		return str[index];
	else
		return '\0';
}

// return str length
MyString::operator size_t() const
{
	return length;
}

// return string
MyString::operator const char* () const
{
	return str;
}

// input string by using keyboard
void MyString::Enter()
{
	const short BUFSIZE = 256;
	char buffer[256];
	delete[] str;
	std::cin.getline(buffer, 256);
	length = strlen(buffer);
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = buffer[i];
	str[length] = '\0';
}

// copy string
void MyString::MyStrcpy(MyString& obj)
{
	delete[] str;
	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = obj.str[i];
	str[length] = '\0';
}

// substring in string
bool MyString::MyStrStr(const char* str)
{
	bool result = false;
	if (strlen(str) > length)
		return result;
	for (int i = 0; i < length; i++)
	{
		result = true;
		for (int j = 0; j < strlen(str); j++)
		{
			if (this->str[j + i] != str[j])
			{
				result = false;
				break;
			}
		}
		if (result)
			break;
	}
	return result;
}

// search for character in string(character index OR -1)
int MyString::MyChr(char c) const
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

// get string length
size_t MyString::MyStrLen() const
{
	return length;
}

// string concatenation
void MyString::MyStrCat(const MyString& b)
{
	char* temp = new char[length + b.length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < b.length; i++)
	{
		temp[i + length] = b.str[i];
	}
	length += b.length;
	temp[length] = '\0';
	delete[] str;
	str = temp;
}

void MyString::MyStrCat(const char* b)
{
	char* temp = new char[length + strlen(b) + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < strlen(b); i++)
	{
		temp[i + length] = b[i];
	}
	length += strlen(b);
	temp[length] = '\0';
	delete[] str;
	str = temp;
}

// delete character from string 
void MyString::MyDelChr(char c)
{
	bool check = false;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			check = true;
			for (int j = i; j < length - 1; j++)
				str[j] = str[j + 1];
			str[length] = '\0';
			i--;
			length--;
		}
	}
	if (check)
	{
		char* temp = new char[length + 1];
		for (int i = 0; i < length; i++)
			temp[i] = str[i];
		temp[length] = '\0';
		delete[] str;
		str = temp;
	}
}

// compare strings
int MyString::MyStrCmp(const MyString& b) const
{
	char* str1 = str;
	char* str2 = b.str;

	if (strlen(str1) < strlen(str2))
	{
		return -1;
	}
	while (*str2 == '\0')
	{
		if (*str1 != *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	if (strlen(str1) > strlen(str2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// get const pointer to char array
const char* MyString::MyC_Str() const
{
	return str;
}

int MyString::GetCount()
{
	return count;
}


std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	for (int i = 0; i < obj.length; i++)
	{
		os << obj[i];
	}
	return os;
}

// move constructor
MyString::MyString(MyString&& obj2) noexcept // move constructor
{
	cout << "Constructor MOVE\n";

	str = obj2.str; 
	obj2.str = nullptr;

	length = obj2.length;
	obj2.length = 0;

	count++;
}

// = move
MyString& MyString::operator=(MyString&& obj2) noexcept
{
	cout << "= MOVE\n";
	
	if (str != nullptr) delete[] str;

	str = obj2.str;
	obj2.str = nullptr;
	length = obj2.length;
	obj2.length = 0;

	return *this;
}

// Constructor initializer_list
MyString::MyString(initializer_list<char> ch)
{
	cout << "Size -> " << ch.size() << endl;
	// Copy to string from initializer list
	string _str;
	_str.append(ch.begin(), ch.end());

	// Copy length
	length = _str.length();

	// String to char*
	str = new char[length + 1];
	strcpy_s(str, _str.length() + 1, _str.c_str());

	count++;
}