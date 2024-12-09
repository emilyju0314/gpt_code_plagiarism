mxArray *spqr_mx_put_dense2
(
    Long m,
    Long n,
    double *Ax,         // size nz if real; size 2*nz if complex
    int is_complex,
    cholmod_common *cc
)
{
    mxArray *A ;

    if (cc == NULL) return (NULL) ;

    A = mxCreateDoubleMatrix (0, 0, is_complex ? mxCOMPLEX : mxREAL) ;
    mxSetM (A, m) ;
    mxSetN (A, n) ; 
    MXFREE (mxGetPr (A)) ;
    MXFREE (mxGetPi (A)) ;
    put_values (m*n, A, Ax, is_complex, cc) ;
    return (A) ;
}