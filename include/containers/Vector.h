#include "./Array.h"

template<typename T>
class Vector: public Array<T> {
public:
	using Array<T>::data;
	using Array<T>::size;
	using Array<T>::capacity;

	Vector(int s = 0) : Array<T>(s) {}
	Vector(int s, T val) : Array<T>(s, val) {}
	Vector(initializer_list<T> list) : Array<T>(list) {}

	T pop(int idx) {
		if (size <= idx || idx < 0) {
			throw out_of_range("out of range");
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
};

