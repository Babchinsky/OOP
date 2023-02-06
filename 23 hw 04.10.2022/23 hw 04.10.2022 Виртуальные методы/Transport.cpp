#include "Transport.h"
#include <iostream>
using namespace std;

Transport::Transport()
{
	cout << "Transport Constructor by default\n";
	Name = "Default";
	NumberOfSeats = 0;
	FuelConsumption = 0;
}
Transport::Transport(string name, unsigned short number_of_seats, unsigned short fuel_consumption)
{
	cout << "Transport Constructor by params\n";
	Name = name;
	NumberOfSeats = number_of_seats;
	FuelConsumption = fuel_consumption;
}
Transport::Transport(Transport& obj)
{
	cout << "Transport Constructor by object\n";
	Name = obj.Name;
	NumberOfSeats = obj.NumberOfSeats;
	FuelConsumption = obj.FuelConsumption;
}
Transport::~Transport()
{
	cout << "Transport Destructor\n";
	Name = "";
	NumberOfSeats = -1;
	FuelConsumption = -1;
}

//void Transport::Init() = 0
//{
//	cout << "Transport Init\n";
//	cout << "Enter name\n->";
//	cin >> Name;
//	cout << "Enter number of seats\n->";
//	cin >> NumberOfSeats;
//	cout << "Enter fuel consumption\n->";
//	cin >> FuelConsumption;
//}
//void Transport::Show() const = 0
//{
//	cout << "Transport Show\n";
//	cout << "Name: " << Name << endl;
//	cout << "Number of seats: " << NumberOfSeats << endl;
//	cout << "Fuel consumption: " << FuelConsumption << endl;
//}