#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

class Stack
{
	// Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 20 };
	// Массив для хранения данных
	char st[FULL + 1];
	// Указатель на вершину стека
	int top;

public:
	// Конструктор
	Stack();

	// Добавление элемента
	void Push(char c);
	void Push(char c, int _pos);

	// Извлечение элемента
	char Pop();


	// Очистка стека
	void Clear();

	// Проверка существования элементов в стеке
	bool IsEmpty();

	// Проверка на переполнение стека
	bool IsFull();

	// Количество элементов в стеке
	int GetCount();

	void Output();
	char Output(int _pos);
};

Stack::Stack()
{
	// Изначально стек пуст
	top = EMPTY;
}

void Stack::Clear()
{
	// Эффективная "очистка" стека 
	// (данные в массиве все еще существуют, 
	// но функции класса, ориентированные на работу с вершиной стека,
	// будут их игнорировать)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// Пуст?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// Полон?
	return top == FULL;
}

int Stack::GetCount()
{
	// Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(char c)
{
	// Если в стеке есть место, то увеличиваем указатель
	// на вершину стека и вставляем новый элемент
	if (!IsFull())
		st[++top] = c;
}

void Stack::Push(char c, int _pos)
{
	// Если в стеке есть место, то увеличиваем указатель
	// на вершину стека и вставляем новый элемент
	if (!IsFull())
		st[_pos] = c;
}

char Stack::Pop()
{
	// Если в стеке есть элементы, то возвращаем верхний и
	// уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[top--];
	else // Если в стеке элементов нет
		return 0;
}

void Stack::Output()
{
	for (int i = 0; i < top + 1; i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;
}

char Stack::Output(int _pos)
{
	return st[_pos];
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	Stack ST;	//stack
	string str; //A

	char end_open_skobka;           // последн¤¤ открывающа¤ скобка
	int pos = -1;


	cout << "Enter expression: ";
	cin >> str;
	cout << str << endl;

	int round, figured, squared;

	round = figured = squared = 0;
	

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') round++;
		else
			if (str[i] == ')') round--;
			else
				if (str[i] == '{') figured++;
				else
					if (str[i] == '}') figured--;
					else
						if (str[i] == '[') squared++;
						else
							if (str[i] == ']') squared--;

		if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
		{
			end_open_skobka = str[i];
			pos++;
			ST.Push(str[i]);///////////////////////////////
		}

		if (round < 0 || figured < 0 || squared < 0)
		{
			cout << "Лишня закрывающая скобка" << endl;
			break;
		}

		if (((str[i] == ')') && (end_open_skobka != '(')) ||
			((str[i] == '}') && (end_open_skobka != '{')) ||
			((str[i] == ']') && (end_open_skobka != '[')))
		{
			cout << "Закрывающая скобка другого типа" << endl;
			break;
		}

		if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']'))
		{
			pos--;
			if (pos >= 0)
			{
				end_open_skobka = ST.Output(pos);////////////////////////////
			}
			ST.Push(str[i]);
		}
	}


	if (round || figured || squared) 
		cout << "Скобки расставлены неправильно" << endl;
	else cout << "Скобки расставлены правильно" << endl;

	ST.Output();
}