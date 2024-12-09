void addVectorsSIMD(float* __restrict output, float* __restrict left, float* __restrict right, int numElements)
{
    register __m256 _out, _left, _right;

    for (int i = 0; i < numElements-8; i += 8)
    {
        _out   = _mm256_load_ps(&output[i]);
        _left  = _mm256_load_ps(&left[i]);
        _right = _mm256_load_ps(&right[i]);
        _out = _mm256_add_ps(_left, _right);
        _mm256_store_ps(&output[i], _out);
    }
}