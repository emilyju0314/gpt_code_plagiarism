mxArray *spqr_mx_put_permutation
(
    Long *P,        // size n permutation vector
    Long n, 
    int vector,     // if TRUE, return a vector; otherwise return a matrix

    // workspace and parameters
    cholmod_common *cc
)
{
    mxArray *Pmatlab ;
    double *Ex ;
    Long *Ep, *Ei, j, k ;

    if (cc == NULL) return (NULL) ;

    if (vector)
    {
        // return P as a permutation vector
        Pmatlab = mxCreateDoubleMatrix (1, n, mxREAL) ;
        Ex = mxGetPr (Pmatlab) ;
        for (k = 0 ; k < n ; k++)
        {
            Ex [k] = (double) ((P ? P [k] : k) + 1) ;
        }
    }
    else
    {
        // return E as a permutation matrix
        Pmatlab = mxCreateSparse (n, n, MAX (n,1), mxREAL) ;
        Ep = (Long *) mxGetJc (Pmatlab) ;
        Ei = (Long *) mxGetIr (Pmatlab) ;
        Ex = mxGetPr (Pmatlab) ;
        for (k = 0 ; k < n ; k++)
        {
            j = P ? P [k] : k ;
            Ep [k] = k ;
            Ei [k] = j ;
            Ex [k] = 1 ;
        }
        Ep [n] = n ;
    }
    return (Pmatlab) ;
}