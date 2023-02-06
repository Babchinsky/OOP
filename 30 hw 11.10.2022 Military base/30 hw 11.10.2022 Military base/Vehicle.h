#pragma once
#include "Base.h"

class Vehicle :public Base
{
protected:
    int driver; 
	int petrol_amount;		// ������� ������
	int tank_volume;		// ����� ���������
public:
	Vehicle();
	Vehicle(const int petrol_amount, const int tank_volume);
	Vehicle(const Vehicle& obj);
	~Vehicle();

	int getTankVolume() const;
	int getPetrolAmount() const;
	bool isLeave() const;

	virtual void Arrive();
	virtual void Leave();

	virtual void Print() const;
};
