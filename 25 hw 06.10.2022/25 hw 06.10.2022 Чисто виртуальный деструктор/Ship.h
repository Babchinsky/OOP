#pragma once
#include "Transport.h"
class Ship : public Transport
{
protected:
	char* Type;
public:
	Ship();
	Ship(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type);
	Ship(Ship& obj);
	~Ship();

	void Init();
	void Show() const;
};