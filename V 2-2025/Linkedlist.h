#include <iostream>
#include "Node.h"
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H



class Linkedlist {
public:
    Node* head;
    Linkedlist();
    bool isEmpty() const;

    void insertFirst (int nodeData);

    void Display();
    int count();
    bool isFound(int item);

    void insertBefore(int item,int newData);

    void append(int nodeData);

    void Delete(int item);

};




#endif //LINKEDLIST_H
