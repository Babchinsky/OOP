#pragma once
#include <iostream>
#include "List.h"
#include <conio.h>
#include <Windows.h>
using namespace std;

class Animal
{
protected:
	int col;				// количество животных 
	int max_age;			// максимальный возрост животных 
	List<int> age;			//список на возврост каждого животного по отделньости с помощью списка.
	string habitat;			// среда обитания животных
	bool life;				// есть какие то животные
public:
	Animal();				// по умолчанию 
	Animal(int c);			// вводим количество животных, в консоли отдельно попросит ввести возраст каждого животного.
	~Animal();				// деструктор (вызывает деструктор списка)

	virtual void Local() final;
	virtual void Analysis() final;
	virtual void Init();	// инициализация 
	virtual void Show() = 0;  // чисто виртуальный метод, не возможно создать объект класса, в потомках нам нужно будет его явно переопределить!

	virtual string GetHabitat(); // возвращаем место обитания 
};