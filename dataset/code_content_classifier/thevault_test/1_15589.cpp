ListNode *ListNode::copy() 
{
    ListNode *p, *temp, *tail=NULL, *head = NULL;

    // start from this node
    p = this; 
    while (p) 
    {
        // create a new node containing the same datum as p
        temp = new ListNode(p->datum);

        // if it's not the first, add it to the back of the new list
        if (head) 
        { 
            tail->next = temp; 
            tail = temp;
        }
        else // otherwise make it both first and last
            head = tail = temp;

        p = p->next; // move to the next node to copy
    }
    return head;
}