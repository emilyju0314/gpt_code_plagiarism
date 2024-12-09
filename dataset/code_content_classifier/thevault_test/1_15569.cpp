bool MyArray::operator==(MyArray &data) const
{
    //Declare a flag to keep track of whether the arrays match.  Assume that they do.
    bool arraysMatch = true;
    
    //Check to make sure the sizes match.  If they do not, set the arraysMatch flag to false.  This
    //will prevent the following for loop from triggering.
    if (size != data.size)
        arraysMatch = false;

    //Cycle through the elements of the arrays and test if they match.  If they do not, set the
    //arraysMatch flag to false, which will exit the for loop.
    for (int i = 0; i < size && arraysMatch; ++i)
        if (array[i] != data.array[i])
            arraysMatch = false;

    //Return the arraysMatch flag
    return arraysMatch;
}