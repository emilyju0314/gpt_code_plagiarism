#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
    Node(int id) : id(id), left(nullptr), right(nullptr) {}
};

vector<int> preorder;
vector<int> inorder;
vector<int> postorder;

void preOrder(Node* root) {
    if(root == nullptr) return;
    preorder.push_back(root->id);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if(root == nullptr) return;
    inOrder(root->left);
    inorder.push_back(root->id);
    inOrder(root->right);
}

void postOrder(Node* root) {
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    postorder.push_back(root->id);
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes(n);
    for(int i = 0; i < n; i++) {
        int id, left, right;
        cin >> id >> left >> right;
        nodes[id] = new Node(id);
        if(left != -1) nodes[id]->left = nodes[left];
        if(right != -1) nodes[id]->right = nodes[right];
    }

    Node* root = nodes[0];

    preOrder(root);
    inOrder(root);
    postOrder(root);

    cout << "Preorder" << endl;
    for(int val : preorder) {
        cout << " " << val;
    }
    cout << endl;

    cout << "Inorder" << endl;
    for(int val : inorder) {
        cout << " " << val;
    }
    cout << endl;

    cout << "Postorder" << endl;
    for(int val : postorder) {
        cout << " " << val;
    }
    cout << endl;

    return 0;
}