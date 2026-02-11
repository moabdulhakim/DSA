#include <iostream>
using namespace std;

class Sort {
public:
	template<typename T>
	static void insertionRecursive(T* start, T* end) {
		if (start != end) {
			insertionSort(start, end - 1);
		}
		else return;

		T* current = end;
		T* head = end - 1;
		while (*head > *current) {
			swap(*head, *current);

			current--;
			head--;
		}
	}

	template<typename T>
	static void insertion(T* start, T* end) {
		if (start == nullptr || start >= end) return;

		T* head = start + 1;
		while (head < end) {
			T* preHead = head;
			T currentVal = *head;

			T* virtualHead = head - 1;
			while (currentVal < *virtualHead) {
				*head = *virtualHead;

				head--;
				virtualHead--;
			}

			*head = currentVal;
			head = preHead + 1;
		}
	}

	template<typename T>
	static void insertionAI(T* start, T* end) {
		if (start == nullptr || start >= end) return;

		for (T* head = start + 1; head <= end; ++head) {
			T currentVal = *head;
			T* j = head;

			while (j > start && currentVal < *(j - 1)) {
				*j = *(j - 1);
				j--;
			}
			*j = currentVal;
		}
	}
};