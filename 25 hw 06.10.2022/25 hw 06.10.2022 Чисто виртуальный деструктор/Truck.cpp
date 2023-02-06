#include "Truck.h"
#include <iostream>
using namespace std;

Truck::Truck() : Transport()
{
	cout << "Truck Constructor by default\n";
	Type = new char[10] {"Default"};
}
Truck::Truck(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Truck Constructor by params\n";
	Type = new char[strlen(type) + 1];
	strcpy_s(Type, strlen(type) + 1, type);
}
Truck::Truck(Truck& obj) :Truck(obj.Name, obj.NumberOfSeats, obj.FuelConsumption, obj.Type)
{
	cout << "Truck Constructor by object\n";
}
Truck::~Truck()
{
	cout << "Truck Destructor\n";
	Transport::~Transport();
	if (Type != nullptr) delete[] Type;
}

void Truck::Init()
{
	cout << "Truck Init\n";
	Transport::Init();

	cout << "Enter type\n->";
	char buf[128];
	cin >> buf;

	if (Type != nullptr) delete[] Type;
	Type = new char[strlen(buf) + 1];
	strcpy_s(Type, strlen(buf) + 1, buf);
}
void Truck::Show() const
{
	cout << "Truck Show\n";
	Transport::Show();
	cout << "Type: " << Type << endl;
}