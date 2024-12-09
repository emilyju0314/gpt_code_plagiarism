cholmod_dense *SuiteSparseQR_C_backslash_default   // returns X, NULL if failure
(
    // inputs:
    cholmod_sparse *A,      // m-by-n sparse matrix
    cholmod_dense  *B,      // m-by-k
    cholmod_common *cc      // workspace and parameters
)
{
    return (SuiteSparseQR_C_backslash (SPQR_ORDERING_DEFAULT, SPQR_DEFAULT_TOL,
        A, B, cc)) ;
}