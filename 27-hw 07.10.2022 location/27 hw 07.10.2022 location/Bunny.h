#pragma once
#include "Animal.h"
class Bunny : public Animal
{
public:
	Bunny();
	Bunny(int c);

	void Init();
	void Show();

	void Remainder(int);
	int GetCount();

};

