#include "Vehicle.h"
#include <iostream>
using namespace std;


Vehicle::Vehicle()
{
	cout << "Vehicle Default Constructor\n";
	driver = 1;
	petrol_amount = 70;
	tank_volume = 120;
}

Vehicle::Vehicle(const int petrol_amount, const int tank_volume) : Vehicle()
{
	cout << "Vehicle Constructor by params\n";
	this->petrol_amount = petrol_amount;
	this->tank_volume = tank_volume;
}

Vehicle::Vehicle(const Vehicle& obj) : Vehicle()
{
	cout << "Vehicle Constructor by oibject\n";
	petrol_amount = obj.petrol_amount;
	tank_volume = obj.tank_volume;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle Destructor\n";
	driver = -1;
	petrol_amount = -1;
	tank_volume = -1;
}


int Vehicle::getTankVolume() const
{
	return tank_volume;
}

int Vehicle::getPetrolAmount() const
{
	return petrol_amount;
}

bool Vehicle::isLeave() const
{
	// ������������
	if (petrol_amount < tank_volume)	// ���� ��� �� �����
	{
		int not_enough_fuel = tank_volume - petrol_amount;	// ������� �� ������� �������

		if (petrol_on_base < not_enough_fuel)	// ���� ������� �� ���� ������������
			return false;
	}


	// ���� ��������
	if (!driver) // ���� ��� ��������
		if (!people_on_base) // ���� ��� ����� �� ����
			return false;
		
	return true;
}

void Vehicle::Arrive()
{
	cout << "Vehicle Arrive\n";


	people_on_base += driver;	// ����� ���������� ��������
	driver--;

	vehicle_on_base++;
}

void Vehicle::Leave()
{
	cout << "Vehicle Leave\n";

	// ������������
	if (petrol_amount < tank_volume)	// ���� ��� �� �����
	{
		int not_enough_fuel = tank_volume - petrol_amount;	// ������� �� ������� �������

		if (petrol_on_base < not_enough_fuel)	// ���� ������� �� ���� ������������
		{
			cout << "Vehicle will not go, because base hasn't enough petrol";
			return;
		}
		else // ������� �� ���� ���������� ��� �������� ����
		{
			petrol_amount = tank_volume;	// ��������� ��������� ���
			petrol_on_base -= not_enough_fuel;	// �������� �� ������� ���� �������
		}
	}


	// ���� ��������
	if (!driver)
	{
		if (people_on_base) // ���� ���� ���� �� ����
		{
			driver++;
			people_on_base--;
		}
		else				// ���� ��� ����� �� ����
		{
			cout << "Vehicle will not go, because base has no people\n";
			return;
		}

	}


	cout << "Vehicle has successfully left\n";
	vehicle_on_base--;
}

void Vehicle::Print() const
{
	cout << "Vehicle Print\n";
	cout << "Driver: " << driver << endl;
	cout << "Petrol amount: " << petrol_amount << endl;
	cout << "Tank volume: " << tank_volume << endl;
}