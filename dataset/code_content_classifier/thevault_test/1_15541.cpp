bool List::removeFront()
{
    bool operationSuccessful = false;

    //Make sure the list is not empty.
    if (size)
    {
        //Store the current head of the list so it doesn't get lost.
        ListNode *temp = head;

        //Point the head of the list at the next node.
        head = head->next;

        //Delete the former head node of the list.
        delete temp;

        //Decrement the size.
        --size;

        //If the new size is 0, then we just deleted the last node in the list and need to update
        //tail to reflect that fact.
        if (!size)
            tail = NULL;

        //Operation was successful.
        operationSuccessful = true;
    }

    return operationSuccessful;
}