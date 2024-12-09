inline void spqr_private_larf (Long m, Long n, double *V, double tau,
    double *C, Long ldc, double *W, cholmod_common *cc)
{
    BLAS_INT M = m, N = n, LDC = ldc, one = 1 ;
    char left = 'L' ;
    if (CHECK_BLAS_INT && !(EQ (M,m) && EQ (N,n) && EQ (LDC,ldc)))
    {
        cc->blas_ok = FALSE ;
        
    }
    if (!CHECK_BLAS_INT || cc->blas_ok)
    {
        LAPACK_DLARF (&left, &M, &N, V, &one, &tau, C, &LDC, W) ;
    }
}