int MyArray::hamming(MyArray &data) const
{
    //Declare a variable to hold the Hamming distance counter and set it to 0.
    int hammingDistance = 0;

    //Declare variables to hold object-independent sizes.
    int smallerArraySize = (size < data.size ? size : data.size);
    int largerArraySize = (size > data.size ? size : data.size);

    //Cycle through the arrays and increment the Hamming distance counter when appropriate.
    for (int i = 0; i < smallerArraySize; ++i)
        if (array[i] != data.array[i])
            ++hammingDistance;

    //Return the Hamming distance counter plus the difference in array sizes.
    return hammingDistance + largerArraySize - smallerArraySize;
}