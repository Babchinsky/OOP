#pragma once
class Person
{
protected:
	char* name;
	int age;
public:
	// construcrots, destructors, copy semantic
	Person();
	Person(const char* n, int a);
	Person(const Person& obj);
	~Person();

	Person& operator=(const Person& obj);

	void Print();
};

