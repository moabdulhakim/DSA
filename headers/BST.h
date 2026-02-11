#include<iostream>
#include "bstNode.h"
using namespace std;


#ifndef BST_H
#define BST_H



class BST {
public:
    bstNode* root;
    BST() {
        root = NULL;
    }

    bstNode *insert(bstNode *r, int item) {
        if (r == NULL) {
            bstNode *newNode = new bstNode(item);
            r = newNode;
        }
        else if (item < r->data) {
            r->left = insert(r->left, item);
        }else {
            r->right = insert(r->right, item);
        }

        return r;
    }

    void insert(int item) {
        root = insert(root, item);
    }

    void Preorder (bstNode* r) { // root -> left -> right;
        if (r == NULL) return;

        cout << r->data << '\t';
        Preorder(r->left);
        Preorder(r->right);
    }

    void Inorder (bstNode* r) { // left -> root -> right;
        if (r == NULL) return;

        Inorder(r->left);
        cout << r->data << '\t';
        Inorder(r->right);
    }

    void Postorder (bstNode* r) { // left -> right -> root;
        if (r == NULL) return;

        Postorder(r->left);
        Postorder(r->right);
        cout << r->data << '\t';
    }

    bstNode *Search(bstNode *r, int key) {
        if (r == NULL) return NULL;

        if (r->data == key) return r;

        return Search(((r->data < key)? r->right:r->left) , key);
    }

    bstNode *FindMin(bstNode *r) {
        if (r == NULL) return NULL;
        if (r->left == NULL) {
            return r;
        }

        return FindMin(r->left);
    }
    bstNode* FindMax(bstNode *r) {
        if (r == NULL) return NULL;
        if (r->right == NULL) {
            return r;
        }

        return FindMax(r->right);
    }

    bstNode *Delete(bstNode *r,int key) {
        if (r->data < key) {
            r->right = Delete(r->right, key);
        }else if (r->data > key) {
            r->left = Delete(r->left, key);
        }
        else {
            if (r->left == NULL && r->right == NULL) {
                r = NULL;
            }else if (r->right != NULL && r->left == NULL) {
                r->data = r->right->data;
                delete r->right;
                r->right = NULL;
            }else if (r->right == NULL && r->left != NULL) {
                r->data = r->left->data;
                delete r->left;
                r->left = NULL;
            }
            else {
                bstNode* max = FindMax(r->left);
                r->data = max->data;
                r->left = Delete(r->left, max->data);
            }
        }

        return r;
    }

    bstNode *getParent(bstNode *r, int key) {
        if (r == NULL || !(r->right || r->left)) return NULL;

        if (r == root && r->data == key) return NULL;
        if (r->right) {
            if (r->right->data == key) return r;
        }
        if (r->left) {
            if (r->left->data == key) return r;
        }

        return getParent(((r->data < key)? r->right:r->left) , key);
    }
};




#endif //BST_H
