Long SuiteSparseQR_C             // returns rank(A) estimate, (-1) if failure
(
    // inputs:
    int ordering,           // all, except 3:given treated as 0:fixed
    double tol,             // columns with 2-norm <= tol are treated as 0
    Long econ,              // e = max(min(m,econ),rank(A))
    int getCTX,             // 0: Z=C (e-by-k), 1: Z=C', 2: Z=X (e-by-k)
    cholmod_sparse *A,      // m-by-n sparse matrix to factorize
    cholmod_sparse *Bsparse,// sparse m-by-k B
    cholmod_dense  *Bdense, // dense  m-by-k B
    // outputs:
    cholmod_sparse **Zsparse,   // sparse Z
    cholmod_dense  **Zdense,    // dense Z
    cholmod_sparse **R,     // R factor, e-by-n
    Long **E,               // size n column permutation, NULL if identity
    cholmod_sparse **H,     // m-by-nh Householder vectors
    Long **HPinv,           // size m row permutation
    cholmod_dense **HTau,   // 1-by-nh Householder coefficients
    cholmod_common *cc      // workspace and parameters
)
{
    RETURN_IF_NULL_COMMON (EMPTY) ;
    RETURN_IF_NULL (A, EMPTY) ;
    cc->status = CHOLMOD_OK ;

    return ((A->xtype == CHOLMOD_REAL) ?
        SuiteSparseQR <double>  (ordering, tol, econ, getCTX, A, Bsparse,
            Bdense, Zsparse, Zdense, R, E, H, HPinv, HTau, cc) :
        SuiteSparseQR <Complex> (ordering, tol, econ, getCTX, A, Bsparse,
            Bdense, Zsparse, Zdense, R, E, H, HPinv, HTau, cc)) ;
}