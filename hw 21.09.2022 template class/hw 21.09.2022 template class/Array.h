#pragma once
#include <ostream>

template<class T = int>
class MyArray
{
	T* arr; // array
	int size; // size of array
	int capacity; // dedicated amount of elements
	int grow; // grow value

	bool CorrectIndex(int index) const { return (index >= 0 && index < size); } // check index correctness

public:
	MyArray(); // default constructor
	MyArray(int s); // second constructor // size=s; capacity=size;
	MyArray(const MyArray<T>& obj); // copy constructor
	~MyArray(); // destructor
	MyArray<T>& operator=(const MyArray<T>& obj); // operator=
	T& operator[](int index); // operator[]


	/*METHODS*/
	int GetSize() const; // get size
	void SetSize(int size, int grow = 1); // set size
	int GetUpperBound() const; // get last admissible index
	bool IsEmpty() const; // is empty?
	bool FreeExtra(); // free memory after upper bound
	void RemoveAll(); // remove all
	T GetAt(int index) const;// get element by index 
	bool SetAt(const T& element, int index); // set element by index	
	void Add(const T& element); // add element to array
	void Append(const MyArray<T>& obj); // append another array to current
	const T* GetData(); // get array pointer
	bool InsertAt(const T& element, int index); // insert element in target position (index)
	bool RemoveAt(int index); // remove element from target position (index)

};

// default constructor
template<class T>
MyArray<T>::MyArray() : arr(nullptr), capacity(0), size(0), grow(1) {}

// second constructor
template<class T>
MyArray<T>::MyArray(int s) : MyArray<T>()
{
	arr = new T[s];
	capacity = size = s;
}

// copy constructor
template<class T>
MyArray<T>::MyArray(const MyArray<T>& obj)
{
	size = obj.size;
	capacity = obj.capacity;
	grow = obj.grow;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] == obj.arr[i];
	}
}

// destructor
template<class T>
MyArray<T>::~MyArray()
{
	if (arr != nullptr)
		delete[] arr;
}

// operator=
template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj)
{
	if (arr != nullptr)
		delete[]arr;

	size = obj.size;
	capacity = obj.capacity;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] == obj.arr[i];
	}
	return *this;
}

// operator[]
template<class T>
T& MyArray<T>::operator[](int index)
{
	if (CorrectIndex(index))
		return arr[index];
	else
		return arr[0];
}

/*METHODS*/

// get size
template<class T>
int MyArray<T>::GetSize() const
{
	return size;
}

// set size
template<class T>
void MyArray<T>::SetSize(int size, int grow)
{
	if (grow >= 1)
		this->grow = grow;
	else
		this->grow = 1;

	if (size != this->size && capacity != size + this->grow)
	{
		this->capacity = size + this->grow;
		T* temp = new T[capacity];
		for (int i = 0; i < size && i < this->size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		this->size = size;
	}
}

// get last admissible index
template<class T>
int MyArray<T>::GetUpperBound() const
{
	return (size - 1);
}

// is empty?
template<class T>
bool MyArray<T>::IsEmpty() const
{
	if (arr == nullptr)
		return true;
	else
		return false;
}

// free memory after upper bound
template<class T>
bool MyArray<T>::FreeExtra()
{
	if (size < capacity)
	{
		T* temp = new T[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		capacity = size;
		return true;
	}
	else
	{
		return false;
	}
}

// remove all
template<class T>
void MyArray<T>::RemoveAll()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
	grow = 1;
}

// get element by index 
template<class T>
T MyArray<T>::GetAt(int index) const
{
	if (CorrectIndex(index))
	{
		return arr[index];
	}
	else
	{
		return T(0);
	}
}

// set element by index
template<class T>
bool MyArray<T>::SetAt(const T& element, int index)
{
	if (CorrectIndex(index))
	{
		*this[index] = element;
		return true;
	}
	else
		return false;
}

// add element to array
template<class T>
void MyArray<T>::Add(const T& element)
{
	if (size == capacity)
	{
		capacity += grow;
		T* temp = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = element;
		delete[] arr;
		arr = temp;
	}
	else
	{
		arr[size] = element;
	}
	size++;
}

// append another array to current
template <class T>
void MyArray<T>::Append(const MyArray<T>& obj)
{
	if (obj.size <= (capacity - size))
	{
		for (int i = 0; i < obj.size; i++)
		{
			arr[i + size] = obj.arr[i];
		}
	}
	else
	{
		capacity = size + obj.size + grow;
		T* temp = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		for (int i = 0; i < obj.size; i++)
		{
			temp[i + size] = obj.arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	size += obj.size;
}

// get array pointer
template<class T>
const T* MyArray<T>::GetData()
{
	return arr;
}

// insert element in target position (index)
template<class T>
bool MyArray<T>::InsertAt(const T& element, int index)
{
	if (CorrectIndex(index) || index >= size)
	{
		if (size == capacity)
		{
			capacity += grow;
			T* temp = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
		for (int i = size; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		if (index > size)
		{
			index = size;
		}
		arr[index] = element;
		size++;
		return true;
	}
	return false;
}

// remove element from target position (index)
template<class T>
bool MyArray<T>::RemoveAt(int index)
{
	if (CorrectIndex(index))
	{
		if (capacity - size >= grow)
		{
			capacity = size + grow - 1;
			T* temp = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
		for (int i = index; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
		return true;
	}
	return false;
}


/*FUNC*/

// operator<< for MyArray<T>
template<class T>
std::ostream& operator<<(std::ostream& os, const MyArray<T>& obj)
{
	os << '(';
	for (int i = 0; i < obj.GetSize(); i++)
	{
		os << obj.GetAt(i) << ',' << ' ';
	}
	os << '\b' << '\b';
	os << ')';
	return os;
}