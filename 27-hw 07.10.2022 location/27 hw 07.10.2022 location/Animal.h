#pragma once
#include <iostream>
#include "List.h"
#include <conio.h>
#include <Windows.h>
using namespace std;

class Animal
{
protected:
	int col;				// ���������� �������� 
	int max_age;			// ������������ ������� �������� 
	List<int> age;			//������ �� �������� ������� ��������� �� ����������� � ������� ������.
	string habitat;			// ����� �������� ��������
	bool life;				// ���� ����� �� ��������
public:
	Animal();				// �� ��������� 
	Animal(int c);			// ������ ���������� ��������, � ������� �������� �������� ������ ������� ������� ���������.
	~Animal();				// ���������� (�������� ���������� ������)

	virtual void Local() final;
	virtual void Analysis() final;
	virtual void Init();	// ������������� 
	virtual void Show() = 0;  // ����� ����������� �����, �� �������� ������� ������ ������, � �������� ��� ����� ����� ��� ���� ��������������!

	virtual string GetHabitat(); // ���������� ����� �������� 
};