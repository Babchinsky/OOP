#include "Truck.h"
#include <iostream>
using namespace std;

Truck::Truck() : Vehicle()
{
	cout << "Truck Default Constructor\n";
	goods = 100;
	goods_max = 100;
}

Truck::Truck(const int petrol_amount, const int tank_volume, const int goods, const int goods_max) :Vehicle(petrol_amount, tank_volume)
{
	cout << "Truck Constructor by params\n";
	this->goods = goods;
	this->goods_max = goods_max;
}

Truck::Truck(const Truck& obj) :Vehicle(obj)
{
	cout << "Truck Constructor by object\n";
	goods = obj.goods;
	goods_max = obj.goods_max;
}

Truck::~Truck()
{
	cout << "Truck Destructor\n";
	Vehicle::~Vehicle();
	goods = -1;
	goods_max = -1;
}


void Truck::Print() const
{
	cout << "Truck Print\n";
	Vehicle::Print();
	cout << "Goods: " << goods << endl;
	cout << "Max goods: " << goods_max << endl;
}

void Truck::Arrive()
{
	cout << "Truck Arrive\n";
	Vehicle::Arrive();
	goods_on_base += goods;
	goods = 0;

}

void Truck::Leave()
{
	cout << "Truck Leave\n";
	Vehicle::Leave();

	int not_enough_goods = goods_max - goods;	// не хватает пассажирова

	if (goods_on_base >= not_enough_goods)	// если людей достаточно, чтобы заполнить все места
	{
		goods_on_base -= not_enough_goods;
		goods += not_enough_goods;
	}

	else // если людей недостаточно, чтобы заполнить все места,
	{	 // то заполняем, сколько можем
		goods += goods_on_base;
		goods_on_base = 0;
	}
}

int Truck::getCurrentLoad() const
{
	return goods;
}

int Truck::getMaxLoad() const
{
	return goods_max;
}