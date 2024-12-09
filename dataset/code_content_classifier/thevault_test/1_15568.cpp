void MyArray::randomize(int limit, int theSize)
{
    //Use a static variable to keep track of whether rand() has already been seeded
    static bool randInit = false;
    if (!randInit)
    {
        //If rand() has not been seeded, do so using the current time.
        srand(time(NULL));
        randInit = true;
    }

    //If theSize is not 0, call the resize() method to resize the array.
    if (theSize)
        resize(theSize);

    //Cycle through the array and randomize the elements from 0 (inclusive) to limit (inclusive).
    for (int i = 0; i < size; ++i)
        array[i] = rand() % (limit + 1);
}