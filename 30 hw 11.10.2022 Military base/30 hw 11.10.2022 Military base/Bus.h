#pragma once
#include "Vehicle.h"
class Bus :public Vehicle
{
private:
	int passengers;
	int passengers_max;
public:
	Bus();
	Bus(const int petrol_amount, const int tank_volume, const int passengers, const int passengers_max);
	Bus(const Bus& obj);
	~Bus();

	void Print() const;
	void Arrive();
	void Leave();
	int getPeopleCount() const;
	int getMaxPeople() const;
};