#include "Person.h"
#include<iostream>
using namespace std;

Person::Person(): age(0)
{
	cout << "Person Constructor by default\n";
	name = new char[10] {"Default"};
}

Person::Person(const char* n, int a): age(a)
{
	cout << "Person Constructor by 2 params\n";
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Person::Person(const Person& obj): age(obj.age)
{
	cout << "Person Copy Constructor\n";
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
}

Person::~Person()
{
	cout << "Destructor Person\n";
	if (name != nullptr) delete[] name;
}

Person& Person::operator=(const Person& obj)
{
	cout << "Person =\n";

	if (this == &obj) return *this;		   // if same
	if (name != nullptr) this-> ~Person(); // if name stores smth

	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	age = obj.age;

	return *this;
}

void Person::Print()
{
	cout << "Print Person\n";
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}
