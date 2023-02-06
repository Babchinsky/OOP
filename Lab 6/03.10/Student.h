#pragma once
#include "Person.h"
class Student :public Person
{
	char* Academy;
public:
	// construcrots, destructors, copy semantic
	Student();
	Student(const char* n, int a, const char* Ac);
	Student(const Person& obj, const char* Ac);
	Student(const Student& obj);

	~Student();

	Student& operator=(const Student& obj);

	void Print();
};

