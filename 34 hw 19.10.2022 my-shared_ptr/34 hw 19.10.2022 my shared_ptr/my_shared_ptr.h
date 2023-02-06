typedef unsigned int uint;

template<class T>
class my_shared_ptr
{
private:
	T* ptr = nullptr;
	uint* refCount = nullptr;

	void __cleanup__()
	{
		(*refCount)--;
		if (*refCount == 0)
		{
			if (nullptr != ptr)
				delete ptr;
			delete refCount;
		}
	}
public:
	// default constructor
	my_shared_ptr() : ptr(nullptr), refCount(new uint(0)) 
	{
	}

	// constructor by params
	my_shared_ptr(T* ptr) : ptr(ptr), refCount(new uint(1)) 
	{
	}

	/*** Copy Semantics ***/ // copy constructor
	my_shared_ptr(const my_shared_ptr& obj) 
	{
		this->ptr = obj.ptr; // share the underlying pointer
		this->refCount = obj.refCount;
		if (nullptr != obj.ptr)
		{
			(*this->refCount)++; // if the pointer is not null, increment the refCount
		}
	}

	// copy assignment
	my_shared_ptr& operator=(const my_shared_ptr& obj) 
	{
		__cleanup__(); // cleanup any existing data

		// Assign incoming object's data to this object
		this->ptr = obj.ptr; // share the underlying pointer
		this->refCount = obj.refCount;
		if (nullptr != obj.ptr)
		{
			(*this->refCount)++; // if the pointer is not null, increment the refCount
		}
	}

	/*** Move Semantics ***/ // move constructor
	my_shared_ptr(my_shared_ptr&& dyingObj) 
	{
		this->ptr = dyingObj.ptr; // share the underlying pointer
		this->refCount = dyingObj.refCount;

		dyingObj.ptr = dyingObj.refCount = nullptr; // clean the dying object
	}

	// move assignment
	my_shared_ptr& operator=(my_shared_ptr&& dyingObj) 
	{
		__cleanup__(); // cleanup any existing data

		this->ptr = dyingObj.ptr; // share the underlying pointer
		this->refCount = dyingObj.refCount;

		dyingObj.ptr = dyingObj.refCount = nullptr; // clean the dying object
	}

	uint get_count() const
	{
		return *refCount; // *this->refCount
	}

	T* get() const
	{
		return this->ptr;
	}

	T* operator->() const
	{
		return this->ptr;
	}

	T& operator*() const
	{
		return this->ptr;
	}

	// destructor
	~my_shared_ptr() 
	{
		__cleanup__();
	}
};