void rprintPreorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    rprintPreorder(node->left);

    /* now recur on right subtree */
    rprintPreorder(node->right);
}