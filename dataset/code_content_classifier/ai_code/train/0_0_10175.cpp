#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int label;
    Node* left;
    Node* right;

    Node(int l) : label(l), left(nullptr), right(nullptr) {}
};

Node* buildTree(int n, vector<pair<int, int>> constraints) {
    if (constraints.empty()) {
        return nullptr;
    }

    vector<Node*> nodes;
    for (int i = 1; i <= n; ++i) {
        nodes.push_back(new Node(i));
    }

    for (const auto& constraint : constraints) {
        int parent = constraint.first;
        int child = constraint.second;
        string direction;
        cin >> direction;

        if (direction == "LEFT") {
            nodes[parent - 1]->left = nodes[child - 1];
        } else {
            nodes[parent - 1]->right = nodes[child - 1];
        }
    }

    return nodes[0]; // return the root of the binary tree
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->label << " ";
    inOrderTraversal(root->right);
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<pair<int, int>> constraints;
    for (int i = 0; i < c; ++i) {
        int a, b;
        cin >> a >> b;
        constraints.push_back({a, b});
    }

    Node* root = buildTree(n, constraints);

    if (root) {
        inOrderTraversal(root);
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}