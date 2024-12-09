int sparse_merge
(
    cholmod_sparse *A,          // input/output
    cholmod_sparse *A_imag,     // input only
    cholmod_common *cc
)
{
    if (A == NULL || A_imag == NULL)
    {
        return (FALSE) ;
    }
    Long nz1 = cholmod_l_nnz (A, cc) ;
    Long nz2 = cholmod_l_nnz (A_imag, cc) ;
    if (A->xtype != CHOLMOD_REAL || A_imag->xtype != CHOLMOD_REAL || nz1 != nz2)
    {
        return (FALSE) ;
    }

    // change A from real to complex
    cholmod_l_sparse_xtype (CHOLMOD_COMPLEX, A, cc) ;

    double *Ax = (double *) A->x ;
    double *Az = (double *) A_imag->x ;

    // merge in the imaginary part from A_imag into A
    for (Long k = 0 ; k < nz1 ; k++)
    {
        Ax [2*k+1] = Az [k] ;
    }
    return (TRUE) ;
}