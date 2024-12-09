void ListNode::setDatum(const int number)
{
    if (this) // check if we even have a target object
        datum = number;
    else        
    {
        cerr << "Accessing a NULL pointer. Terminating program now." << endl;
        exit(1);
    }
}