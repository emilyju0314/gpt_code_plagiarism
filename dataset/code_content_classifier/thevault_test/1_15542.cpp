ListIterator List::nodeAtPosition(int location)
{
    //Start at the head of the list.
    ListIterator currentNode = head;

    //Move forward however many nodes desired.
    currentNode.moveForward(location);

    return currentNode;
}