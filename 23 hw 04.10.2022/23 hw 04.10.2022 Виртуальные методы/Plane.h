#pragma once
#include "Transport.h"
class Plane : public Transport
{
protected:
	string Type;
public:
	Plane();
	Plane(string name, unsigned short number_of_seats, unsigned short fuel_consumption, string type);
	Plane(Plane& obj);
	~Plane();

	void Init();
	void Show() const;
};