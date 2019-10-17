#pragma once

template <class T>
class shared_ptr
{
public:
	int* reference_count;
	T* object_pointer;

	shared_ptr()
	{
		reference_count = nullptr;
		this->object_pointer = nullptr;
	}

	explicit shared_ptr(T* object_ptr)
	{
		reference_count = new int();
		*(reference_count) = 1;

		this->object_pointer = object_ptr;
	}

	shared_ptr(const shared_ptr& another)
	{
		reference_count = another.reference_count;
		*reference_count = *reference_count + 1;

		this->object_pointer = another.object_pointer;
	}

	shared_ptr& operator=(const shared_ptr& another)
	{
		reference_count = another.reference_count;
		*reference_count = *reference_count + 1;

		this->object_pointer = another.object_pointer;
		return *this;
	}

	~shared_ptr()
	{
		*reference_count = *reference_count - 1;

		if (*reference_count == 0)
		{
			delete object_pointer;
			object_pointer = nullptr;
		}
	}
	T* operator->()
	{
		return this->object_pointer;
	}

	T& operator*()
	{
		return *(this->object_pointer);
	}

	int use_count()
	{
		return *(this->reference_count);
	}
};