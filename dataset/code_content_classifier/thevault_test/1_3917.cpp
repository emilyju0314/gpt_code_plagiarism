void invertBinaryTree(Node* root)
{
    // base case: if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // swap left subtree with right subtree
    swap(root->left, root->right);
 
    // invert left subtree
    invertBinaryTree(root->left);
 
    // invert right subtree
    invertBinaryTree(root->right);
}