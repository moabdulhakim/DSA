#include "./Vector.h"

template<typename T>
class MinHeap{
	Vector<T> arr;

	void getLessThanImplicit(T value, int topPos, MinHeap& result) {
		if (arr[topPos] >= value) {
			return;
		}

		result.push(arr[topPos]);

		const int firstChildPos = this->getFirstChildPos(topPos);
		const int secondChildPos = this->getSecondChildPos(topPos);

		if (firstChildPos != -1) getLessThanImplicit(value, firstChildPos, result);
		if (secondChildPos != -1) getLessThanImplicit(value, secondChildPos, result);
	}

public:
	explicit MinHeap(int s = 0) : arr(s) {}
	MinHeap(int s, T val) : arr(s, val) {}
	MinHeap(T* arrPtr, int s)
		: arr(arrPtr, s)
	{
		this->heapify();
	}
	MinHeap(std::initializer_list<T> list)
		: arr(list) // O(n)
	{
		this->heapify(); // O(n) not O( nlog(n) )
	}

	static int getParentPos(const int childPos) {
		return (childPos - 1) / 2;
	}

	int getFirstChildPos(const int parentPos) const {
		int pos = 2 * parentPos + 1;
		if (pos >= arr.getSize()) pos = -1;
		return pos;
	}
	int getSecondChildPos(const int parentPos) const {
		int pos = 2 * parentPos + 2;
		if (pos >= arr.getSize()) pos = -1;
		return pos;
	}

	void heapify_up(int childPos) {
		int parentPos = getParentPos(childPos);

		if (childPos == 0 || arr[parentPos] <= arr[childPos]) return;

		std::swap(arr[parentPos], arr[childPos]);
		heapify_up(parentPos);
	}

	void heapify_down(int parentPos) {
		int childPos = getFirstChildPos(parentPos);
		int secondChildPos = getSecondChildPos(parentPos);

		if (childPos == -1) return; // no children
		if (secondChildPos != -1 && arr[secondChildPos] < arr[childPos]) {
			childPos = secondChildPos;
		}

		if (arr[parentPos] > arr[childPos]) {
			std::swap(arr[parentPos], arr[childPos]);
			heapify_down(childPos);
		}
	}

	void heapify() {
		for (int i = arr.getSize() / 2 - 1; i >= 0; --i) {
			heapify_down(i);
		}
	}

	void push(T value) {
		arr.push_back(value);
		heapify_up(arr.getSize() - 1);
	}

	void pop() {
		if(isEmpty()) {
			throw std::runtime_error("heap is empty");
		}

		arr[0] = arr[--arr.getSize()];
		heapify_down(0);
	}

	bool isEmpty() const {
		return arr.getSize() == 0;
	}

	T top() const {
		if (isEmpty()) {
			throw std::runtime_error("heap is empty");
		}

		return arr[0];
	}

	MinHeap getLessThan(T value) {
		MinHeap<T> result;

		getLessThanImplicit(value, 0, result);

		return result;
	}

	template<typename T2>
	static bool isHeapArray(T2* arrPtr, const int n) {
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

	/*
	void heapSortInPlace(T* arrPtr, int n) {		
		if (n <= 1) return;

		T* oldData = arr.data;
		int oldSize = arr.size;

		arr.data = arrPtr;
		arr.size = n;

		heapify();

		for (int i = 0; i < n; i++) {
			swap(arrPtr[0], arrPtr[n - 1 - i]);
			--arr.size;
			heapify_down(0);
		}

		for(int i = 0; i < n / 2; i++) {
			swap(arrPtr[i], arrPtr[n - 1 - i]);
		}

		arr.data = oldData;
		size = oldSize;
	}
	*/
};