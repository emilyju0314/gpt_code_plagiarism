#include <iostream>
#include <string>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    
    Node* insertHelper(Node* root, int k) {
        if (root == nullptr) {
            return new Node(k);
        }
        
        if (k < root->key) {
            root->left = insertHelper(root->left, k);
        } else {
            root->right = insertHelper(root->right, k);
        }
        
        return root;
    }
    
    bool findHelper(Node* root, int k) {
        if (root == nullptr) {
            return false;
        }
        
        if (root->key == k) {
            return true;
        } else if (k < root->key) {
            return findHelper(root->left, k);
        } else {
            return findHelper(root->right, k);
        }
    }
    
    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
    
    Node* deleteHelper(Node* root, int k) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (k < root->key) {
            root->left = deleteHelper(root->left, k);
        } else if (k > root->key) {
            root->right = deleteHelper(root->right, k);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteHelper(root->right, temp->key);
        }
        
        return root;
    }
    
    void inorderHelper(Node* root) {
        if (root != nullptr) {
            inorderHelper(root->left);
            std::cout << " " << root->key;
            inorderHelper(root->right);
        }
    }
    
    void preorderHelper(Node* root) {
        if (root != nullptr) {
            std::cout << " " << root->key;
            preorderHelper(root->left);
            preorderHelper(root->right);
        }
    }
    
public:
    BinarySearchTree() : root(nullptr) {}
    
    void insert(int k) {
        root = insertHelper(root, k);
    }
    
    bool find(int k) {
        return findHelper(root, k);
    }
    
    void remove(int k) {
        root = deleteHelper(root, k);
    }
    
    void printInorder() {
        inorderHelper(root);
        std::cout << std::endl;
    }
    
    void printPreorder() {
        preorderHelper(root);
        std::cout << std::endl;
    }
};

int main() {
    int m;
    std::cin >> m;
    
    BinarySearchTree bst;
    
    for (int i = 0; i < m; ++i) {
        std::string operation;
        std::cin >> operation;
        
        if (operation == "insert") {
            int k;
            std::cin >> k;
            bst.insert(k);
        } else if (operation == "find") {
            int k;
            std::cin >> k;
            if (bst.find(k)) {
                std::cout << "yes" << std::endl;
            } else {
                std::cout << "no" << std::endl;
            }
        } else if (operation == "delete") {
            int k;
            std::cin >> k;
            bst.remove(k);
        } else if (operation == "print") {
            bst.printInorder();
            bst.printPreorder();
        }
    }
    
    return 0;
}