#include "Transport.h"
#include "Bicycle.h"
#include "Jeep.h"
#include "Plane.h"
#include "Ship.h"
#include "Truck.h"
#include <iostream>
using namespace std;

int main()
{
	Transport* t1 = nullptr;
	short choice;
	cout << "Create:\n1. Bicycle\n2. Jeep\n3. Plane\n4. Ship\n5. Truck\n->";
	cin >> choice;

	switch (choice)
	{
	case 1:
		t1 = new Bicycle;
		break;
	case 2:
		t1 = new Jeep;
		break;
	case 3:
		t1 = new Plane;
		break;
	case 4:
		t1 = new Ship;
		break;
	case 5:
		t1 = new Truck;
		break;
	}

	t1->Init();
	t1->Show();
	return 0;
}