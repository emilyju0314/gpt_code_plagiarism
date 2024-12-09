MyArray::MyArray(MyArray &data)
    : size(data.size) // initialize the size
{
    // allocate the array
    array = new int[size];

    // copy all the values from data
    for (int i=0; i<size; i++)
        array[i] = data.array[i];
}