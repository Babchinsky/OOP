#include <iostream>
using namespace std;

class Book
{
private:	// реализация
	char* name;
	int pages;
public:		// интерфейс
	
	Book(const char* n);			// Делегированный конструктор
	Book(const char* n, int p) ;	// Делегированный конструктор(главный) с 2 параметрами
	void Print();					// Вывод на экран
	~Book();						// Деструктор
};

Book::Book(const char* n)
{
	// Если строка уже создана, то удаляем
	if (name != nullptr) delete[] name;

	pages = 0;	// инициализируем странички 0

	//Выделяем динамическую память под символы которые пришли + 1 для символа '\0'
	name = new char[strlen(n) + 1];

	//Копируем содержимое строки 2 (которая пришла в функцию) в строку 1 с точным размером строки 2
	strcpy_s(name, strlen(n) + 1, n);
};
Book::Book(const char* n, int p) : Book(n)
{
	pages = p;
}; // реализовать делегирование!!!
void Book::Print()
{
	cout << "Name: \"" << name << "\"\n";
	cout << "Pages: " << pages << endl;
};
Book::~Book()
{
	delete[] name;
	pages = 0;
};


class Student
{
	char* name;
	const double step;//  cтепендия 
	Book book; //!!!
	static int number;		//	количество студентов
public:
	// Конструктор с инициализаторами
	Student() :step(0), book(nullptr, 0){};
	// Конструктор с инициализаторами
	Student(const char* n, double st, const char* bookName, int bookPages);// использовать инициализаторы!!!
	~Student();			// Деструктор
	void Print();		// Вывод на экран
};
int Student::number = 0;

Student::Student(const char* n, double st, const char* bookName, int bookPages) :step(st), book(bookName, bookPages)
{
	number++;
	// Если строка уже создана, то удаляем
	if (name != nullptr) delete[] name;

	st = 0;	// инициализируем cтепендию 0

	//Выделяем динамическую память под символы которые пришли + 1 для символа '\0'
	name = new char[strlen(n) + 1];

	//Копируем содержимое строки 2 (которая пришла в функцию) в строку 1 с точным размером строки 2
	strcpy_s(name, strlen(n) + 1, n);
}

Student::~Student()
{
	delete[]name;
}

void Student::Print()
{
	cout << "Number: " << number << endl;
	cout << "Name: " << name << endl;
	cout << "Step: " << step << endl;
	book.Print();
}


// показать использование объектом в функции main
int main()
{
	Book obj1("The Great Gatsby", 224);
	obj1.Print();
	cout << endl << endl;

	Student student1("Oleksii", 1250, "Clockwork Orange", 280);
	student1.Print();
}