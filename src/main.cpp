#include <iostream>
#include <string>
#include "../include/containers/MinHeap.h"
#include "../include/containers/Array.h"
#include "../include/containers/Vector.h"

using namespace std;

#define خل string
#define اطبع cout <<
#define ثم_اطبع <<
#define سطر_جديد '\n'

int main() {
	MinHeap<int> heap{10,9,8,7,6,5,4,3,2,1};
	
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };

	heap.heapSortInPlace(arr, 10);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

    return 0;
}
