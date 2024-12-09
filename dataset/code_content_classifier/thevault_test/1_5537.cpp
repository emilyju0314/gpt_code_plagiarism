cholmod_sparse *sparse_split
(
    cholmod_sparse *A,
    Long part,
    cholmod_common *cc
)
{
    cholmod_sparse *C ;
    if (!A || A->xtype != CHOLMOD_COMPLEX || A->nz != NULL) return (NULL) ;
    if (! (part == 0 || part == 1)) return (NULL) ;

    Long nz = cholmod_l_nnz (A, cc) ;
    C = cholmod_l_allocate_sparse (A->nrow, A->ncol, nz, TRUE, TRUE, 0,
        CHOLMOD_REAL, cc) ;

    Long *Ap = (Long *) A->p ;
    Long *Ai = (Long *) A->i ;
    double *Ax = (double *) A->x ;

    Long *Cp = (Long *) C->p ;
    Long *Ci = (Long *) C->i ;
    double *Cx = (double *) C->x ;

    Long n = A->ncol ;

    for (Long k = 0 ; k < n+1 ; k++)
    {
        Cp [k] = Ap [k] ;
    }

    for (Long k = 0 ; k < nz ; k++)
    {
        Ci [k] = Ai [k] ;
    }

    for (Long k = 0 ; k < nz ; k++)
    {
        Cx [k] = Ax [2*k + part] ;
    }

    return (C) ;
}