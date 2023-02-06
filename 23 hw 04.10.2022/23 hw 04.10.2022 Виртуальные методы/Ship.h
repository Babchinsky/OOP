#pragma once
#include "Transport.h"
class Ship : public Transport
{
protected:
	string Type;
public:
	Ship();
	Ship(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type);
	Ship(Ship& obj);
	~Ship();

	void Init();
	void Show() const;
};

