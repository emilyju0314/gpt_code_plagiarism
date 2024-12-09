void deleteList(ListNode *head)
{
    ListNode *temp;
    while (head) // we still have nodes to delete
    {
        temp = head;       // store the current node
        head = head->next; // move the head to the next
        delete temp;       // now we can delete it
    }
}