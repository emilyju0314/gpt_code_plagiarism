int numberOfSiblingPairs (nodePtr rootp)
{
    if (!rootp)
        //Base case.  If the node doesn't exist, return 0.
        return 0;
    else
        //Adds one if both children exist, and zero if they don't, in addition to whatever the
        //furthing recursing adds.
        return   (rootp->left && rootp->right ? 1 : 0)
               + numberOfSiblingPairs(rootp->left)
               + numberOfSiblingPairs(rootp->right);
}