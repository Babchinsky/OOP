#pragma once
#include "Transport.h"
class Truck : public Transport
{
protected:
	string Type;
public:
	Truck();
	Truck(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type);
	Truck(Truck& obj);
	~Truck();

	void Init();
	void Show() const;
};

