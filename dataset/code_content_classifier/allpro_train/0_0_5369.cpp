#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

bool find(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->key == key) {
        return true;
    } else if (root->key > key) {
        return find(root->left, key);
    } else {
        return find(root->right, key);
    }
}

void inorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderPrint(root->left);
    std::cout << " " << root->key;
    inorderPrint(root->right);
}

void preorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << " " << root->key;
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    int m;
    std::cin >> m;

    std::string op;
    int key;
    Node* root = nullptr;

    for (int i = 0; i < m; i++) {
        std::cin >> op;
        if (op == "insert") {
            std::cin >> key;
            root = insert(root, key);
        } else if (op == "find") {
            std::cin >> key;
            if (find(root, key)) {
                std::cout << "yes" << std::endl;
            } else {
                std::cout << "no" << std::endl;
            }
        } else if (op == "print") {
            inorderPrint(root);
            std::cout << std::endl;
            preorderPrint(root);
            std::cout << std::endl;
        }
    }

    return 0;
}