#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() {
    top = NULL;
}

bool Stack::isEmpty() {
    return top == NULL;
}
bool Stack::isFull() {
    Node* ptr = new Node();
    if (ptr == NULL) {
        return true;
    }else {
        delete ptr;
        return false;
    }
}
void Stack::push(int item) {
    Node* newNode = new Node();
    newNode->data = item;

    if (isEmpty()) {
        newNode->next = NULL;
    }else {
        newNode->next = top;
    }

    top = newNode;
}

void Stack::Display() {
    Node* temp = top;

    while (temp != NULL) {
        cout << temp->data << '\t';
        temp = temp->next;
    }

    cout << '\n';
}

int Stack::pop() {
    Node* delptr = top;
    top = top->next;

    int valueToReturn = delptr->data;
    delete delptr;

    return valueToReturn;
}

int Stack::peek() {
    return top->data;
}

int Stack::count() {
    int counter = 0;
    Node* temp = top;

    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }

    return counter;
}

bool Stack::isFound(int item) {
    bool found = false;

    Node* temp = top;
    while (temp != NULL) {
        if (temp->data == item) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    return found;
}
