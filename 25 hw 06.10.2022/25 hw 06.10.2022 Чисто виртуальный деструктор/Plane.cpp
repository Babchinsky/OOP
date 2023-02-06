#include "Plane.h"
#include <iostream>
using namespace std;

Plane::Plane() : Transport()
{
	cout << "Plane Constructor by default\n";
	Type = new char[10] {"Default"};
}
Plane::Plane(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Plane Constructor by params\n";
	Type = new char[strlen(type) + 1];
	strcpy_s(Type, strlen(type) + 1, type);
}
Plane::Plane(Plane& obj) :Plane(obj.Name, obj.NumberOfSeats, obj.FuelConsumption, obj.Type)
{
	cout << "Plane Constructor by object\n";
}
Plane::~Plane()
{
	cout << "Plane Destructor\n";
	Transport::~Transport();
	if (Type != nullptr) delete[] Type;
}

void Plane::Init()
{
	cout << "Plane Init\n";
	Transport::Init();

	cout << "Enter type\n->";
	char buf[128];
	cin >> buf;

	if (Type != nullptr) delete[] Type;
	Type = new char[strlen(buf) + 1];
	strcpy_s(Type, strlen(buf) + 1, buf);
}
void Plane::Show() const
{
	cout << "Plane Show\n";
	Transport::Show();
	cout << "Type: " << Type << endl;
}