#pragma once
class MyString
{
private:
	char* str;
	size_t len;
	static short number;				// Количество объектов
public:

	MyString();							// Конструктор по умолчанию создаёт строку размером 80 символов
	MyString(size_t);					// Конструктор по умолчанию создаёт строку любого размера
	MyString(MyString&);				// Конструктор копирования
	void Init(const char*);				// Инициализация строки пользовательской строкой
	void Print();						// Вывод строки на экран
	~MyString();						// Деструктор
	void KeyboardInput();				// Ввод с клавиатуры
	void MyStrСpy(MyString&);			// Копирование строки из параметров в строку объекта
	size_t  MyChr(char);				// поиск символа в строке(индекс найденного символа, либо -1)
	bool MyStrStr(const char*);			// поиск подстроки в строке
	size_t MyStrLen();					// Возвращает длину строки
	void MyStrCat(MyString&);			// объединение строк
	void MyDelChr(char);				// удаляет указанный символ 
	short MyStrCmp(MyString&);			// сравнение строк 

	short StrsNumber();					// Показывает статическое поле(количество объектов)

	MyString& operator=(const MyString&);// =
	void operator() ()const;			 // () - вывод в консоль
	operator int() const;				 //преобразование типов к int
	operator char* () const;			 //преобразование типов  к char*
	char operator[](int index)const;	 // получение значения по индексу
};