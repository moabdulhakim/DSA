#include "./Array.h"

template<typename T>
class MinHeap: public Array<T> {
	using Array<T>::data;
	using Array<T>::capacity;

	using Array<T>::expand;

	void getLessThanImplicit(T value, int topPos, MinHeap& result) {
		if (data[topPos] >= value) {
			return;
		}

		result.push(data[topPos]);

		int firstChildPos = getFirstChildPos(topPos);
		int secondChildPos = getSecondChildPos(topPos);

		if (firstChildPos != -1) getLessThanImplicit(value, firstChildPos, result);
		if (secondChildPos != -1) getLessThanImplicit(value, secondChildPos, result);
	}

public:
	using Array<T>::size;

	MinHeap(int s = 0) : Array<T>(s) {}
	MinHeap(int s, T val) : Array<T>(s, val) {}
	MinHeap(T* arrPtr, int s) 
		: Array<T>(arrPtr, s)
	
	{
		heapify();
	}
	MinHeap(initializer_list<T> list) 
		: Array<T>(list) // O(n)
	{
		heapify(); // O(n) not O( nlog(n) )
	}

	static int getParentPos(int childPos) {
		return (childPos - 1) / 2;
	}

	int getFirstChildPos(int parentPos) {
		int pos = 2 * parentPos + 1;
		if (pos >= size) pos = -1;
		return pos;
	}
	int getSecondChildPos(int parentPos) {
		int pos = 2 * parentPos + 2;
		if (pos >= size) pos = -1;
		return pos;
	}

	void heapify_up(int childPos) {
		int parentPos = getParentPos(childPos);

		if (childPos == 0 || data[parentPos] <= data[childPos]) return;

		swap(data[parentPos], data[childPos]);
		heapify_up(parentPos);
	}

	void heapify_down(int parentPos) {
		int childPos = getFirstChildPos(parentPos);
		int secondChildPos = getSecondChildPos(parentPos);

		if (childPos == -1) return; // no children
		if (secondChildPos != -1 && data[secondChildPos] < data[childPos]) {
			childPos = secondChildPos;
		}

		if (data[parentPos] > data[childPos]) {
			swap(data[parentPos], data[childPos]);
			heapify_down(childPos);
		}
	}

	void heapify() {
		for (int i = size / 2 - 1; i >= 0; i--) {
			heapify_down(i);
		}
	}

	void push(T value) {
		if (size >= capacity) expand();
		data[size++] = value;
		heapify_up(size - 1);
	}

	void pop() {
		if(isEmpty()) {
			throw exception("heap is empty");
		}

		data[0] = data[--size];
		heapify_down(0);
	}

	bool isEmpty() {
		return size == 0;
	}

	int top() {
		if (isEmpty()) {
			throw exception("heap is empty");
		}

		return data[0];
	}

	MinHeap getLessThan(T value) {
		MinHeap<int> result;

		getLessThanImplicit(value, 0, result);

		return result;
	}

	template<typename T2>
	static bool isHeapArray(T2* arrPtr, int n) {
		for (int i = n-1; i > 0; i--) {
			if (arrPtr[i] < arrPtr[MinHeap<T2>::getParentPos(i)]) return false;
		}

		return true;
	}

	template<typename T2>
	static void heapSort(T2* arrPtr, int n) {
		if (n <= 1) return;

		MinHeap<T2> heap(arrPtr, n);

		for (int i = 0; i < n; i++) {
			arrPtr[i] = heap.top();
			heap.pop();
		}
	}

	void heapSortInPlace(T* arrPtr, int n) {		
		if (n <= 1) return;

		T* oldData = data;
		int oldSize = size;

		data = arrPtr;
		size = n;

		heapify();

		for (int i = 0; i < n; i++) {
			swap(arrPtr[0], arrPtr[n - 1 - i]);
			size--;
			heapify_down(0);
		}

		for(int i = 0; i < n / 2; i++) {
			swap(arrPtr[i], arrPtr[n - 1 - i]);
		}

		data = oldData;
		size = oldSize;
	}
};