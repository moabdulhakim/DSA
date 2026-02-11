#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
    front = rear = NULL;
}

bool Queue::isEmpty() {
    return (front == NULL);
}

void Queue::Enqueue(int item) {
    Node* newNode = new Node();
    newNode->data = item;

    if (isEmpty()) {
        front = rear = newNode;
    }else {
        rear->next = newNode;
        rear = newNode;
    }
    newNode->next = NULL;
}

void Queue::Display() {
    if (isEmpty()) {
        cout << "No Items to display\n.";
        return;
    }
    Node* temp = front;

    while (temp != NULL) {
        cout << temp->data << '\t';
        temp = temp->next;
    }

    cout << '\n';
}

int Queue::Dequeue() {
    if (isEmpty()) {
        cout << "The queue is empty, No items to delete.\n";
        return -1;
    }

    Node* delptr = front;
    if (front == rear) {
        front = rear = NULL;
    }else {
        front = front->next;
    }

    int valueToReturn = delptr->data;
    delete delptr;

    return valueToReturn;
}

int Queue::getFront() {
    return front->data;
}
int Queue::getRear() {
    return rear->data;
}

int Queue::count() {
    int counter = 0;
    Node* temp = front;

    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }

    return counter;
}

bool Queue::isFound(int item) {
    bool found = false;

    Node* temp = front;
    while (temp != NULL) {
        if (temp->data == item) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    return found;
}

void Queue::Clear() {
    while (!isEmpty()) {
        Dequeue();
    }

    Display();
}