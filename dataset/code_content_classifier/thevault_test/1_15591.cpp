ListNode *ListNode::lastNode()
{
    ListNode *p = this;  // start from the current node
    while (p && p->next) // while we are not at the last node
        p = p->next;     // move forward
    return p;            // return the last node
}