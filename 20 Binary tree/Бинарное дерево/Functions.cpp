#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "Functions.h"

using namespace std;


void Insert(Tree& tree)
{
    ofstream file; // создаем переменную класса ofstream
    file.open("Vocab.txt", ios::app); // ios::app - открывает файл для записи в конец файла 
    SetConsoleCP(1251); // команда меняющая кодировку файла на 1251ю
    // если режим не указан то по умолчанию будет ios::out, при этом режиме старое содержимое файла будет стерто.
    // "Test.bin" имя файла для открытия/записи/чтения
    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        setlocale(NULL, "Rus");
        Node* temp = new Node;

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->m_english;
        file.write(temp->m_english, strlen(temp->GetEnglish())); //запись в файл, (что,сколько символов)
        file.write("\t", 1); // табуляция для отступа между словами в файле

        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->m_russian;
        file.write(temp->m_russian, strlen(temp->GetRussian())); // запись в файл, (что,сколько символов)
        file << endl; // указываем конец строки, переход на новую

        tree.Insert(temp);
    }
    file.close(); // закрываем файл. В файле рус символы будут зашифрованы, при чтении все ок будет.

}


void Print(const Tree& tree)
{
    system("cls");

    tree.Print(tree.GetRoot());

    _getch();
}

void PrintMenu()
{
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Edit\n6. Exit\n";

    system("cls");

    cout << menu;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "Enter an english word to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }

    _getch();
}

void Edit(Tree& tree)
{
    // ------------------------ начало поиска англ слова -----------------------
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer); 
    // ------------------------ конец поиска англ слова -----------------------
    cout << "Enter changes" << endl;
    cin >> node->m_russian;

    _getch();
}