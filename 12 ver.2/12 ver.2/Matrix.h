#pragma once
#include <iostream>
using namespace std;

template <class T>
class Matrix
{
	T** arr;	// двумерный массив(матрица)
	int row;	// строки
	int column; // столбцы

public:
	// Конструкторы, деструктор
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix<T>&);
	~Matrix();

	Matrix<T>& operator=(const Matrix<T>&);

	Matrix<T> operator+(int) const;
	Matrix<T> operator-(int) const;
	Matrix<T> operator*(int) const;
	Matrix<T> operator/(int) const;
	Matrix<T> operator-() const;


	bool operator>(const Matrix<T>&) const;
	bool operator<(const Matrix<T>&) const;
	bool operator>=(const Matrix<T>&) const;
	bool operator<=(const Matrix<T>&) const;

	void Print();
	void Random();

	template <class T>
	friend ostream& operator<<(ostream&, const Matrix<T>&);
};

// Конструкторы
template<class T>
Matrix<T>::Matrix()
{
	arr = nullptr;
	row = column = 0;
}
template<class T>
Matrix<T>::Matrix(int row, int column)
{
	this->row = row;
	this->column = column;

	arr = new T * [this->row];

	for (int i = 0; i < this->row; i++)
		arr[i] = new T[this->column];
}
template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj) : Matrix()
{
	row = obj.row;
	column = obj.column;
	arr = new T * [row];
	
	for (int i = 0; i < row; i++)
		arr[i] = new T[column];


	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = obj.arr[i][j];
}
// Деструктор
template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < row; i++)
		delete[] arr[i];
	delete[]arr;
}

// Перегрузка методов
template<class T>
Matrix<T> Matrix<T>::operator+(int k) const
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			temp.arr[i][j] = temp.arr[i][j] + k;

	return temp;
}
template<class T>
Matrix<T> Matrix<T>::operator-(int k) const
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			temp.arr[i][j] = temp.arr[i][j] - k;

	return temp;
}
template<class T>
Matrix<T> Matrix<T>::operator*(int k) const
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			temp.arr[i][j] = temp.arr[i][j] * k;
	
	return temp;
}
template<class T>
Matrix<T> Matrix<T>::operator/(int k) const
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			temp.arr[i][j] = temp.arr[i][j] / k;

	return temp;
}
template<class T>
Matrix<T> Matrix<T>::operator-() const
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			temp.arr[i][j] = -temp.arr[i][j];
}

// Операторы сравнения
template<class T>
inline bool Matrix<T>::operator>(const Matrix<T>& obj) const
{
	return ((row * column) > (obj.row * obj.column));
}
template<class T>
inline bool Matrix<T>::operator<(const Matrix<T>& obj) const
{
	return ((row * column) < (obj.row * obj.column));
}
template<class T>
inline bool Matrix<T>::operator>=(const Matrix<T>& obj) const
{
	return ((row * column) >= (obj.row * obj.column));
}
template<class T>
inline bool Matrix<T>::operator<=(const Matrix<T>& obj) const
{
	return ((row * column) <= (obj.row * obj.column));
}
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& obj)
{
	if (this == &obj) return *this;

	if (arr != nullptr)
		for (int i = 0; i < row; i++)
			delete[] arr[i];
		delete[]arr;

	row = obj.row;
	column = obj.column;

	arr = new T * [row];
	for (size_t i = 0; i < row; i++)
		arr[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = obj.arr[i][j];
	return *this;
}

template<class T>
void Matrix<T>::Print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << arr[i][j] << '\t';
		cout << endl << endl;
	}
}
template<class T>
void Matrix<T>::Random()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			arr[i][j] = rand() % 50 * 1.6;
}


template <class T>
ostream& operator<<(ostream& os, const Matrix<T>& obj)
{
	for (int i = 0; i < obj.row; i++)
	{
		for (int j = 0; j < obj.column; j++)
			os << obj.arr[i][j] << '\t';
		os << endl << endl;
	}
	return os;
}



/*Пергрезка функций*/
template <class T>
Matrix<T> operator+(int k, const Matrix<T>& obj)
{
	return  Matrix<T>(obj + k);
}

template <class T>
Matrix<T> operator-(int k, const Matrix<T>& obj)
{
	return  Matrix<T>((-obj) + k);
}

template <class T>
Matrix<T> operator*(int k, const Matrix<T>& obj)
{
	return  Matrix<T>(obj * k);
}