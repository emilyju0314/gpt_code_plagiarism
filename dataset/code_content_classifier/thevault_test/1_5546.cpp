inline double spqr_private_larfg (Long n, double *X, cholmod_common *cc)
{
    double tau = 0 ;
    BLAS_INT N = n, one = 1 ;
    if (CHECK_BLAS_INT && !EQ (N,n))
    {
        cc->blas_ok = FALSE ;
    }
    if (!CHECK_BLAS_INT || cc->blas_ok)
    {
        LAPACK_DLARFG (&N, X, X + 1, &one, &tau) ;
    }
    return (tau) ;
}