#include"Matrix.h"
#include "Point.h"

using namespace std;

int main()
{
	/*Matrix<int> obj1(3, 5);
	obj1.Random();
	obj1.Print();
	cout << "\n---------------------------------------\n";
	Matrix<int> b;
	b = obj1;
	b.Print();*/

	Matrix<Point> A(5, 5);

	A.Random();
	//A.Print();
	//cout << endl;


	Matrix<Point> sum = A + 3;
	Matrix<Point> sum2 = 3 + A;
	cout << sum2 << endl;

	//if (sum > sum2)
	//{
	//	cout << "sum > sum2\n";
	//}
}