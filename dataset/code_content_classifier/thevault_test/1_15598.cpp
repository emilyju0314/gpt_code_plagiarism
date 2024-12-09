int Stack::top()
{ 
    if (!isEmpty()) 
        return *begin();
    else 
    {
        cout << "attempt to access the top of an empty stack" << endl;
        exit(1);
    }  
}