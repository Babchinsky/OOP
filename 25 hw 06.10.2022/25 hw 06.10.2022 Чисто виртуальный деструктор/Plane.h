#pragma once
#include "Transport.h"
class Plane : public Transport
{
protected:
	char* Type;
public:
	Plane();
	Plane(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type);
	Plane(Plane& obj);
	~Plane();

	void Init();
	void Show() const;
};