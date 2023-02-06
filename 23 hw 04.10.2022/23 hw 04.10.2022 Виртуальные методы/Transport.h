#pragma once
#include <string>
using namespace std;

class Transport
{
protected:
	string Name;
	unsigned short NumberOfSeats;
	unsigned short FuelConsumption;
public:
	Transport();
	Transport(string name, unsigned short number_of_seats, unsigned short fuel_consumption);
	Transport(Transport& obj);
	~Transport();

	virtual void Init() = 0;
	virtual void Show() const = 0;
};

