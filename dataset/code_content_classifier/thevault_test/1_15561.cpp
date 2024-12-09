MyArray::MyArray(int theSize)
{
    // initialize the object as empty
    array = NULL;
    size = 0;
    // then use the resize function to allocate the memory
    resize(theSize);
}