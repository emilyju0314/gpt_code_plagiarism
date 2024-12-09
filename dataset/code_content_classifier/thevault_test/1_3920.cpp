void rprintInorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    rprintInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    rprintInorder(node->right);
}