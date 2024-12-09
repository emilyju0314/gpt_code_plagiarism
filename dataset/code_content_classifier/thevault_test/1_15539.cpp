void List::insertAfter(ListIterator chosenNode, int number)
{
    //If the iterator is NULL, insert at the head of the list.
    if (!chosenNode)
        insertFront(number);
    
    //If the iterator is not null, insert where it points.
    else
    {
        //Allocate memory for a new List Node and check it for validity.
        ListNode *newNode = new ListNode(number);
        testAllocation(newNode);

        //Shuffle pointers around to insert the new node into the list.
        newNode->next = chosenNode.current->next;
        chosenNode.current->next = newNode;

        //Check if the new node is pointing to NULL and if it is, make it the new tail.
        if (!newNode->next)
            tail = newNode;
        
        //Increment size.
        ++size;
    }
}