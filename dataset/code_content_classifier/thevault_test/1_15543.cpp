int List::positionAtNode(ListIterator target)
{
    ListIterator currentNode = head;
    int currentPosition = 0, foundPosition = -1;

    //Verify that the target is not NULL and the list is not empty because if either is then there
    //is no need to search.
    if (target && currentNode)
    {
        //Iterate through the list in search of the target.
        while (foundPosition == -1 && currentNode)
        {
            //Check to see if the current node is the target node.
            if (currentNode == target)
                foundPosition = currentPosition;

            //If it is not, move to the next node and increment the position counter.
            else
            {
                ++currentPosition;
                ++currentNode;
            }
        }
    }

    return foundPosition;
}