#pragma once
#include <string>
using namespace std;

class Transport
{
protected:
	char* Name;
	unsigned short NumberOfSeats;
	unsigned short FuelConsumption;
public:
	Transport();
	Transport(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption);
	Transport(Transport& obj);
	virtual ~Transport() = 0;

	virtual void Init();
	virtual void Show() const;
};