bool List::operator==(const List &data)
{
    //Assume the lists are equal.
    bool listsAreEqual = true;

    //If the lists have unequal size, they are not equal, and we have no need to compare.
    if (size != data.size)
        listsAreEqual = false;

    //If both lists start at the same node, then they are equal, and we have no need to compare.
    else if (head == data.head);

    //The head nodes are not the same, but the sizes are equal.  Compare the datum of the lists.
    else
    {
        ListIterator currentNode1 = head, currentNode2 = data.head;

        //Iterate through the lists and check the datums.
        while (listsAreEqual && currentNode1)
        {
            //Compare the datums.
            if (*currentNode1 != *currentNode2)
                listsAreEqual = false;

            //Go to the next node.
            ++currentNode1;
            ++currentNode2;
        }
    }

    //Return the result of the function.
    return listsAreEqual;
}