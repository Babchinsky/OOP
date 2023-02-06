#include "Fox.h"

Fox::Fox() : Animal()
{

}

Fox::Fox(int c) : Animal(c)
{
	
}


void Fox::Init()
{
	Animal::Init(); // вызываем функцию инициализации базового класса 
}

void Fox::Show()
{
	if (life)
	{
		cout << "Number of foxes: " << col << endl;
		cout << "Their habitat: " << habitat << endl;
		cout << "Max age of foxes: " << max_age << endl;
		if (col != 0) // если ничего нету 
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

void Fox::Remainder(int amount)
{
	while (col > amount) // цыкл работает пока животных больше 5
	{
		age.Del(col); // удаляем последний "объект"
		col--; // размер уменьшаем на 1 
	}
}

int Fox::GetCount()
{
	return age.GetCount();
}



