int ListNode::getDatum()
{
    if (this) // check if we even have a target object
        return datum;
    else        
    {
        cerr << "Accessing a NULL pointer. Terminating program now." << endl;
        exit(1);
    }
}