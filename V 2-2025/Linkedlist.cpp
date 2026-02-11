//
// Created by Mohammad on 2/24/2025.
//

#include "Linkedlist.h"


Linkedlist::Linkedlist() {
        head = NULL;
    }
bool Linkedlist::isEmpty() const {
        return (head == NULL);
    }
void Linkedlist::insertFirst (int nodeData) {
        Node* newNode = new Node();
        newNode->data = nodeData;

        newNode->next = head;
        head = newNode;
    }
void Linkedlist::Display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << '\t';
            temp = temp->next;
        }

        cout << '\n';
    }
int Linkedlist::count() {
        int counter = 0;
        Node* temp = head;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }

        return counter;
    }
bool Linkedlist::isFound(int item) {
        int found = false;
        Node* temp = head;
        while (temp != NULL) {
            if (item == temp->data) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
void Linkedlist::insertBefore(int item,int newData) {
        if (isEmpty()) {
            insertFirst(item);
            return;
        }
        if (!isFound(item)) {
            cout << "This item does not exist.\n";
            return;
        }

        if (head->data == item) {
            insertFirst(newData);
            return;
        }

        Node* newNode = new Node();
        newNode->data = newData;

        Node* temp = head;
        while (temp->next->data != item && temp != NULL) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
void Linkedlist::append(int nodeData) {
        if (isEmpty()) {
            insertFirst(nodeData);
            return;
        }

        Node* newNode = new Node();
        newNode->data = nodeData;
        newNode->next = NULL;

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
void Linkedlist::Delete(int item) {
        Node* delptr = head;

        if (isEmpty()) cout << "The list is empty, no items to delete.\n";
        else if (head->data == item) {
            head = head->next;

            delete delptr;
        }else {
            Node* prev = NULL;

            while (delptr->data != item) {
                prev = delptr;
                delptr = delptr->next;
            }

            prev->next = delptr->next;
            delete delptr;
        }

    }