#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    int key;
    int priority;
    Node* left;
    Node* right;
    
    Node(int key, int priority) : key(key), priority(priority), left(nullptr), right(nullptr) {}
};

Node* rightRotate(Node* t) {
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

Node* leftRotate(Node* t) {
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node* insert(Node* t, int key, int priority) {
    if (t == nullptr) {
        return new Node(key, priority);
    }
    
    if (key == t->key) {
        return t;
    }
    
    if (key < t->key) {
        t->left = insert(t->left, key, priority);
        if (t->priority < t->left->priority) {
            t = rightRotate(t);
        }
    } else {
        t->right = insert(t->right, key, priority);
        if (t->priority < t->right->priority) {
            t = leftRotate(t);
        }
    }
    
    return t;
}

Node* _delete(Node* t, int key) {
    if (t->left == nullptr && t->right == nullptr) {
        return nullptr;
    } else if (t->left == nullptr) {
        t = leftRotate(t);
    } else if (t->right == nullptr) {
        t = rightRotate(t);
    } else {
        if (t->left->priority > t->right->priority) {
            t = rightRotate(t);
        } else {
            t = leftRotate(t);
        }
    }
    
    return delete(t, key);
}

Node* delete(Node* t, int key) {
    if (t == nullptr) {
        return nullptr;
    }
    
    if (key < t->key) {
        t->left = delete(t->left, key);
    } else if (key > t->key) {
        t->right = delete(t->right, key);
    } else {
        return _delete(t, key);
    }
    
    return t;
}

bool find(Node* t, int key) {
    if (t == nullptr) {
        return false;
    }
    
    if (key == t->key) {
        return true;
    } else if (key < t->key) {
        return find(t->left, key);
    } else {
        return find(t->right, key);
    }
}

void inorder(Node* t) {
    if (t == nullptr) {
        return;
    }
    
    inorder(t->left);
    std::cout << " " << t->key;
    inorder(t->right);
}

void preorder(Node* t) {
    if (t == nullptr) {
        return;
    }
    
    std::cout << " " << t->key;
    preorder(t->left);
    preorder(t->right);
}

int main() {
    srand(time(nullptr));
    Node* Treap = nullptr;
    
    int m;
    std::cin >> m;
    
    while (m--) {
        std::string op;
        std::cin >> op;
        
        if (op == "insert") {
            int key, priority;
            std::cin >> key >> priority;
            Treap = insert(Treap, key, priority);
        } else if (op == "find") {
            int key;
            std::cin >> key;
            if (find(Treap, key)) {
                std::cout << "yes\n";
            } else {
                std::cout << "no\n";
            }
        } else if (op == "delete") {
            int key;
            std::cin >> key;
            Treap = delete(Treap, key);
        } else if (op == "print") {
            inorder(Treap);
            std::cout << std::endl;
            preorder(Treap);
            std::cout << std::endl;
        }
    }
    
    return 0;
}