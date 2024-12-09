ListIterator ListIterator::min()
{
    ListIterator smallestFound = *this, currentTarget = *this;
    //ListNode *smallestFound = current, *currentTarget = current;

    //Cycle through the list until the end (NULL) is found.
    while (currentTarget)
    {
        //Compare datums and if currentTarget is smaller, set smallestFound equal to it.
        if (*currentTarget < *smallestFound)
        //if (currentTarget->getDatum() < smallestFound->getDatum())
            smallestFound = currentTarget;

        //Move on to the next Node.
        ++currentTarget;
        //currentTarget = currentTarget->getNext();
    }

    //Return a ListIterator containing the address of the smallest found number in the list.
    return ListIterator(smallestFound);
}