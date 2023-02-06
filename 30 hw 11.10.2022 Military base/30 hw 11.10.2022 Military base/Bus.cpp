#include "Bus.h"
#include <iostream>
using namespace std;

Bus::Bus() : Vehicle()
{
	cout << "Bus Default Constructor\n";
	passengers = 21;
	passengers_max = 21;
}

Bus::Bus(const int petrol_amount, const int tank_volume, const int passengers, const int passengers_max) :Vehicle(petrol_amount, tank_volume)
{
	cout << "Bus Constructor by params\n";
	this->passengers = passengers;
	this->passengers_max = passengers_max;
}

Bus::Bus(const Bus& obj) :Vehicle(obj)
{
	cout << "Bus Constructor by object\n";
	passengers = obj.passengers;
}

Bus::~Bus()
{
	cout << "Bus Destructor\n";
	Vehicle::~Vehicle();
	passengers = -1;
	passengers_max = -1;
}

void Bus::Print() const
{
	cout << "Bus Print\n";
	Vehicle::Print();
	cout << "Passengers: " << passengers << endl;
	cout << "Max passengers: " << passengers_max << endl;
}

void Bus::Arrive()
{
	cout << "Bus Arrive\n";
	Vehicle::Arrive();
	people_on_base += passengers;
	passengers = 0;

}

void Bus::Leave()
{
	cout << "Bus Leave\n";
	Vehicle::Leave();

	int not_enough_passangers = passengers_max - passengers;	// не хватает пассажирова

	if (people_on_base >= not_enough_passangers)	// если людей достаточно, чтобы заполнить все места
	{
		people_on_base -= not_enough_passangers;
		passengers += not_enough_passangers;
	}

	else // если людей недостаточно, чтобы заполнить все места,
	{	 // то заполняем, сколько можем
		passengers += people_on_base;
		people_on_base = 0;
	}
}

int Bus::getPeopleCount() const
{
	return passengers;
}

int Bus::getMaxPeople() const
{
	return passengers_max;
}