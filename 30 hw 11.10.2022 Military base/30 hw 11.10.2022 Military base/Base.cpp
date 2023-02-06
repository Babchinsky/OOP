#include "Base.h"
#include <iostream>
using namespace std;

int Base::people_on_base = 0;
int Base::vehicle_on_base = 0;
int Base::petrol_on_base = 0;
int Base::goods_on_base = 0;


Base::Base()
{
	cout << "Base Default Constructor\n";
	people_on_base = 100;
	vehicle_on_base = 10;
	petrol_on_base = 325;
	goods_on_base = 125;
}

Base::Base(const int people_on_base, const int vehicle_on_base, const int petrol_on_base, const int goods_on_base)
{
	cout << "Base Constructor by params\n";
	this->people_on_base = people_on_base;
	this->vehicle_on_base = vehicle_on_base;
	this->petrol_on_base = petrol_on_base;
	this->goods_on_base = goods_on_base;
}


void Base::Input()
{
	cout << "Base Input\n";
	cout << "Enter people on base\n->";
	cin >> people_on_base;
	
	cout << "Enter vehicle on base\n->";
	cin >> vehicle_on_base;

	cout << "Enter petrol on base\n->";
	cin >> petrol_on_base;

	cout << "Enter goods on base\n->";
	cin >> goods_on_base;
}

void Base::Print() const
{
	cout << "Base Print\n";
	cout << "People on base: " << people_on_base << endl;
	cout << "Vehicle on base: " << vehicle_on_base << endl;
	cout << "Petrol on base: " << petrol_on_base << endl;
	cout << "Goods on base: " << goods_on_base	<< endl;
}

