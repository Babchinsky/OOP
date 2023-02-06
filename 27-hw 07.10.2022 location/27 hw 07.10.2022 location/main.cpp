#include <iostream>
#include "Animal.h"
#include "Fox.h"
#include "Bunny.h"
#include "Grass.h"
#include "IsLife.h"
using namespace std;

//The program works if created: Fox, Grass, Bunny.
//Notes!Grass IS IN EVERY LOCATION.
//To perform the check, it is necessary to pass objects to the object of the IsLife class in the following order : Fox, Bunny, Grass.
//The program imitates the simultaneous placement of all objects on locations.If the locations match, the following conditions are met
//1) Fox Bunny Grass habitats matched
//1.1) All foxes over 5 are destroyed.
//1.2) If there are more foxes than rabbits.The fox eats the rabbit.The rabbits are gone.The Grass remains.
//1.3) If there are fewer foxes than rabbits.Then one fox eats the 1st rabbit, the rest of the rabbits remain.
//1.3.1) If there is no Grass, then all the rabbits die.
//1.3.2) If there are more herbs than rabbits, then one rabbit eats one Grass.
//1.3.3) If the Grass is smaller than the rabbits, the Grass will be eaten.
//2) Foxand Bunny are separate from each other(each has Grass)
//2.1) The foxes start eating each other, half of them remain.
//2.2.1) If there is no Grass, then all the rabbits die.
//2.2.2) If there are more herbs than rabbits, then one rabbit eats one Grass.
//2.2.3) If the Grass is smaller than the rabbits, the Grass will be eaten.
//3) After all operations, what is left at the end is shown.

int main()
{
	cout << "Let's create all the animals and Grass" << endl;

	cout << "Create a fox" << endl;
	Fox fox;
	fox.Init();
	system("cls");

	cout << "Create a bunny" << endl;
	Bunny bunny;
	bunny.Init();
	system("cls");

	cout << "Create a Grass" << endl;
	Grass gras;
	gras.Init();
	system("cls");

	cout << "\t\tBEFORE" << endl;
	fox.Show();
	cout << endl << endl;
	bunny.Show();
	cout << endl << endl;
	gras.Show();
	cout << endl << endl;

	IsLife a(fox, bunny, gras);

	return 0;
}