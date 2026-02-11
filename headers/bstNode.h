#include<iostream>
using namespace std;

#ifndef BSTNODE_H
#define BSTNODE_H


class bstNode{
public:
    int data;
    bstNode *left,*right;

    bstNode(int item) {
        data = item;
        left = right = NULL;
    }
};



#endif //BSTNODE_H
