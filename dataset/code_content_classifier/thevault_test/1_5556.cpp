cholmod_sparse *spqr_mx_get_sparse
(
    const mxArray *Amatlab, // MATLAB version of the matrix
    cholmod_sparse *A,	    // CHOLMOD version of the matrix
    double *dummy 	    // a pointer to a valid scalar double
)
{
    Long *Ap ;
    A->nrow = mxGetM (Amatlab) ;
    A->ncol = mxGetN (Amatlab) ;
    A->p = (Long *) mxGetJc (Amatlab) ;
    A->i = (Long *) mxGetIr (Amatlab) ;
    Ap = (Long *) A->p ;
    A->nzmax = Ap [A->ncol] ;
    A->packed = TRUE ;
    A->sorted = TRUE ;
    A->nz = NULL ;
    A->itype = CHOLMOD_LONG ;
    A->dtype = CHOLMOD_DOUBLE ;     // FUTURE: support single
    A->stype = 0 ;

    if (mxIsEmpty (Amatlab))
    {
	// this is not dereferenced, but the existence (non-NULL) of these
	// pointers is checked in CHOLMOD
	A->x = dummy ;
	A->z = dummy ;
	A->xtype = mxIsComplex (Amatlab) ? CHOLMOD_ZOMPLEX : CHOLMOD_REAL ;
    }
    else if (mxIsDouble (Amatlab))
    {
	A->x = mxGetPr (Amatlab) ;
	A->z = mxGetPi (Amatlab) ;
	A->xtype = mxIsComplex (Amatlab) ? CHOLMOD_ZOMPLEX : CHOLMOD_REAL ;
    }
    else
    {
	// only sparse complex/real double matrices are supported
        mexErrMsgIdAndTxt ("QR:invalidInput", "matrix type not supported") ;
    }

    return (A) ;
}