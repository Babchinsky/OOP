#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
	char* str; // pointer to string
	size_t length; // string length
	static int count; // number of objects

public:
	MyString(); // default constructor
	MyString(int length); // get a param of string length
	MyString(const char* str); // get string to write
	MyString(const MyString& obj); // copy constructor
	~MyString(); // destructor

	MyString& operator=(const MyString& obj); // assignment				// last added code
	MyString& operator=(const char* str); // assignment					// last added code
	void operator()() const; // output string by using cout				// last added code
	char operator[](int index) const; // return char by index			// last added code
	operator size_t() const; // return str length							// last added code
	operator const char* () const; // return string						// last added code

	void Enter(); // input string by using keyboard

	void MyStrcpy(MyString& obj); // copy string
	bool MyStrStr(const char* str); // substring in string
	int  MyChr(char c) const; // search for character in string(character index OR -1)
	size_t MyStrLen() const; // get string length
	void MyStrCat(const MyString& b); // string concatenation
	void MyStrCat(const char* b);
	void MyDelChr(char c); // delete character from string 
	int MyStrCmp(const MyString& b) const; // compare strings
	const char* MyC_Str() const; // get const pointer to char array
	static int GetCount(); // get number of objects

	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);

	MyString(MyString&& obj2) noexcept; // move constructor
	MyString& operator=(MyString&& obj2) noexcept; // = move
	MyString(initializer_list<char> ch); // Constructor initializer_list
};
