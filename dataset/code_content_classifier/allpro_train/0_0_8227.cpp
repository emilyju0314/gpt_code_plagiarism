#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
};

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
    if (preStart >= preorder.size() || inStart > inEnd) return nullptr;

    Node* root = new Node();
    root->id = preorder[preStart];

    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->id) {
            inIndex = i;
            break;
        }
    }

    root->left = buildTree(preorder, inorder, preStart + 1, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, preStart + (inIndex - inStart) + 1, inIndex + 1, inEnd);

    return root;
}

void postorderTraversal(Node* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->id << " ";
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n);
    vector<int> inorder(n);

    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    Node* root = buildTree(preorder, inorder, 0, 0, n - 1);

    postorderTraversal(root);

    return 0;
}