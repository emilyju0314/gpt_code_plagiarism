void MyArray::resize(int theSize)
{
    if (theSize >= 0) // check that the new size is valid
    {
        if (size > 0) // if the array is not empty, deallocate first
            empty();
        if (theSize != 0) // allocate again if the size is not 0
        {
            size = theSize;
            array = new int[size];
        }
    }
    else // negative size, give an error message
        cout << "Resize attepmted with a negative size. "
             << "Operation ignored." << endl;
}