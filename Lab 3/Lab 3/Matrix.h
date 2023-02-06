#pragma once
#include <iostream>
using namespace std;

template <class T>
class Matrix
{
	T** arr;
	int row;
	int col;
public:
	Matrix();
	Matrix(int _row, int _col);
	Matrix(const Matrix<T>& obj);
	~Matrix();
	void Print();
	void Random();

	Matrix operator+(const T)const;
	Matrix operator-(const T)const;
	Matrix operator*(const T)const;
	Matrix operator/(const T)const;
	Matrix& operator=(const Matrix&);

	T GetMin();
	T GetMax();
};

template<class T>
Matrix<T>::Matrix()
{
	arr = nullptr;
	row = col = 0;
}

template<class T>
Matrix<T>::Matrix(int _row, int _col)
{
	row = _row;
	col = _col;
	arr = new T * [row];
	for (size_t i = 0; i < row; i++)
		arr[i] = new T[col];
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj)
{
	row = obj.row;
	col = obj.col;

	arr = new T * [row];
	for (size_t i = 0; i < row; i++)
		arr[i] = new T[col];

	// copy
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			arr[i][j] = obj.arr[i][j];
}

template<class T>
Matrix<T>::~Matrix()
{
	for (size_t i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
}

template<class T>
void Matrix<T>::Print()
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
			cout << arr[i][j] << '\t';
		cout << endl << endl;
	}
}

template<class T>
void Matrix<T>::Random()
{
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			arr[i][j] = rand() % 100 * 1.6;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const T param) const
{
	Matrix temp(*this); // начальное состояние	
	
	for (size_t i = 0; i < row; i++)			// прибавляем параметр
		for (size_t j = 0; j < col; j++)
			temp.arr[i][j] += param;
	
	return temp;		// возвращаем матрицу
}

template<class T>
Matrix<T> Matrix<T>::operator-(const T param) const
{
	Matrix temp(*this); // начальное состояние	

	for (size_t i = 0; i < row; i++)			// отнимаем параметр
		for (size_t j = 0; j < col; j++)
			temp.arr[i][j] -= param;

	return temp;		// возвращаем матрицу
}

template<class T>
Matrix<T> Matrix<T>::operator*(const T param) const
{
	Matrix temp(*this); // начальное состояние	

	for (size_t i = 0; i < row; i++)			// отнимаем параметр
		for (size_t j = 0; j < col; j++)
			temp.arr[i][j] *= param;

	return temp;		// возвращаем матрицу
}

template<class T>
Matrix<T> Matrix<T>::operator/(const T param) const
{
	Matrix temp(*this); // начальное состояние	

	for (size_t i = 0; i < row; i++)			// отнимаем параметр
		for (size_t j = 0; j < col; j++)
			temp.arr[i][j] /= param;

	return temp;		// возвращаем матрицу
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& obj)
{
	if (this == &obj) return *this;
	if (arr != nullptr) this->~Matrix();

	row = obj.row;
	col = obj.col;
	
	arr = new T * [row];
	for (size_t i = 0; i < row; i++)
		arr[i] = new T[col];

	for (size_t i = 0; i < row; i++)			// копируем
		for (size_t j = 0; j < col; j++)
			arr[i][j] = obj.arr[i][j];

	return *this;								// возвращаем матрицу
}

template<class T>
T Matrix<T>::GetMin()
{
	T min = arr[0][0];

	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			if (arr[i][j] < min) min = arr[i][j];

	return min;
}

template<class T>
T Matrix<T>::GetMax()
{
	T max = arr[0][0];

	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			if (arr[i][j] > max) max = arr[i][j];

	return max;
}