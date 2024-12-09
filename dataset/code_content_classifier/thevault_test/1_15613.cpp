int sumOfLeafData (nodePtr rootp)
{
    if (!rootp)
        //Base case.  If the node doesn't exist, return 0.
        return 0;
    else if (!rootp->left && !rootp->right)
        //If the node is a leaf, return its datum.  Don't need to recurse further because of the
        //fact that the node IS a leaf.
        return rootp->datum;
    else
        //This node has at least one child, so continue to recurse.
        return   sumOfLeafData(rootp->left)
               + sumOfLeafData(rootp->right);
}