void growNewLeaves (nodePtr & rootp)
{
    if (!rootp)
    {
        //Base case.  If a node doesn't exist, create it.
        rootp = new node;

        //Test to make sure the memory was allocated.
        testDynamicAllocation(rootp);

        //Set the default values of the node.
        rootp->datum = 0;
        rootp->left = NULL;
        rootp->right = NULL;
    }
    else
    {
        //This node exists.  Continue to recurse through the tree.
        growNewLeaves(rootp->left);
        growNewLeaves(rootp->right);
    }

}