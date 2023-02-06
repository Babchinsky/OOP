#include "Truck.h"
#include <iostream>
using namespace std;

Truck::Truck() : Transport()
{
	cout << "Truck Constructor by default\n";
	Type = "Default";
}
Truck::Truck(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Truck Constructor by params\n";
	Type = type;
}
Truck::Truck(Truck& obj)
	:Transport(obj)
{
	cout << "Truck Constructor by object\n";
	Type = obj.Type;
}
Truck::~Truck()
{
	cout << "Truck Destructor\n";
	Transport::~Transport();
	Type = "";
}

void Truck::Init()
{
	cout << "Truck Init\n";
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
void Truck::Show() const
{
	cout << "Truck Show\n";
	//Transport::Show();
	cout << "Name: " << Name << endl;
	cout << "Number of seats: " << NumberOfSeats << endl;
	cout << "Fuel consumption: " << FuelConsumption << endl;
	cout << "Type: " << Type << endl;
}