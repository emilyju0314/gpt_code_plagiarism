double *spqr_mx_merge_if_complex
(
    // inputs, not modified
    const mxArray *A,
    int make_complex,       // if TRUE, return value is Complex
    // output
    Long *p_nz,             // number of entries in A

    // workspace and parameters
    cholmod_common *cc
)
{
    Long nz, m, n ;
    double *X, *Xx, *Xz ;

    if (cc == NULL) return (NULL) ;

    m = mxGetM (A) ;
    n = mxGetN (A) ;
    Xx = mxGetPr (A) ;
    Xz = mxGetPi (A) ;

    if (mxIsSparse (A))
    {
        Long *Ap = (Long *) mxGetJc (A) ;
        nz = Ap [n] ;
    }
    else
    {
        nz = m*n ;
    }
    if (make_complex)
    {
        // Note the typecast and sizeof (...) intentionally do not match
        X = (double *) cholmod_l_malloc (nz, sizeof (Complex), cc) ;
        for (Long k = 0 ; k < nz ; k++)
        {
            X [2*k  ] = Xx [k] ;
            X [2*k+1] = Xz ? (Xz [k]) : 0 ;
        }
    }
    else
    {
        X = Xx ;
    }
    *p_nz = nz ;
    return (X) ;
}