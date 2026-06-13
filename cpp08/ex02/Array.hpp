#pragma once

#include <stdexcept>

template <typename T>
class Array {
   public:
	Array() : len(0) {};
	Array(unsigned int n) : len(n) {
		if (n == 0)
			return;
		array = new T[n];
		for (unsigned int i = 0; i < n; i++)
			array[i] = 0;
	};
	Array(Array &other) : len(other.len) {
		array = new T[len];

		for (unsigned int i = 0; i < len; i++)
			array[i] = other[i];
	}
	Array &operator=(Array &other) {
		if (this == other)
			return (&other);
		len = other.len;
		for (unsigned int i; i < other.size(); i++)
			array[i] = other[i];

		return (*this);
	}
	~Array() {
		if (len != 0)
			delete [] array;
	}

	T &operator[](unsigned int n) const {
		if (n >= len)
			throw std::out_of_range("Index is out of bounds.");
		return array[n];
	}
	unsigned int size() const {
		return len;
	}

   private:
	unsigned int len;
	T *array;
};
