#pragma once
#include "Transport.h"
class Jeep : public Transport
{
protected:
	char* Type;
public:
	Jeep();
	Jeep(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type);
	Jeep(Jeep& obj);
	~Jeep();

	void Init();
	void Show() const;
};