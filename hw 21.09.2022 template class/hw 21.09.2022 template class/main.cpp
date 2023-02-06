#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	MyArray<char> obj1(10);
	MyArray<char> obj2(2);
	for (int i = 0; i < obj1.GetSize(); i++)
	{
		obj1[i] = i + 65;
	}
	for (int i = 0; i < obj2.GetSize(); i++)
	{
		obj2[i] = i + 117;
	}
	obj1.SetSize(obj1.GetSize(), 5);
	obj1.FreeExtra();
	obj1.Add('Y');
	obj1.Append(obj2);
	cout << obj1 << endl;
	obj1.InsertAt('b', obj1.GetSize() + 21);
	cout << obj1 << endl;
	obj1.RemoveAt(0);
	cout << obj1 << endl;
	cout << obj2.IsEmpty() << endl;
	obj2.RemoveAll();
	cout << obj2.IsEmpty() << endl;

	return 0;
}


/*RESULT*/

/*

(A, B, C, D, E, F, G, H, I, J, Y, u, v)
(A, B, C, D, E, F, G, H, I, J, Y, u, v, b)
(B, C, D, E, F, G, H, I, J, Y, u, v, b)
0
1

*/