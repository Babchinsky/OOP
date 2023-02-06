#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	cout << "Constructor Student by def\n";
	Academy = new char[10] {"Default"};
}

Student::Student(const char* n, int a, const char* Ac) : Person(n, a)
{
	cout << "Constructor Student by 3 params\n";

	Academy = new char[strlen(Ac) + 1];
	strcpy_s(Academy, strlen(Ac) + 1, Ac);
}

Student::Student(const Person& obj, const char* Ac): Person(obj)
{
	cout << "Constructor Student by object(name, age) and param\n";

	Academy = new char[strlen(Ac) + 1];
	strcpy_s(Academy, strlen(Ac) + 1, Ac);
}

Student::Student(const Student& obj) : Person(obj)
{
	cout << "Constructor Student by copy\n";

	Academy = new char[strlen(obj.Academy) + 1];
	strcpy_s(Academy, strlen(obj.Academy) + 1, obj.Academy);
}

Student::~Student()
{
	cout << "Student Destructor\n";
	if (Academy != nullptr) delete[] Academy;
}

Student& Student::operator=(const Student& obj)
{
	cout << "Student =\n";

	if (this == &obj) return *this;				// if same
	if (name != nullptr) delete[]name;			// if name stores smth
	if (Academy != nullptr) delete[]Academy;	// if Academy stores smth

	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);

	Academy = new char[strlen(obj.Academy) + 1];
	strcpy_s(Academy, strlen(obj.Academy) + 1, obj.Academy);

	age = obj.age;
	return *this;
}

void Student::Print()
{
	cout << "Print Student\n";
	Person::Print();
	cout << "Academy: " << Academy << endl;
}