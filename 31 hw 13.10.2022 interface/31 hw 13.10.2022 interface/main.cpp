#include "Animal.h"
using namespace std;

int main()
{

	IAnimal* ptr = nullptr;

	ptr = new Cat("Rizhik", 4, "Asia"); // ������������ ������(��������� �� ���������) �� ����
	Cat* cat = static_cast<Cat*>(ptr);
	cat->Eat();
	cat->Move();
	cat->Print();
	delete ptr;
	cout << endl << endl;

	ptr = new Parrot("Kesha", 0.6, "Africa"); // ������������ ������(��������� �� ���������) �� ����
	Parrot* parrot = static_cast<Parrot*>(ptr);
	parrot->Eat();
	parrot->Move();
	parrot->Fly();
	parrot->Print();
	delete ptr;
	cout << endl << endl;


	ptr = new Dog("Sharik", 7, "Europe"); // ������������ ������(��������� �� ���������) �� ����
	Dog* dog = static_cast<Dog*>(ptr);
	dog->Eat();
	dog->Move();
	dog->Print();
	delete ptr;
	cout << endl << endl;

	ptr = new Penguin("Ricco", 40, "Antarctica"); // ������������ ������(��������� �� ���������) �� ����
	Penguin* penguin = static_cast<Penguin*>(ptr);
	penguin->Eat();
	penguin->Move();
	penguin->Swim();
	penguin->Print();
	delete ptr;
	cout << endl << endl;

	ptr = new Dolphin("Olsen", 30, "North America"); // ������������ ������(��������� �� ���������) �� ����
	Dolphin* dolphin = static_cast<Dolphin*>(ptr);
	dolphin->Eat();
	dolphin->Move();
	dolphin->Swim();
	dolphin->Print();
	delete ptr;
	cout << endl << endl;
}