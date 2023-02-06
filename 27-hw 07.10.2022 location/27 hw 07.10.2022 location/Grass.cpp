#include "Grass.h"
#include "Animal.h"

Grass::Grass()
{
	count = 0;
	life = false;
}

Grass::Grass(int c) : Grass()
{
	if (c > 0) // если 0 объектов, то зачем что то делать ? 
	{
		count = c;
		life = true;
	}
}

void Grass::Init()
{
	cout << "Enter the amount of Grass: ";
	cin >> count;
	if (count > 0)
	{
		life = true;
	}
	else
	{
		life = false;
	}
}

void Grass::Show()
{
	if (life)
	{
		cout << "Amount of Grass: " << count << endl;
	}
	else
	{
		cout << "There is no life" << endl;
	}
}

int Grass::GetCount()
{
	return count;
}

void Grass::SetCount(int amount)
{
	count = amount;
	if (amount > 0)
	{
		life = true;
	}
	else
	{
		life = false;
	}
}
