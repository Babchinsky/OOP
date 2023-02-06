#pragma once
#include "Transport.h"
class Truck : public Transport
{
protected:
	char* Type;
public:
	Truck();
	Truck(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type);
	Truck(Truck& obj);
	~Truck();

	void Init();
	void Show() const;
};