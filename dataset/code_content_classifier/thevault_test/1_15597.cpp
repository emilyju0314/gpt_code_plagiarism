int Stack::pop()
{
    int result = top();
    removeFront();
    return result;
}