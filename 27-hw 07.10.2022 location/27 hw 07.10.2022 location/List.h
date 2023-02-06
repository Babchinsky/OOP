#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Elem
{
    T data; // данные
    Elem<T>* next, * prev;
};

template <class T>
class List
{
    // Голова, хвост
    Elem<T>* Head, * Tail;
    // Количество элементов
    int Count;

public:

    // Конструктор
    List();
    // Конструктор копирования
    List(const List&);
    // Деструктор
    ~List();

    // Получить количество
    int GetCount();
    // Получить элемент списка
    Elem<T>* GetElem(int);
    int GetData(int); // метод который возвращает значение в данной точке

    // Удалить весь список
    void DelAll();
    // Удаление элемента, если параметр не указывается,
    // то функция его запрашивает
    void Del(int pos = 0);
    // Вставка элемента, если параметр не указывается,
    // то функция его запрашивает
    void Insert(int pos = 0);

    // Добавление в конец списка
    void AddTail(T n);

    // Добавление в начало списка
    void AddHead(T n);

    // Печать списка
    void Print();
};



template <class T>
List<T>::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

template <class T>
List<T>::List(const List<T>& L)
{
    Head = Tail = NULL;
    Count = 0;

    // Голова списка, из которого копируем
    Elem<T>* temp = L.Head;
    // Пока не конец списка
    while (temp != 0)
    {
        // Передираем данные
        AddTail(temp->data);
        temp = temp->next;
    }
}

template <class T>
List<T>::~List()
{
    // Удаляем все элементы
    DelAll();
}

template <class T>
void List<T>::AddTail(T n)
{
    // Создаем новый элемент
    Elem<T>* temp = new Elem<T>;
    // Следующего нет
    temp->next = 0;
    // Заполняем данные
    temp->data = n;
    // Предыдущий - бывший хвост
    temp->prev = Tail;

    // Если элементы есть?
    if (Tail != 0)
        Tail->next = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - хвостовой
        Tail = temp;

    Count++;
}

template <class T>
void List<T>::AddHead(T n)
{
    // новый элемент
    Elem<T>* temp = new Elem<T>;

    // Предыдущего нет
    temp->prev = 0;
    // Заполняем данные
    temp->data = n;
    // Следующий - бывшая голова
    temp->next = Head;

    // Если элементы есть?
    if (Head != 0)
        Head->prev = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - головной
        Head = temp;

    Count++;
}


template <class T>
void List<T>::Insert(int pos)
{
    // если параметр отсутствует или равен 0, то запрашиваем его
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }

    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count + 1)
    {
        // Неверная позиция
        cout << "Incorrect position !!!\n";
        return;
    }

    // Если вставка в конец списка
    if (pos == Count + 1)
    {
        // Вставляемые данные
        int data;
        cout << "Input new number: ";
        cin >> data;
        // Добавление в конец списка
        AddTail(data);
        return;
    }


    // Счетчик
    int i = 1;

    // Отсчитываем от головы n - 1 элементов
    Elem<T>* Ins = Head;

    while (i < pos)
    {
        // Доходим до элемента, 
        // перед которым вставляемся
        Ins = Ins->next;
        i++;
    }

    // Доходим до элемента, 
    // который предшествует
    Elem<T>* PrevIns = Ins->prev;

    // Создаем новый элемент
    Elem<T>* temp = new Elem<T>;

    // Вводим данные
    cout << "Input new number: ";
    cin >> temp->data;

    // настройка связей
    if (PrevIns != 0 && Count != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    Count++;
}

template <class T>
void List<T>::Del(int pos)
{
    // если параметр отсутствует или равен 0, то запрашиваем его
    if (pos == 0)
    {
        cout << "Input position: ";
        cin >> pos;
    }
    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count)
    {
        // Неверная позиция
        cout << "Incorrect position !!!\n";
        return;
    }
    ///------------------------------------------------
    // Счетчик
    Elem<T>* Del = nullptr;
    int i = 1;

    // Определяем с какой стороны 
    // быстрее двигаться
    if (pos <= Count / 2)
    {
        // Отсчет с головы
        Del = Head;

        while (i < pos)
        {
            // Двигаемся до нужного элемента
            Del = Del->next;
            i++;
        }
    }
    else
    {
        // Отсчет с хвоста
        Del = Tail;
        while (i <= Count - pos)
        {
            // Двигаемся до нужного элемента
            Del = Del->prev;
            i++;
        }
    }
    /////---------------------------------------------

    // Доходим до элемента, 
    // который предшествует удаляемому
    Elem<T>* PrevDel = Del->prev;
    // Доходим до элемента, который следует за удаляемым
    Elem<T>* AfterDel = Del->next;

    // Если удаляем не голову
    if (PrevDel != 0 && Count != 1)
        PrevDel->next = AfterDel;
    // Если удаляем не хвост
    if (AfterDel != 0 && Count != 1)
        AfterDel->prev = PrevDel;

    // Удаляются крайние?
    if (pos == 1)
        Head = AfterDel;
    if (pos == Count)
        Tail = PrevDel;

    // Удаление элемента
    delete Del;

    Count--;
}

template <class T>
void List<T>::Print()
{
    // Если в списке присутствуют элементы, то пробегаем по нему
    // и печатаем элементы, начиная с головного
    if (Count != 0)
    {
        Elem<T>* temp = Head;
        cout << "( ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}

template <class T>
void List<T>::DelAll()
{
    // Пока остаются элементы, удаляем по одному с головы
    while (Count != 0)
        Del(1);
}

template <class T>
int List<T>::GetCount()
{
    return Count;
}
/// <summary>

template <class T>
Elem<T>* List<T>::GetElem(int pos)
{
    Elem<T>* temp = nullptr;
    // Счетчик
    int i = 1;

    // Определяем с какой стороны 
    // быстрее двигаться
    if (pos <= Count / 2)
    {
        // Отсчет с головы
        temp = Head;

        while (i < pos)
        {
            // Двигаемся до нужного элемента
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // Отсчет с хвоста
        temp = Tail;
        while (i <= Count - pos)
        {
            // Двигаемся до нужного элемента
            temp = temp->prev;
            i++;
        }
    }
    /////---------------------------------------------

    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count)
    {
        // Неверная позиция
        cout << "Incorrect position !!!\n";
        return 0;
    }

    return temp;
}

template <class T>
int List<T>::GetData(int pos)
{
    Elem<T>* temp = nullptr;
    // Счетчик
    int i = 1;

    // Определяем с какой стороны 
    // быстрее двигаться
    if (pos <= Count / 2)
    {
        // Отсчет с головы
        temp = Head;

        while (i < pos)
        {
            // Двигаемся до нужного элемента
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // Отсчет с хвоста
        temp = Tail;
        while (i <= Count - pos)
        {
            // Двигаемся до нужного элемента
            temp = temp->prev;
            i++;
        }
    }
    /////---------------------------------------------

    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count)
    {
        // Неверная позиция
        cout << "Incorrect position !!!\n";
        return 0;
    }

    return temp->data;
}
