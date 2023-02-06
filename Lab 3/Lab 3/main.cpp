#include "Matrix.h"

int main()
{
	Matrix<int> obj1(3, 5);
	obj1.Random();
	obj1.Print();

	cout << endl << endl;

	obj1 = obj1 + 5;
	obj1.Print();

	cout << endl << endl;

	Matrix<int> obj2 = obj1;
	obj2.Print();

	cout << "Min: " << obj2.GetMin() << endl;
	cout << "Max: " << obj2.GetMax() << endl;
}