#include "Jeep.h"
#include <iostream>
using namespace std;

Jeep::Jeep() : Transport()
{
	cout << "Jeep Constructor by default\n";
	Type = "Default";
}
Jeep::Jeep(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Jeep Constructor by params\n";
	Type = type;
}
Jeep::Jeep(Jeep& obj)
	:Transport(obj)
{
	cout << "Jeep Constructor by object\n";
	Type = obj.Type;
}
Jeep::~Jeep()
{
	cout << "Jeep Destructor\n";
	Transport::~Transport();
	Type = "";
}

void Jeep::Init()
{
	cout << "Jeep Init\n";
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
void Jeep::Show() const
{
	cout << "Jeep Show\n";
	//Transport::Show();
	cout << "Name: " << Name << endl;
	cout << "Number of seats: " << NumberOfSeats << endl;
	cout << "Fuel consumption: " << FuelConsumption << endl;
	cout << "Type: " << Type << endl;
}