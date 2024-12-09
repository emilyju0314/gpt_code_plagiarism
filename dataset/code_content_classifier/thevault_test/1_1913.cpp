void sobolCPU(int n_vectors, int n_dimensions, unsigned int *directions, float *output)
{
    unsigned int *v = directions;

    for (int d = 0 ; d < n_dimensions ; d++)
    {
        unsigned int X = 0;
        // x[0] is zero (in all dimensions)
        output[n_vectors * d] = 0.0;        
        for (int i = 1 ; i < n_vectors ; i++)
        {
            // x[i] = x[i-1] ^ v[c]
            //  where c is the index of the rightmost zero bit in i
            //  minus 1 (since C arrays count from zero)
            // In the Bratley and Fox paper this is equation (**)
            X ^= v[ffs(~(i - 1)) - 1];
            output[i + n_vectors * d] = (float)X * k_2powneg32;
        }
        v += n_directions;
    }
}