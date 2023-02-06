#include "Bicycle.h"
#include <iostream>
using namespace std;

Bicycle::Bicycle(): Transport()
{
	cout << "Bicycle Constructor by default\n";
	Type = "Default";
}
Bicycle::Bicycle(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Bicycle Constructor by params\n";
	Type = type;
}
Bicycle::Bicycle(Bicycle& obj)
	:Transport(obj)
{
	cout << "Bicycle Constructor by object\n";
	Type = obj.Type;
}
Bicycle::~Bicycle()
{
	cout << "Bicycle Destructor\n";
	Transport::~Transport();
	Type = "";
}

void Bicycle::Init()
{
	cout << "Bicycle Init\n";
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
void Bicycle::Show() const
{
	cout << "Bicycle Show\n";
	//Transport::Show();
	cout << "Name: " << Name << endl;
	cout << "Number of seats: " << NumberOfSeats << endl;
	cout << "Fuel consumption: " << FuelConsumption << endl;
	cout << "Type: " << Type << endl;
}