void destroyABinaryTree(nodePtr &rootp)
{
    //Only attempt to delete the node and subtree if the node exists.
    if (rootp)
    {
        //Delete the tree from the bottom up.  This prevents memory leaks from deleting a low level
        //node and losing access to its subtree.
        destroyABinaryTree(rootp->left);
        destroyABinaryTree(rootp->right);

        //Once the recursive calls are done, actually delete the node referenced by rootp.
        delete rootp;
        //Set rootp to NULL, which, because it's a reference parameter, will set the left or right
        //data member to NULL as well.
        rootp = NULL;
    }
}