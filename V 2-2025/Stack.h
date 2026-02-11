#include "Node.h"

#ifndef STACK_H
#define STACK_H



class Stack {
    Node* top;

public:
    Stack();

    bool isEmpty();

    bool isFull();

    void push(int item);

    void Display();

    int pop();

    int peek();

    int count();

    bool isFound(int item);
};


#endif //STACK_H
