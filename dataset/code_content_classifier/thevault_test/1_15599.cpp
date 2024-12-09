int Stack::bottom()
{
    if (!isEmpty())
        return *end();
    else 
    {
        cout << "attempt to find the bottom of an empty stack" << endl;
        exit(1);
    }
}