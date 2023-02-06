#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;

int main()
{
	//Person obj1;
	//obj1.Print();
	//cout << endl << endl;

	//Person obj2("Alex", 19);
	//obj2.Print();
	//cout << endl << endl;

	//obj1 = obj2;
	//obj1.Print();
	//cout << endl << endl;

	//Person obj3 = obj2;
	//obj3.Print();
	//cout << endl << endl;

	////////////////////////////////////////////////////////

	Student st1;
	st1.Print();
	cout << endl << endl;

	Student st2("Oleg", 20, "ITStep");
	st2.Print();
	cout << endl << endl;

	Student st3 = st2;
	st3.Print();
	cout << endl << endl;

	Student st4;
	st4 = st2;
	st4.Print();
	cout << endl << endl;

	////////////////////////////////////////////////////////

	//Teacher t1;
	//t1.Print();
	//cout << endl << endl;

	//Teacher t2("Oleg", 20, "ITStep");
	//t2.Print();
	//cout << endl << endl;

	//Teacher t3 = t2;
	//t3.Print();
	//cout << endl << endl;

	//Teacher t4;
	//t4 = t2;
	//t4.Print();
	//cout << endl << endl;
}
