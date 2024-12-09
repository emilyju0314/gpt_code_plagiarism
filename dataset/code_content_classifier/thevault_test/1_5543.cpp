int SuiteSparseQR_C_numeric // returns TRUE if successful, FALSE otherwise
(
    // inputs:
    double tol,             // treat columns with 2-norm <= tol as zero
    cholmod_sparse *A,      // sparse matrix to factorize
    // input/output:
    SuiteSparseQR_C_factorization *QR,
    cholmod_common *cc      // workspace and parameters
)
{
    RETURN_IF_NULL_COMMON (FALSE) ;
    RETURN_IF_NULL (A, FALSE) ;
    RETURN_IF_NULL (QR, FALSE) ;
    cc->status = CHOLMOD_OK ;

    if (QR->xtype == CHOLMOD_REAL)
    {
        SuiteSparseQR_factorization <double> *QR2 ;
        QR2 = (SuiteSparseQR_factorization <double> *) (QR->factors) ;
        SuiteSparseQR_numeric <double> (tol, A, QR2, cc) ;
    }
    else
    {
        SuiteSparseQR_factorization <Complex> *QR2 ;
        QR2 = (SuiteSparseQR_factorization <Complex> *) (QR->factors) ;
        SuiteSparseQR_numeric <Complex> (tol, A, QR2, cc) ;
    }
    return (TRUE) ;
}