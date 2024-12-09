#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node(int v) : value(v), left(NULL), right(NULL) {}
};

void insert(Node* root, int value) {
    Node* current = root;
    while (true) {
        if (value > current->value) {
            if (current->right == NULL) {
                current->right = new Node(value);
                break;
            }
            current = current->right;
        } else {
            if (current->left == NULL) {
                current->left = new Node(value);
                break;
            }
            current = current->left;
        }
    }
}

void printParents(Node* root, vector<int>& results) {
    Node* current = root;
    for (int i = 1; i < results.size(); i++) {
        Node* target = root;
        while (true) {
            if (results[i] > target->value) {
                if (target->right->value == results[i]) {
                    cout << target->value << " ";
                    break;
                }
                target = target->right;
            } else {
                if (target->left->value == results[i]) {
                    cout << target->value << " ";
                    break;
                }
                target = target->left;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = new Node(arr[0]);
    for (int i = 1; i < n; i++) {
        insert(root, arr[i]);
    }

    vector<int> results = arr;
    printParents(root, results);

    return 0;
}