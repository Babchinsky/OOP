#include "Jeep.h"
#include <iostream>
using namespace std;
using namespace jeep;

Jeep::Jeep() : Transport()
{
	cout << "Jeep Constructor by default\n";
	Type = new char[10] {"Default"};
}
Jeep::Jeep(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type)
	: Transport(name, number_of_seats, fuel_consumption)
{
	cout << "Jeep Constructor by params\n";
	Type = new char[strlen(type) + 1];
	strcpy_s(Type, strlen(type) + 1, type);
}
Jeep::Jeep(Jeep& obj) :Jeep(obj.Name, obj.NumberOfSeats, obj.FuelConsumption, obj.Type)
{
	cout << "Jeep Constructor by object\n";
}
Jeep::~Jeep()
{
	cout << "Jeep Destructor\n";
	Transport::~Transport();
	if (Type != nullptr) delete[] Type;
}

void Jeep::Init()
{
	cout << "Jeep Init\n";
	Transport::Init();

	cout << "Enter type\n->";
	char buf[128];
	cin >> buf;

	if (Type != nullptr) delete[] Type;
	Type = new char[strlen(buf) + 1];
	strcpy_s(Type, strlen(buf) + 1, buf);

}
void Jeep::Show() const
{
	cout << "Jeep Show\n";
	Transport::Show();
	cout << "Type: " << Type << endl;
}