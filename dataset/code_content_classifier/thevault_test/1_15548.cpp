int Queue::front()
{ 
    if (!isEmpty()) 
        return *begin();
    else 
    {
        cerr << "Error: Attempt to access the front of an empty queue.\n";
        exit(1);
    }  
}