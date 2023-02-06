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
	//virtual void Eat() = 0;
	//virtual void Move() = 0;	
};

class Elephant : public Animal // наследование 
{
public:
	Elephant() = default;
	Elephant(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- реализация ИНТЕРФЕЙСА IANIMAL !!!

	virtual void Eat()
	{
		cout << "Elephant Eat\n";
	}
	virtual void Move()
	{
		cout << "Elephant Move\n";
	}

};
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
class Human :public IAnimal
{
public:
	virtual void Eat()
	{
		cout << "Human Eat\n";
	}
	virtual void Move()
	{
		cout << "Human Move\n";
	}
};


class Cat : public Animal
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
};
class Dog : public Animal
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
};
class Penguin : public Animal, public ISwim
{
public:
	Penguin() = default;
	Penguin(string n, double k, string cont) :Animal(n, k, cont) {}

	// ----- реализация ИНТЕРФЕЙСА IANIMAL !!!

	virtual void Eat()
	{
		cout << "Penguin Eat\n";
	}
	virtual void Move()
	{
		cout << "Penguin Move\n";
	}
	virtual void Swim()
	{
		cout << "Penguin Swim\n";
	}
};
class Dolphin : public Animal, public ISwim
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
	virtual void Swim()
	{
		cout << "Dolphin Swim\n";
	}
};