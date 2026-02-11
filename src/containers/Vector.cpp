#include<initializer_list>

#include "../../include/containers/Vector.h"
using namespace std;

template<typename T>
Vector<T>::Vector(int size) {
	if (size > 0) size = size;
	capacity = size + 10;

	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(int size, T initialValue) : Vector(size) {
	for (int i = 0; i < size; i++) data[i] = initialValue;
}

template<typename T>
Vector<T>::Vector(initializer_list<T> list) : Vector(list.size()) {
	auto it = list.begin();

	int i = 0;
	while (it != list.end()) {
		data[i] = *it;

		i++;
		it++;
	}
}

template<typename T>
T Vector<T>::pop(int idx) {
	if (size <= idx) {
		throw exception("out of range");
	}

	T popped = data[idx];

	for (int i = idx; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;

	return popped;
}

template<typename T>
int Vector<T>::findTransposition(T value) {
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

template<typename T>
void Vector<T>::rightRotate(int times) {
	if (size <= 1) return;
	times = times % size;
	if (times == 0) return;

	for (int i = 0; i < times; i++) {
		T rotatedItem = data[size - 1];

		for (int j = size - 1; j > 0; j--) {
			data[j] = data[j - 1];
		}

		data[0] = rotatedItem;
	}
}

template<typename T>
void Vector<T>::leftRotate(int times) {
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

template<typename T>
ostream& operator<< (ostream& out, const Vector<T>& v) {
	for (int i = 0; i < v.size; i++) {
		out << v.data[i] << '\t';
	}

	return out;
}