#pragma once
#include "Person.h"
class Teacher : public Person
{
	char* School;
public:
	// construcrots, destructors, copy semantic
	Teacher();
	Teacher(const char* n, int a, const char* s);
	Teacher(const Person& obj, const char* s);
	Teacher(const Teacher& obj);

	~Teacher();

	Teacher& operator=(const Teacher& obj);

	void Print();
};

