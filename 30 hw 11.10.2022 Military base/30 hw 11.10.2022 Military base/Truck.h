#pragma once
#include "Vehicle.h"
class Truck :public Vehicle
{
private:
	int goods;
	int goods_max;
public:
	Truck();
	Truck(const int petrol_amount, const int tank_volume, const int goods, const int goods_max);
	Truck(const Truck& obj);
	~Truck();

	void Print() const;
	void Arrive();
	void Leave();
	int getCurrentLoad() const;
	int getMaxLoad() const;
};