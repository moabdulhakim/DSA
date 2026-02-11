#include "Node.h"

#ifndef QUEUE_H
#define QUEUE_H


class Queue {
    Node* front;
    Node* rear;

public:
    Queue();

    bool isEmpty();

    void Enqueue(int item);

    void Display();

    int Dequeue();

    int getFront();
    int getRear();

    int count();

    bool isFound(int item);

    void Clear();
};



#endif //QUEUE_H
