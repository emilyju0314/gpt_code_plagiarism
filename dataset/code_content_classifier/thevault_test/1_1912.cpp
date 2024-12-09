void initSobolDirectionVectors(int n_dimensions, unsigned int *directions)
{
    unsigned int *v = directions;

    for (int dim = 0 ; dim < n_dimensions ; dim++)
    {
        // First dimension is a special case
        if (dim == 0)
        {
            for (int i = 0 ; i < n_directions ; i++)
            {
                // All m's are 1
                v[i] = 1 << (31 - i);
            }
        }
        else
        {
            int d = sobol_primitives[dim].degree;
            // The first direction numbers (up to the degree of the polynomial)
            // are simply v[i] = m[i] / 2^i (stored in Q0.32 format)
            for (int i = 0 ; i < d ; i++)
            {
                v[i] = sobol_primitives[dim].m[i] << (31 - i);
            }
            // The remaining direction numbers are computed as described in
            // the Bratley and Fox paper.
            // v[i] = a[1]v[i-1] ^ a[2]v[i-2] ^ ... ^ a[v-1]v[i-d+1] ^ v[i-d] ^ v[i-d]/2^d
            for (int i = d ; i < n_directions ; i++)
            {
                // First do the v[i-d] ^ v[i-d]/2^d part
                v[i] = v[i - d] ^ (v[i - d] >> d);
                // Now do the a[1]v[i-1] ^ a[2]v[i-2] ^ ... part
                // Note that the coefficients a[] are zero or one and for compactness in
                // the input tables they are stored as bits of a single integer. To extract
                // the relevant bit we use right shift and mask with 1.
                // For example, for a 10 degree polynomial there are ten useful bits in a,
                // so to get a[2] we need to right shift 7 times (to get the 8th bit into
                // the LSB) and then mask with 1.
                for (int j = 1 ; j < d ; j++)
                {
                    v[i] ^= (((sobol_primitives[dim].a >> (d - 1 - j)) & 1) * v[i - j]);
                }
            }
        }
        v += n_directions;
    }
}