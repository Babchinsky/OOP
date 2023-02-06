#include "Ship.h"
#include <iostream>
using namespace std;

Ship::Ship() : Transport()
{
	cout << "Ship Constructor by default\n";
	Type = new char[10] {"Default"};
}
Ship::Ship(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Ship Constructor by params\n";
	Type = new char[strlen(type) + 1];
	strcpy_s(Type, strlen(type) + 1, type);
}
Ship::Ship(Ship& obj) :Ship(obj.Name, obj.NumberOfSeats, obj.FuelConsumption, obj.Type)
{
	cout << "Ship Constructor by object\n";
}
Ship::~Ship()
{
	cout << "Ship Destructor\n";
	Transport::~Transport();
	if (Type != nullptr) delete[] Type;
}

void Ship::Init()
{
	cout << "Ship Init\n";
	Transport::Init();

	cout << "Enter type\n->";
	char buf[128];
	cin >> buf;

	if (Type != nullptr) delete[] Type;
	Type = new char[strlen(buf) + 1];
	strcpy_s(Type, strlen(buf) + 1, buf);
}
void Ship::Show() const
{
	cout << "Ship Show\n";
	Transport::Show();
	cout << "Type: " << Type << endl;
}