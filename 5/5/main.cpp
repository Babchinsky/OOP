#include <iostream>			// стандартная библиотека ввода/вывода
#include <Windows.h>		// библиотека для подключения русского языка

using namespace std;

class MyString
{
private:
	char* str;
	size_t len;	
	static short number;		// Количество объектов
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
	void RussianLanguage();				// Подключение русского языка
};
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

	for (size_t j = 0; j < obj.len;  )		// Копируем посимвольно строку параметров в общую строку
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
void MyString::RussianLanguage()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}


int main()
{	
	MyString str1;
	str1.Init("Hello, world!");
	str1.Print();

	MyString str2 = str1;
	str2.Print();
}