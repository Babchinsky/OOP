#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher()
{
	cout << "Constructor Teacher by def\n";
	School = new char[10] {"Default"};
}

Teacher::Teacher(const char* n, int a, const char* s) : Person(n, a)
{
	cout << "Constructor Teacher by 3 params\n";

	School = new char[strlen(s) + 1];
	strcpy_s(School, strlen(s) + 1, s);
}

Teacher::Teacher(const Person& obj, const char* s) : Person(obj)
{
	cout << "Constructor Teacher by object(name, age) and param\n";

	School = new char[strlen(s) + 1];
	strcpy_s(School, strlen(s) + 1, s);
}

Teacher::Teacher(const Teacher& obj) : Person(obj)
{
	cout << "Constructor Teacher by copy\n";

	School = new char[strlen(obj.School) + 1];
	strcpy_s(School, strlen(obj.School) + 1, obj.School);
}

Teacher::~Teacher()
{
	cout << "Teacher Destructor\n";
	if (School != nullptr) delete[] School;
}

Teacher& Teacher::operator=(const Teacher& obj)
{
	cout << "Teacher =\n";

	if (this == &obj) return *this;				// if same
	if (name != nullptr) delete[]name;			// if name stores smth
	if (School != nullptr) delete[]School;		// if School stores smth

	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);

	School = new char[strlen(obj.School) + 1];
	strcpy_s(School, strlen(obj.School) + 1, obj.School);
	
	age = obj.age;
	return *this;
}

void Teacher::Print()
{
	cout << "Print Teacher\n";
	Person::Print();
	cout << "School: " << School << endl;
}