#include <iostream>
#include "Menu.h"
using namespace std;

int main()
{
	Base b;
	//b.Input();
	b.Print();
	cout << endl;

	Vehicle *v = new Bus;
	v->Print();
	cout << endl << endl;


	v->Leave();
	b.Print();
	cout << endl;
	v->Print(); 
}