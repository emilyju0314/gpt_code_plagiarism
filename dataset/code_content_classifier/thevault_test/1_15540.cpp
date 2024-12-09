int List::countNegative()
{
    ListIterator currentNode = head;
    int numNegatives = 0;

    //Iterate through the list until the end (NULL) is reached.
    while (currentNode)
    {
        //Compare the value in the current node and see if it is less than 0.
        if (*currentNode < 0)
            //If it is, increment the counter.
            ++numNegatives;

        //Advance to the next node in the list.
        ++currentNode;
    }

    return numNegatives;
}