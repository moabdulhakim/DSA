#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include<exception>
#include<initializer_list>
#include <algorithm>

template<typename T>
class Vector;

template<typename T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& v);

template<typename T>
class Vector {
protected:
	T* data = nullptr;
	int size = 0;
	int capacity = 0;

public:
	Vector(int size = 0) {
		if (size < 0) {
			throw std::out_of_range("Array size must be non-negative");
		}
		this->size = size;
		capacity = size + 10;

		data = new T[capacity];
	}

	Vector(int size, const T& initialValue) : Vector(size) {
		for (int i = 0; i < size; i++)
			data[i] = initialValue;
	}

	Vector(T* arrPtr, int size) : Vector(size) {
        std::copy(arrPtr, arrPtr + size, data);
	}

	Vector(std::initializer_list<T> list) : Vector(static_cast<int>(list.size())) {
		std::copy(list.begin(), list.end(), data);
	}

	// --------------------
	// Copy Constructor
	// --------------------

	Vector(const Vector& other)
		: size(other.size), capacity(other.capacity)
	{
		data = new T[capacity];
		std::copy(other.data, other.data + size, data);
	}

	// --------------------
	// Copy Assignment
	// --------------------

	Vector& operator=(const Vector& other)
	{
		if (this == &other)
			return *this;

		T* newData = new T[other.capacity];

		std::copy(other.data, other.data + other.size, newData);

		delete[] data;

		data = newData;
		size = other.size;
		capacity = other.capacity;

		return *this;
	}

	// --------------------
	// Move Constructor
	// --------------------

	Vector(Vector&& other) noexcept
		: data(other.data),
		  size(other.size),
		  capacity(other.capacity)
	{
		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;
	}

	// --------------------
	// Move Assignment
	// --------------------

	Vector& operator=(Vector&& other) noexcept
	{
		if (this == &other)
			return *this;

		delete[] data;

		data = other.data;
		size = other.size;
		capacity = other.capacity;

		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;

		return *this;
	}

	int getSize() const {
		return size;
	}

	int getCapacity() const {
		return capacity;
	}

	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}

	T& at(int index)
	{
		if (index < 0 || index >= size)
			throw std::out_of_range("Index out of range");
		return data[index];
	}

	const T& at(int index) const
	{
		if (index < 0 || index >= size)
			throw std::out_of_range("Index out of range");
		return data[index];
	}

	void expand() {
		capacity = capacity == 0? 1 : capacity * 2;
		T* newData = new T[capacity];
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}

	void push_back(const T& val) {
		if (size >= capacity) expand();
		data[size++] = val;
	}

	void pop_back() {
		erase((size - 1));
	}

	T erase(int idx) {
		if (size <= idx || idx < 0) {
			throw std::out_of_range("out of range");
		}

		T popped = data[idx];

		for (int i = idx; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;

		return popped;
	}

	int findTransposition(T value) {
		int position = -1;

		for (int i = 0; i < size; i++) {
			if (data[i] == value) {
				position = i;
				break;
			}
		}

		if (position > 0) {
			swap(data[position], data[position - 1]);
			position--;
		}

		return position;
	}

	void rightRotate(int times = 1) {
		times = times % size;
		if (size <= 1 || times == 0) return;

		for (int i = 0; i < times; i++) {
			T rotatedItem = data[size - 1];

			for (int j = size - 1; j > 0; j--) {
				data[j] = data[j - 1];
			}

			data[0] = rotatedItem;
		}
	}

	void leftRotate(int times = 1) {
		times = times % size;
		if (size <= 1 || times == 0) return;

		for (int i = 0; i < times; i++) {
			T rotatedItem = data[0];

			for (int j = 0; j <= size - 2; j++) {
				data[j] = data[j + 1];
			}

			data[size - 1] = rotatedItem;
		}
	}

	friend std::ostream& operator<< <T> (std::ostream& out, const Vector<T>& v);

	~Vector() {
		delete[] data;
	}
};


template<typename T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& v) {
	for (int i = 0; i < v.size; i++) {
		out << v.data[i] << '\t';
	}

	return out;
}

#endif