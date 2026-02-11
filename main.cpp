#include <iostream>
#include "headers/BST.h"
using namespace std;

int main() {
    BST bst;
    bool exit = false;

    bst.insert(45);
    bst.insert(15);
    bst.insert(79);
    bst.insert(90);
    bst.insert(10);
    bst.insert(55);
    bst.insert(12);
    bst.insert(20);
    bst.insert(50);

    while (!exit) {
        cout << "0. Exit" << '\n';
        cout << "1. Insert" << '\n';
        cout << "2. Display" << '\n';
        cout << "3. Search" << '\n';
        cout << "4. Find Max Item" << '\n';
        cout << "5. Find Min Item" << '\n';
        cout << "6. Delete" << '\n';
        cout << "===========================\n";

        int option; cin >> option;
        int item;

        cout << "\n------------------------------------------------------------------------------------------------------\n";
        switch (option) {
            case 0:
                exit = true;
                break;
            case 1:
                cout << "Enter item to insert in BST:\n"; cin >> item;
                bst.insert(item);
                break;
            case 2:
                cout << "\nPre Order:\n";
                bst.Preorder(bst.root);
                cout << '\n';

                cout << "\nIn Order:\n";
                bst.Inorder(bst.root);
                cout << '\n';

                cout << "\nPost Order:\n";
                bst.Postorder(bst.root);
                cout << '\n';
                break;
            case 3:
                cout << "Enter item you want to search for:\n"; cin >> item;
            if (bst.Search(bst.root, item)) {
                if (bst.Search(bst.root, item)->right) {
                    cout << "Right item is: " << bst.Search(bst.root, item)->right->data << '\n';
                }if (bst.Search(bst.root, item)->left) {
                    cout << "Left item is: " << bst.Search(bst.root, item)->left->data << '\n';
                }
            }else cout << item << " Not Found in this tree.\n";
                break;
            case 4:
                cout << "Max item in this tree is: " << bst.FindMax(bst.root)->data << '\n';
                break;
            case 5:
                cout << "Min item in this tree is: " << bst.FindMin(bst.root)->data << '\n';
                break;
            case 6:
                cout << "Enter item to delete: \n"; cin >> item;
                bst.Delete(bst.root,item);
                break;
        }

        cout << "------------------------------------------------------------------------------------------------------\n\n";
    }


    return 0;
}






/*
 void Delete(int key) {
        tNode *r = Search(root, key);
        if (r == NULL) return;

        // Cases
        bool leafToDel = !(r->right || r->left);
        bool hasLeafRightChild = ((r->right && !r->left) && !(r->right->right || r->right->left));
        bool hasLeafLeftChild = ((!r->right && r->left) && !(r->left->right || r->left->left));
        bool hasOneRightChild = (r->right && !r->left);
        bool hasOneLeftChild = (!r->right && r->left);
        bool hasTwoChild = (r->right && r->left);

        if (r == root) {
            delete r;
            r = NULL;
        }
        else if (leafToDel) {
            tNode *parent = getParent(root, key);
            if (parent->right != NULL && parent->right->data == key) {
                delete parent->right;
                parent->right = NULL;
            }else {
                delete parent->left;
                parent->left == NULL;
            }

        }else if (hasLeafRightChild) {
            r->data = r->right->data;
            delete r->right;
            r->right = NULL;
        }else if (hasLeafLeftChild) {
            r->data = r->left->data;
            delete r->left;
            r->right = NULL;
        }else if (hasOneRightChild) {
            tNode *min = FindMin(r->right);
            r->data = min->data;
            Delete(min->data);
        }else if (hasOneLeftChild) {
            tNode *max = FindMax(r->left);
            r->data = max->data;
            Delete(max->data);
        }else if (hasTwoChild) {
            tNode *min = FindMin(r->right);
            r->data = min->data;
            Delete(min->data);
        }
    }
 */