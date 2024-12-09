int Queue::dequeue()
{
    int result = front();
    removeFront();
    return result;
}