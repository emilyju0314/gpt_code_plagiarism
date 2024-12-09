bool testHeightBalanced(nodePtr rootp, int &height)
{
    if (!rootp)
    {
        //Base case.  If the node doesn't exist, set height to -1 and return true because a subtree
        //that has does not exist is by definition height balanced.  Also catches instances like the
        //root of the entire tree being NULL.
        height = -1;
        return true;
    }
    else
    {
        //The node exists.  Need to evaluate the height of its subtrees.

        int leftHeight = 0, rightHeight = 0;
        //Use recursion to determine the height of this node's subtrees and store that height in
        //leftHeight and rightHeight respectively.
        if (!testHeightBalanced(rootp->left, leftHeight) ||
            !testHeightBalanced(rootp->right, rightHeight))
            //If either of these functions return false, then the subtree is not height balanced,
            //so continue to relay that message up the chain of recursion.
            return false;
        //Check to see if the heights of the subtrees differ by more than 1.
        else if (abs(leftHeight - rightHeight) > 1)
            //If the height of the subtrees differ by more than one, the subtrees are not height
            //balanced.  Return 'false' to send that message up the chain of recursion.
            return false;
        //Assembles the height of the subtrees to be returned via height.
        else
        {
            //Set height to 1 plus the greater of leftHeight or rightHeight and return 'true'
            //so the recursion continues as required.
            height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
            return true;
        }
    }
}