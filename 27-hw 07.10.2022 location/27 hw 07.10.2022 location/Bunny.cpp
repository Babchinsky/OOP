#include "Bunny.h"

Bunny::Bunny() : Animal()
{

}

Bunny::Bunny(int c) : Animal(c)
{
	
}

void Bunny::Init()
{
	Animal::Init(); // �������� ������� ������������� �������� ������ 
}

void Bunny::Show()
{
	if (life)
	{
		cout << "Number of Bunny: " << col << endl;
		cout << "Their habitat: " << habitat << endl;
		cout << "Max age of Bunny: " << max_age << endl;
		if (col != 0) // ���� ������ ���� 
		{
			cout << "Their age: " << endl;
			age.Print();
		}
	}
	else
	{
		cout << "There is no life" << endl;
	}
}

void Bunny::Remainder(int amount)
{
	while (col > amount) // ���� �������� ���� �������� ������ ���������� �������� 
	{
		age.Del(col); // ������� ��������� "������"
		col--; // ������ ��������� �� 1 
	}
}

int Bunny::GetCount()
{
	return age.GetCount();
}
