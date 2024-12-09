mxArray *spqr_mx_put_sparse
(
    cholmod_sparse **Ahandle,	// CHOLMOD version of the matrix
    cholmod_common *cc
)
{
    mxArray *Amatlab ;
    cholmod_sparse *A ;
    Long nz, is_complex ;

    A = *Ahandle ;
    is_complex = (A->xtype != CHOLMOD_REAL) ;
    Amatlab = mxCreateSparse (0, 0, 0, is_complex ? mxCOMPLEX: mxREAL) ;
    mxSetM (Amatlab, A->nrow) ;
    mxSetN (Amatlab, A->ncol) ;
    mxSetNzmax (Amatlab, A->nzmax) ;
    MXFREE (mxGetJc (Amatlab)) ;
    MXFREE (mxGetIr (Amatlab)) ;
    MXFREE (mxGetPr (Amatlab)) ;
    mxSetJc (Amatlab, (mwIndex *) A->p) ;
    mxSetIr (Amatlab, (mwIndex *) A->i) ;

    nz = cholmod_l_nnz (A, cc) ;
    put_values (nz, Amatlab, (double *) A->x, is_complex, cc) ;

    A->p = NULL ;
    A->i = NULL ;
    A->x = NULL ;
    A->z = NULL ;
    cholmod_l_free_sparse (Ahandle, cc) ;
    return (Amatlab) ;
}