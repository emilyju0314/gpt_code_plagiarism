bool isHeightBalanced (nodePtr rootp)
{
    //This function is converted into a driver function for testHeightBalanced.

    //In this case, height is basically just a dummy variable not used for anything except to give
    //the testHeightBalanced function something to use to keep track of the height of the table.
    int height = 0;
    return testHeightBalanced(rootp, height);
}