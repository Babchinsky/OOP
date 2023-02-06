#include "Bicycle.h"
#include <iostream>
using namespace std;

Bicycle::Bicycle() : Transport()
{
	cout << "Bicycle Constructor by default\n";
	Type = new char[10] {"Default"};
}
Bicycle::Bicycle(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Bicycle Constructor by params\n";
	Type = new char[strlen(type) + 1];
	strcpy_s(Type, strlen(type) + 1, type);
}
Bicycle::Bicycle(Bicycle& obj) :Bicycle(obj.Name, obj.NumberOfSeats, obj.FuelConsumption, obj.Type)
{
	cout << "Bicycle Constructor by object\n";
}
Bicycle::~Bicycle()
{
	cout << "Bicycle Destructor\n";
	Transport::~Transport();
	if (Type != nullptr) delete[] Type;
}

void Bicycle::Init()
{
	cout << "Bicycle Init\n";
	Transport::Init();

	cout << "Enter type\n->";
	char buf[128];
	cin >> buf;

	if (Type != nullptr) delete[] Type;
	Type = new char[strlen(buf) + 1];
	strcpy_s(Type, strlen(buf) + 1, buf);
}
void Bicycle::Show() const
{
	cout << "Bicycle Show\n";
	Transport::Show();
	cout << "Type: " << Type << endl;
}