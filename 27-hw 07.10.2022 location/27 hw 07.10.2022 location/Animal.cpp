#include "Animal.h"
#include "List.h"

Animal::Animal() : age() // ��� �������� (������) ���������� � ������������ �� ��������
{
	col = 0;
	max_age = 5;
	habitat = "Forest";
	life = false;
}

Animal::Animal(int c)
{
	col = c;
	cout << "Enter max age: ";
	cin >> max_age;

	for (int i = 0; i < col; i++) // ��������� ������� (� ������) ������� ���������
	{
		int temp = 0;
		cout << "Enter age " << (i + 1) << " animals: ";
		cin >> temp;
		age.AddTail(temp);
	}
	this->Local(); // �������� ������� ��� ����������� ����� ���������� ���������
	this->Analysis();
}

Animal::~Animal()
{
	age.~List(); // �������� ���������� ��� ������ 
}

void Animal::Local()
{
	int var, temp;
	cout << "Select habitat: " << endl;
	cout << "1.Forest\n2.Field\n3.Steppe\n4.Jungle\n5.Dessert\n6.Sea" << endl;
	cin >> temp;
	if (temp > 0 && temp <= 6) // ���� � ��������� ��������� �����, ����� ����������� 
	{
		var = temp;
	}
	else // ���� ���, ������ ������ ��� ��� �� ��� ��� ���� �� ����� �� 
	{
		cout << "Error. Select correct number of habitat: " << endl;
		cout << "1.Forest\n2.Field\n3.Steppe\n4.Jungle\n5.Dessert\n6.Sea" << endl;
		cin >> var;
	} // ����� ������ ���� ������ 

	switch (var)
	{
	case 1:
	{
		habitat = "Forest";
		break;
	}
	case 2:
	{
		habitat = "Field";
		break;
	}
	case 3:
	{
		habitat = "Steppe";
		break;
	}
	case 4:
	{
		habitat = "Jungle";
		break;
	}
	case 5:
	{
		habitat = "Dessert";
		break;
	}
	case 6:
	{
		habitat = "Sea";
		break;
	}
	}
}

string Animal::GetHabitat()
{
	return habitat;
}


void Animal::Analysis()
{
	cout << "Analysis..." << endl;
	int temp = col;
	for (int j = 1, i = 1; i <= temp; i++) // ����� ������ �������� ��� �������, ��� ���
	{
		if (age.GetData(j) >= max_age) // ��� �������� � ������ ������� ��������� 
		{
			int a = age.GetData(j);
			cout << "Unfortunately the animal " << i << " did not survive." << endl;
			cout << "Age animal: " << age.GetData(j) << " max age: " << max_age << endl;
			age.Del(j); // ������� ����� ��������� 
			col--; // ���������� �������� ����������� 
		}
		else
		{
			j++; // ���� ������ �� ��������� �� ������������ �� ������ �� 1
		}
	}
	if (col > 0) // ���� ���� �������, �� ���� ����� 
	{
		life = true;
	}
	else // ���� �������� ���� col == 0 ����� ����� ���� 
	{
		life = false;
	}
	Sleep(5000);
	system("cls");
}

void Animal::Init()
{
	cout << "Enter the amount of animals: ";
	cin >> col;
	cout << "Enter max age animals: ";
	cin >> max_age;
	for (int i = 0; i < col; i++) // ��������� ������� (� ������) ������� ���������
	{
		int temp = 0;
		cout << "Enter age " << (i + 1) << " animals: ";
		cin >> temp;
		age.AddTail(temp);
	}
	this->Local(); // ��� ������� ���������� ������� ����������� ����� �������� 
	this->Analysis();
}
