void randomize(int a[], unsigned int size, int lowerBound, int upperBound)
{
    if (!size)
        return;

    for (unsigned long i = 0; i < size; ++i)
        a[i] = rand() % (upperBound + lowerBound) - lowerBound;
}