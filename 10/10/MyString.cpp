#include <iostream>			// стандартная библиотека ввода/вывода
#include "MyString.h"		// подключаем файл реализации
using namespace std;	

short MyString::number = 0;
MyString::MyString()
{
	cout << "Default constructor" << endl;
	// Размер строки
	len = 80;
	//Выделяем динамическую память под символы которые пришли + 1 для символа '\0'
	str = new char[len + 1];
	number++;			// Инкрементируем счётчик объектов
}
MyString::MyString(size_t _len)
{
	cout << "Param constructor" << endl;
	// Размер строки
	len = _len;
	//Выделяем динамическую память под символы которые пришли + 1 для символа '\0'
	str = new char[len + 1];
	number++;			// Инкрементируем счётчик объектов
}
MyString::MyString(MyString& obj)
{
	cout << "Copy constructor" << endl;
	len = obj.len;
	str = new char[len + 1];			// Выделяем память под строку. + 1 для нуль-терминатора

	for (size_t i = 0; i < len + 1; i++)// Копируем строку вместе с нуль-терминатором
		str[i] = obj.str[i];

	number++;
}
void MyString::Init(const char* _str)
{
	// Узнаём длинну введённой строки
	len = strlen(_str);

	// Если строка уже создана, то удаляем
	if (str != nullptr) delete[] str;

	//Выделяем динамическую память под символы которые пришли + 1 для символа '\0'
	str = new char[len + 1];

	//Копируем содержимое строки 2 (которая пришла в функцию) в строку 1 с точным размером строки 2
	strcpy_s(str, strlen(_str) + 1, _str);
}
void MyString::Print()
{
	cout << "String: " << str << endl;
}
MyString::~MyString()
{
	delete[]str;
	len = 0;
}
void MyString::KeyboardInput()
{
	char* buf = new char[len + 1];			// Буфер для введённой строки
	cout << "Input your string\n";

	cin.getline(buf, len);					// Ввод строки

	if (str != nullptr) delete[] str;		// Если строка уже создана, то удаляем

	str = new char[strlen(buf) + 1];		// Пересоздаём строку
	for (size_t i = 0; i < strlen(buf); i++)
		str[i] = buf[i];					// Копируем посимвольно из буфера в строку

	str[strlen(buf)] = '\0';				// Последний символ нуль-терминатор
	len = strlen(str);						// Меняем зарезервированный размер на настоящий
	delete[]buf;							// Очищаем буфер

}
void MyString::MyStrСpy(MyString& obj)		// копирование строк
{
	delete[] str;							// Удаляем строку
	len = obj.len;							// Копируем размер
	str = new char[len + 1];				// Создаём строку нужного размера
	for (size_t i = 0; i < len; i++)		// Копируем каждый символ
		str[i] = obj.str[i];
	str[len] = '\0';						// Помещаем нуль-терминаторв в конец
}
bool MyString::MyStrStr(const char* _str)
{

	if (strlen(_str) > len) return false;	// если длина искомой подстроки больше, то априори её не может быть внутри строки

	int counter;							// счётчик
	for (size_t i = 0; i < len; i++)		// перебор массива строки
	{
		counter = 0;
		for (size_t j = 0; j < strlen(_str); j++)	// если первый символ совпадает
		{
			if (_str[j] == str[i + j]) counter++;	// если символы совпадают, то инкрементируем счётчик
			if (counter == strlen(_str)) return true;// если счётчик совпадает с размером искомой строки, то подстрока найдена в строке
		}
	}

	return false;
}
size_t  MyString::MyChr(char ch)
{
	for (size_t i = 0; i < len; i++)		// перебор всех символов массива
		if (str[i] == ch) return i;			// если находит, то сразу возвращает индекс

	return -1;								// если не находит
}
size_t MyString::MyStrLen()
{
	return len;
}
void MyString::MyStrCat(MyString& obj)
{
	char* buf = new char[len];				// Выделяем под буффер размер строки объекта(без нуль-терминатора)
	size_t buf_len = len;					// Копируем в буферный размер размер строки объекта

	for (size_t i = 0; i < len; i++)
		buf[i] = str[i];					// копируем строку объекта в буфер
	delete[]str;							// удаляем строку объекта


	str = new char[buf_len + obj.len + 1];	// Выделяем память под объединяющую строку

	size_t i = 0;							// Общий счётчик индекса общей строки

	for (; i < buf_len; i++)
		str[i] = buf[i];					// Копируем посимвольно буфер в общую строку

	for (size_t j = 0; j < obj.len; )		// Копируем посимвольно строку параметров в общую строку
	{
		str[i] = obj.str[j];
		j++;
		i++;
	}

	delete[]buf;							// Очищаем буфер
	len = buf_len + obj.len;				// Общий размер
	str[len] = '\0';						// Добавляем нуль-терминатор в конец
}
void MyString::MyDelChr(char ch)
{
	size_t counter = 0;						// счётчик количества искомых символов
	for (size_t i = 0; i < len; i++)		// Проходимся по символам строки и сравниваем их с искомым символом
		if (str[i] == ch) counter++;		// Если совпадает, то инкрементируем счётчик

	size_t buf_len = len;					// Буферный размер
	char* buf = new char[buf_len];			// Буферная строка

	for (size_t i = 0; i < buf_len; i++)	// Посимвольно копируем строку в буфер
		buf[i] = str[i];

	len -= counter;							// Отнимем от размера количество удаляемых символов
	delete[]str;							// Удаляем строку
	str = new char[len + 1];				// Выделяем память под новую строку.+ 1 для нуль-терминатора

	for (size_t i = 0, j = 0; i < buf_len; i++)	// i для прогона буфера. Каждую итерацию шагаем по буфферу
		if (buf[i] != ch)						// j для прогона новой строки без удаляемых символов
		{
			str[j] = buf[i];
			j++;								// Шагаем по строке без удаляемых символов
		}

	str[len] = '\0';						// Добавляем нуль-терминатор в конец
	delete[]buf;							// Очищаем буфер
}
short MyString::MyStrCmp(MyString& obj)
{
	if (len < obj.len) return -1;			// Первая строка меньше, чем вторая
	else if (len > obj.len) return 1;		// Первая строка больше, чем вторая
	else return 0;							// Строки равны!
}

short MyString::StrsNumber()
{
	return number;
}

// =
MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj) return *this;					// если справа тот же объект, то сразу возвращаем
	if (str != nullptr) delete[]str;			// если заполнено, очищаем кучу

	str = new char[strlen(obj.str) + 1];		// выделяем память

	// глубокое копирование 
	strcpy_s(str, strlen(obj.str) + 1, obj.str);

	len = obj.len;

	return *this; // a = b = c; 
}
// () - вывод в консоль
void MyString::operator() ()const
{
	for (size_t i = 0; i < len; i++)
		cout << str[i];
	cout << endl;
}
//преобразование типов к int
MyString::operator int() const
{
	return len;
}
//преобразование типов  к char*
MyString::operator char* () const
{
	char* temp = new char[strlen(str) + 1];
	strcpy_s(temp, strlen(str) + 1, str);
	return temp;
}
// получение значения по индексу
char MyString::operator[](int index)const
{
	if (index >= 0 && index < strlen(str)) return str[index];
	return '\0';
}