#include "Plane.h"
#include <iostream>
using namespace std;

Plane::Plane() : Transport()
{
	cout << "Plane Constructor by default\n";
	Type = "Default";
}
Plane::Plane(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Plane Constructor by params\n";
	Type = type;
}
Plane::Plane(Plane& obj)
	:Transport(obj)
{
	cout << "Plane Constructor by object\n";
	Type = obj.Type;
}
Plane::~Plane()
{
	cout << "Plane Destructor\n";
	Transport::~Transport();
	Type = "";
}

void Plane::Init()
{
	cout << "Plane Init\n";
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
void Plane::Show() const
{
	cout << "Plane Show\n";
	//Transport::Show();
	cout << "Name: " << Name << endl;
	cout << "Number of seats: " << NumberOfSeats << endl;
	cout << "Fuel consumption: " << FuelConsumption << endl;
	cout << "Type: " << Type << endl;
}