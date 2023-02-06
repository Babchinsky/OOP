#pragma once
#include <iostream>
using namespace std;

class Grass
{
private:
	int count;
	bool life;
public:
	Grass();
	Grass(int c);

	void Init();
	void Show();

	int GetCount();
	void SetCount(int);
};