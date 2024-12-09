ListNode *ListNode::getNext()
{
    if (this) // check if we even have a target object
        return next;
    else        
    {
        cerr << "Accessing a NULL pointer. Terminating program now." << endl;
        exit(1);
    }
}