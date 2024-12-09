void spqr_mx_get_usage
(
    mxArray *A,         // mxArray to check
    int tight,          // if true, then nnz(A) must equal nzmax(A)
    Long *p_usage,      // bytes used
    Long *p_count,      // # of malloc'd blocks
    cholmod_common *cc
)
{
    Long nz, m, n, nzmax, is_complex, usage, count, *Ap ;
    m = mxGetM (A) ;
    n = mxGetN (A) ;
    is_complex = mxIsComplex (A) ;
    if (mxIsSparse (A))
    {
        nzmax = mxGetNzmax (A) ;
        Ap = (Long *) mxGetJc (A) ;
        nz = MAX (Ap [n], 1) ;
        if (tight && nz != nzmax)
        {
            // This should never occur.
            mexErrMsgIdAndTxt ("QR:internalError", "nnz (A) < nzmax (A)!") ;
        }
        usage = sizeof (Long) * (n+1 + nz) ;
        count = 2 ;
    }
    else
    {
        nz = MAX (m*n,1) ;
        nzmax = nz ;
        usage = 0 ;
        count = 0 ;
    }
    if (is_complex)
    {
        usage += nzmax * sizeof (double) * 2 ;
        count += 2 ;
    }
    else
    {
        usage += nzmax * sizeof (double) ;
        count += 1 ;
    }
    *p_usage = usage ;
    *p_count = count ;
}