void List::insertBack(int number)
{
    //Make things simple and call insertAfter using the tail as the base node.
    insertAfter(tail, number);
}