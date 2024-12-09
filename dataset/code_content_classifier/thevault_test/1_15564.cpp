void MyArray::empty()
{
    // make sure we have an array to delete
    if (size != 0 && array != NULL) 
    {
        size = 0;
        delete [] array;
        array = NULL; // make the pointer NULL after deallocating 
    }
}