#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include<stdexcept>
#include<initializer_list>

using namespace std;

template<typename T>
class Array {
protected:
	T* data;
	int size = 0;
	int capacity = 0;

	void expand() {
		capacity *= 2;
		T* newData = new T[capacity];
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}

public:
	Array(int size = 0) {
		if (size > 0) this->size = size;
		capacity = size + 10;

		data = new T[capacity];
	}

	Array(int size, T initialValue) : Array(size) {
		for (int i = 0; i < size; i++) data[i] = initialValue;
	}

	Array(T* arrPtr, int size) : Array(size) {
		for (int i = 0; i < size; i++) data[i] = arrPtr[i];
	}

	Array(initializer_list<T> list) : Array(list.size()) {
		auto it = list.begin();

		int i = 0;
		while (it != list.end()) {
			data[i] = *it;

			i++;
			it++;
		}
	}

	friend ostream& operator<< <T> (ostream& out, const Array<T>& v);

	~Array() {
		delete[] data;
		data = nullptr;
	}
};


template<typename T>
ostream& operator<< (ostream& out, const Array<T>& v) {
	for (int i = 0; i < v.size; i++) {
		out << v.data[i] << '\t';
	}

	return out;
}

#endif