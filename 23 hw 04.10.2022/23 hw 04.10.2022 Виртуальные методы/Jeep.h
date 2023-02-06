#pragma once
#include "Transport.h"
class Jeep : public Transport
{
protected:
	string Type;
public:
	Jeep();
	Jeep(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type);
	Jeep(Jeep& obj);
	~Jeep();

	void Init();
	void Show() const;
};


