void ListNode::setNext(ListNode *link)
{
    if (this) // check if we even have a target object
        next = link;
    else        
    {
        cerr << "Accessing a NULL pointer. Terminating program now." << endl;
        exit(1);
    }
}