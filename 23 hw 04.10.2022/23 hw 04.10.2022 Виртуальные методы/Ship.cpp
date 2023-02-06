#include "Ship.h"
#include <iostream>
using namespace std;

Ship::Ship() : Transport()
{
	cout << "Ship Constructor by default\n";
	Type = "Default";
}
Ship::Ship(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Ship Constructor by params\n";
	Type = type;
}
Ship::Ship(Ship& obj)
	:Transport(obj)
{
	cout << "Ship Constructor by object\n";
	Type = obj.Type;
}
Ship::~Ship()
{
	cout << "Ship Destructor\n";
	Transport::~Transport();
	Type = "";
}

void Ship::Init()
{
	cout << "Ship Init\n";
	//Transport::Init();
	cout << "Enter name\n->";
	cin >> Name;
	cout << "Enter number of seats\n->";
	cin >> NumberOfSeats;
	cout << "Enter fuel consumption\n->";
	cin >> FuelConsumption;
	cout << "Enter type\n->";
	cin >> Type;
}
void Ship::Show() const
{
	cout << "Ship Show\n";
	//Transport::Show();
	cout << "Name: " << Name << endl;
	cout << "Number of seats: " << NumberOfSeats << endl;
	cout << "Fuel consumption: " << FuelConsumption << endl;
	cout << "Type: " << Type << endl;
}