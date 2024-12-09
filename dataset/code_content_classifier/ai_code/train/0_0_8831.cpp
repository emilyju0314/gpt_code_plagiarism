#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

Node* insert(Node* T, Node* z) {
    Node* y = nullptr;
    Node* x = T;
    while (x != nullptr) {
        y = x; 
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) {
        T = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    return T;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int m;
    cin >> m;
    
    Node* T = nullptr;
    
    for (int i = 0; i < m; i++) {
        string operation;
        cin >> operation;
        if (operation == "insert") {
            int k;
            cin >> k;
            Node* newNode = new Node();
            newNode->key = k;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->parent = nullptr;
            T = insert(T, newNode);
        } else if (operation == "print") {
            inorder(T);
            cout << endl;
            preorder(T);
            cout << endl;
        }
    }
    
    return 0;
}