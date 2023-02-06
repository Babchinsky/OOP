#pragma once
#include<iostream>
#include"MyInterface.h"
using namespace std;

class Animal : public IAnimal // реализация интерфеса
{
protected:
	string name;
	double kg;
	string continent;
public:
	Animal() = default;
	Animal(string n, double k, string cont)
	{
		name = n;
		kg = k;
		continent = cont;
	}
	virtual void Print()
	{
		cout << "Name: " << name << endl;
		cout << "KG: " << kg << endl;
		cout << "Continent: " << continent << endl;
	}
	virtual void PrintStr()
	{
		cout << name << '\t' << kg << '\t' << continent << endl;
	}
	virtual string GetName();
	virtual void SetName(string a);
	virtual void SetKg(double a);
	virtual void SetCont(string a);
	//virtual void Eat() = 0;
	//virtual void Move() = 0;	
	//friend std::ostream& operator<<(std::ostream& os, const Animal& a);
};
//std::ostream& operator<<(std::ostream& os, const Animal& a)
//{
//	os << a.name << "\t" << a.kg << "\t" << a.continent << endl;
//	return os;
//}



class Parrot : public Animal, public IFly // наследование 
{
public:
	Parrot() = default;
	Parrot(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- реализация ИНТЕРФЕЙСА IANIMAL !!!

	virtual void Eat()
	{
		cout << "Parrot Eat\n";
	}
	virtual void Move()
	{
		cout << "Parrot Move\n";
	}
	// ----- реализация ИНТЕРФЕЙСА IFLY !!!
	virtual void Fly()
	{
		cout << "Parrot Fly\n";
	}

};

class Cat : public Animal // наследование 
{
public:
	Cat() = default;
	Cat(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- реализация ИНТЕРФЕЙСА IANIMAL !!!

	virtual void Eat()
	{
		cout << "Cat Eat\n";
	}
	virtual void Move()
	{
		cout << "Cat Move\n";
	}
	//friend std::ostream& operator<<(std::ostream& os, const Cat& a);
};
//std::ostream& operator<<(std::ostream& os, const Cat& a)
//{
//	os << a.name << "\t" << a.kg << "\t" << a.continent << endl;
//	return os;
//}


class Dog : public Animal // наследование 
{
public:
	Dog() = default;
	Dog(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- реализация ИНТЕРФЕЙСА IANIMAL !!!

	virtual void Eat()
	{
		cout << "Dog Eat\n";
	}
	virtual void Move()
	{
		cout << "Dog Move\n";
	}
	//friend std::ostream& operator<<(std::ostream& os, const Dog& a);
};
//std::ostream& operator<<(std::ostream& os, const Dog& a)
//{
//	os << a.name << "\t" << a.kg << "\t" << a.continent << endl;
//	return os;
//}

class Pinguin : public Animal, public ISwim // наследование 
{
public:
	Pinguin() = default;
	Pinguin(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- реализация ИНТЕРФЕЙСА IANIMAL !!!

	virtual void Eat()
	{
		cout << "Pinguin Eat\n";
	}
	virtual void Move()
	{
		cout << "Pinguin Move\n";
	}
	// ----- реализация ИНТЕРФЕЙСА ISwim !!!
	virtual void Swim()
	{
		cout << "Pinguin Swim\n";
	}
	//friend std::ostream& operator<<(std::ostream& os, const Pinguin& a);
};
//std::ostream& operator<<(std::ostream& os, const Pinguin& a)
//{
//	os << a.name << "\t" << a.kg << "\t" << a.continent << endl;
//	return os;
//}

class Dolphin : public Animal, public ISwim // наследование 
{
public:
	Dolphin() = default;
	Dolphin(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- реализация ИНТЕРФЕЙСА IANIMAL !!!

	virtual void Eat()
	{
		cout << "Dolphin Eat\n";
	}
	virtual void Move()
	{
		cout << "Dolphin Move\n";
	}
	// ----- реализация ИНТЕРФЕЙСА ISwim !!!
	virtual void Swim()
	{
		cout << "Dolphin Swim\n";
	}
	//friend std::ostream& operator<<(std::ostream& os, const Dolphin& a);
};
