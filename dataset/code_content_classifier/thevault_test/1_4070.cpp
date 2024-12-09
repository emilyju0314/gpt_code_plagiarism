void addVectors(float* __restrict output, float* __restrict left, float* __restrict right, int numElements)
{
    for (int i = 0; i < numElements; i++)
    {
        output[i] = left[i] + right[i];
    }
}