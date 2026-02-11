#include "Array.h"
#include<iostream>
using namespace std;

Array::Array(const int arrSize) {
    items = new int[arrSize];
    size = arrSize;
    length = 0;
}

void Array::Array::Fill() {
    int noOfItems;
    cout << "Enter the number of items you want to fill: \n";
    cin >> noOfItems;

    if (noOfItems > size) {
        cout << "You can't exceed the size of the array.\n";
        return;
    }
    for (int i = 0; i < noOfItems; i++) {
        cout << "Enter the number of index " << i << '\n';
        cin >> items[i];
        length++;
    }
}

void Array::Display() const {
    cout << "Array Items: \n";
    for (int i = 0; i < length; i++) {
        cout << items[i] << '\t';
    }
    cout << '\n';
}

int Array::getLength() const {
    return length;
}

int Array::getSize() const {
    return size;
}

int Array::Search(int key) {
    int index = -1;

    for (int i = 0; i < length; i++) {
        if (items[i] == key) {
            index = i;
            break;
        }
    }

    return index;
}

void Array::Append(int newItem) {
    if (length == size) {
        cout << "The array is already full.\n";
        return;
    }

    items[length] = newItem;
    length++;
}

void Array::Insert(int index, int newItem) {
    if (index > size || index < 0) {
        cout << "Error, Index out of range\n";
        return;
    }
    if (length == size) {
        cout << "Array is full\n";
        return;
    }

    for (int i = length; i > index; i--) {
        items[i] = items[i - 1];
    }
    items[index] = newItem;
    length++;
}

void Array::Delete(int index) {
    if (index >= length || index < 0) {
        cout << "Error, Index out of range.\n";
        return;
    }
    for (int i = index; i < length - 1; i++) {
        items[i] = items[i + 1];
    }

    length--;
}

void Array::Enlrage(int newSize) {
    if (newSize <= size) {
        cout << "New Size must be at least (oldSize + 1).\n";
        return;
    }
    size = newSize;
    int *old = items;
    items = new int[newSize];

    for (int i = 0; i < length; i++) {
        items[i] = old[i];
    }
    delete [] old; // Important to clean heap.
}

void Array::Merge(Array other) {
    size += other.getSize();

    int *old = items;
    items = new int[size];

    int i;
    for (i = 0; i < length; i++) {
        items[i] = old[i];
    }

    for (int j = 0; j < other.getLength(); j++) {
        items[i++] = other.items[j];
        length++;
    }

    delete [] old;
}


// =========================================== Main Code ========================================================
/*
    cout << "Hello, This is Array ADT demo.\n";

    cout << "What is the size of your array? \n"; int arrSize; cin >> arrSize;
    Array items(arrSize);

    // ============================= Fill =================================
    items.Fill();
    items.Display();
    cout << "Size: " << items.getSize() << '\t' << "Length: " << items.getLength() << '\n';

    // ============================= Search =================================
    cout << "Enter the value you want to search for: \n"; int key; cin >> key;
    if (const int index = items.Search(key); index == -1) cout << "This item does not exist in the array.\n";
    else cout << "item found at position " << index << '\n';

    // ============================= Append =================================
    cout << "Enter the item you want to append: \n"; int newItem; cin >> newItem;
    items.Append(newItem);

    items.Display();

    // ============================= Insert =================================
    cout << "Enter the index of the item you want to insert: \n"; int indexOfInsertion; cin >> indexOfInsertion;
    cout << "Enter the item you want to insert: \n"; int itemToInsert; cin >> itemToInsert;
    items.Insert(indexOfInsertion, itemToInsert);

    items.Display();

    // ============================= Delete =================================
    cout << "Enter the index of the item you want to delete: \n"; int indexToDelete; cin >> indexToDelete;
    items.Delete(indexToDelete);

    items.Display();

    // ============================= Enlarge =================================
    cout << "Do you want to enlarge the array? Enter the new size : \n"; int newSize; cin >> newSize;
    items.Enlrage(newSize);
    cout << "Size: " << items.getSize() << '\t' << "Length: " << items.getLength() << '\n';


    // ============================= Write another array to merge =================================
    Array secondArray(5);
    cout << "Fill another array of size 5 to merge with the first array.\n";
    secondArray.Fill();

    items.Merge(secondArray);
    cout << "First array after merging: \n";
    items.Display();
    cout << "Size: " << items.getSize() << '\t' << "Length: " << items.getLength() << '\n';

*/