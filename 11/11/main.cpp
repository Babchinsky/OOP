#include "var.h"
#include <iostream>
using namespace std;

int main()
{
	//var a = 15;
	//var b("Hello");
	//var c = 7.8;
	var d = "50";

	//////////char buf[16];
	//////////strcpy_s(buf, 16, "Start");
	//////////strcat_s(buf, 16, " End");               // Correct
	//////////cout << buf;
	
	//char a[100] = "Hello";
	//char b[100] = " world!";

	//cout << strlen(a) << endl;
	//cout << strlen(b) << endl;
	//strcat_s(a, sizeof(a), b);
	//cout << a[0] << endl;
	//cout << a[1] << endl;
	//cout << a[2] << endl;
	//cout << a[3] << endl;
	//cout << a[4] << endl;
	//cout << a;

	var c = d;
	c.Print();
}