#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;


class Fox : public Animal
{
public:
	Fox();
	Fox(int c);

	void Init();
	void Show();

	void Remainder(int); // ������� ���, �������� ���������� ������� ����� �������� 
	int GetCount();

};

