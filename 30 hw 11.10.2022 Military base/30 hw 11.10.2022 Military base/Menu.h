#pragma once
#include <iostream>
#include "Base.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Truck.h"
using namespace std;

void Menu()
{
	system("cls");

	cout << "  1 - Create base\n";
	cout << "  2 - Create bus\n";
	cout << "  3 - Create truck\n";
	cout << "  4 - Add \n";
	cout << "ESC - Exit\n";
}