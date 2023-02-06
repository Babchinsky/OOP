#pragma once
#include "Transport.h"
class Bicycle: public Transport
{
protected:
	string Type;
public:
	Bicycle();
	Bicycle(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type);
	Bicycle(Bicycle& obj);
	~Bicycle();

	void Init();
	void Show() const;
};

