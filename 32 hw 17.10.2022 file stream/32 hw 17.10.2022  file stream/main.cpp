#include "Directory.h"
#include <iostream>
using namespace std;

int main()
{
	//Directory obj1("Spark", "Aleksei", "380973563534", "Odesa", "Software");
	//obj1.Save();
	//Directory obj2("MedService", "Kontantyn", "380960355982", "Kyiv", "Medicine");
	//obj2.Save();
	//obj2.Read();

	Directory obj3 = SearchByCompanyName("MedService");
	obj3.Print();

	return 0;
}