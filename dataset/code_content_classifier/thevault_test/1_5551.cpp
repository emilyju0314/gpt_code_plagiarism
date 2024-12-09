int spqr_mx_get_options
(
    const mxArray *mxopts,
    spqr_mx_options *opts,
    Long m,
    int nargout,
    cholmod_common *cc
)
{
    double x ;
    char *s ;
    Long x_present ;

    if (cc == NULL) return (FALSE) ;

    // -------------------------------------------------------------------------
    // spumoni: an integer that defaults to SPUMONI (see spqr_mx.hpp)
    // -------------------------------------------------------------------------

    get_option (mxopts, "spumoni", &x, &x_present, NULL, cc) ;
    opts->spumoni = x_present ? ((Long) x) : SPUMONI ;
    spqr_spumoni = opts->spumoni ;

    // -------------------------------------------------------------------------
    // econ: an integer that defaults to m
    // -------------------------------------------------------------------------

    get_option (mxopts, "econ", &x, &x_present, NULL, cc) ;
    opts->econ = x_present ? ((Long) x) : m ;

    // -------------------------------------------------------------------------
    // tol: a double with default computed later
    // -------------------------------------------------------------------------

    get_option (mxopts, "tol", &x, &x_present, NULL, cc) ;
    opts->tol = x_present ? x : SPQR_DEFAULT_TOL ;

    // -------------------------------------------------------------------------
    // cc->SPQR_grain: defaults to 1 (no TBB parallelism)
    // -------------------------------------------------------------------------

    get_option (mxopts, "grain", &x, &x_present, NULL, cc) ;
    cc->SPQR_grain = x_present ? x : 1 ;

    // -------------------------------------------------------------------------
    // cc->SPQR_small: defaults to 1e6 (min flop count in a TBB task)
    // -------------------------------------------------------------------------

    get_option (mxopts, "small", &x, &x_present, NULL, cc) ;
    cc->SPQR_small = x_present ? x : 1e6 ;

    // -------------------------------------------------------------------------
    // cc->SPQR_shrink: defaults to 1; for testing malloc/realloc only!
    // -------------------------------------------------------------------------

    // NOTE: this feature is not documented in "help spqr".  Nor should it be.
    get_option (mxopts, "shrink", &x, &x_present, NULL, cc) ;
    cc->SPQR_shrink = x_present ? ((int) x) : 1 ;

    // -------------------------------------------------------------------------
    // cc->SPQR_nthreads: defaults to 0; # of threads to use
    // -------------------------------------------------------------------------

    // nthreads = 0 means to use the TBB default
    get_option (mxopts, "nthreads", &x, &x_present, NULL, cc) ;
    cc->SPQR_nthreads = x_present ? ((int) x) : 0 ;
    cc->SPQR_nthreads = MAX (0, cc->SPQR_nthreads) ;

    // -------------------------------------------------------------------------
    // ordering: a string (fixed, natural, colamd, metis, or cholmod)
    // -------------------------------------------------------------------------

    if (nargout < 3)
    {
        // R = qr ( ), [C,R] = qr ( ), or [Q,R] = qr ( ) usages
        opts->ordering = SPQR_ORDERING_FIXED ;
    }
    else
    {
        // [C,R,E] = qr ( ) or [Q,R,E] = qr ( ) usages
        opts->ordering = SPQR_ORDERING_DEFAULT ;
        get_option (mxopts, "ordering", NULL, &x_present, &s, cc) ;
        if (s != NULL)
        {
            if (strcmp (s, "fixed") == 0)
            {
                opts->ordering = SPQR_ORDERING_FIXED ;
            }
            else if (strcmp (s, "natural") == 0)
            {
                opts->ordering = SPQR_ORDERING_NATURAL ;
            }
            else if (strcmp (s, "colamd") == 0)
            {
                opts->ordering = SPQR_ORDERING_COLAMD ;
            }
            else if (strcmp (s, "amd") == 0)
            {
                opts->ordering = SPQR_ORDERING_AMD ;
            }
#ifndef NPARTITION
            else if (strcmp (s, "metis") == 0)
            {
                opts->ordering = SPQR_ORDERING_METIS ;
            }
#endif
            else if (strcmp (s, "best") == 0)
            {
                opts->ordering = SPQR_ORDERING_BEST ;
            }
            else if (strcmp (s, "bestamd") == 0)
            {
                opts->ordering = SPQR_ORDERING_BESTAMD ;
            }
            else if (strcmp (s, "default") == 0)
            {
                opts->ordering = SPQR_ORDERING_DEFAULT ;
            }
            else
            {
                mexErrMsgIdAndTxt ("QR:invalidInput","invalid ordering option");
            }
            MXFREE (s) ;
        }
    }