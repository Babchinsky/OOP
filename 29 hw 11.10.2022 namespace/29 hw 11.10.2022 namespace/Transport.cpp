#include <iostream>
#include "Transport.h"
using namespace std;
using namespace transport;

Transport::Transport()
{
	cout << "Transport Constructor by default\n";
	Name = new char[10] {"Default"};
	NumberOfSeats = 0;
	FuelConsumption = 0;
}
Transport::Transport(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption)
{
	cout << "Transport Constructor by params\n";
	Name = new char[strlen(name) + 1];
	strcpy_s(Name, strlen(name) + 1, name);

	NumberOfSeats = number_of_seats;
	FuelConsumption = fuel_consumption;
}
Transport::Transport(Transport& obj) : Transport(obj.Name, obj.NumberOfSeats, obj.FuelConsumption)
{
	cout << "Transport Constructor by object\n";
}
Transport::~Transport()
{
	cout << "Transport Destructor\n";
	if (Name != nullptr) delete[] Name;

	NumberOfSeats = -1;
	FuelConsumption = -1;
}

void Transport::Init()
{
	cout << "Transport Init\n";

	cout << "Enter name\n->";
	char buf[128];
	cin >> buf;

	if (Name != nullptr) delete[] Name;
	Name = new char[strlen(buf) + 1];
	strcpy_s(Name, strlen(buf) + 1, buf);

	cout << "Enter number of seats\n->";
	cin >> NumberOfSeats;

	cout << "Enter fuel consumption\n->";
	cin >> FuelConsumption;
}
void Transport::Show() const
{
	cout << "Transport Show\n";
	cout << "Name: " << Name << endl;
	cout << "Number of seats: " << NumberOfSeats << endl;
	cout << "Fuel consumption: " << FuelConsumption << endl;
}