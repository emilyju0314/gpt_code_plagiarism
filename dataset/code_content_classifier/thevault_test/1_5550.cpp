void spqr_mx_spumoni
(
    spqr_mx_options *opts,
    int is_complex,             // TRUE if complex, FALSE if real
    cholmod_common *cc
)
{
    // -------------------------------------------------------------------------
    // author and copyright
    // -------------------------------------------------------------------------

    mexPrintf (
    "\nSuiteSparseQR, version %d.%d.%d (%s), a multithreaded\n"
    "multifrontal sparse QR factorization method, (c) Timothy A. Davis,\n"
    "http://www.suitesparse.com\n\n",
        SPQR_MAIN_VERSION, SPQR_SUB_VERSION, SPQR_SUBSUB_VERSION, SPQR_DATE) ;

    // -------------------------------------------------------------------------
    // installation
    // -------------------------------------------------------------------------

    if (opts->spumoni > 1)
    {
        mexPrintf (
            "Installation:\n"
            "    size of mwIndex:  %d bytes\n"
            "    size of int:      %d bytes\n"
            "    size of BLAS int: %d bytes\n",
            sizeof (mwIndex), sizeof (int), sizeof (BLAS_INT)) ;
#ifdef HAVE_TBB
        mexPrintf ("    compiled with Intel Threading Building Blocks (TBB)\n");
#endif
#ifndef NEXPERT
        mexPrintf ("    compiled with opts.solution='min2norm' option\n") ;
#endif
#ifndef NPARTITION
        mexPrintf (
            "    compiled with opts.ordering='metis' option\n") ;
#endif
    }

    // -------------------------------------------------------------------------
    // input options
    // -------------------------------------------------------------------------

    mexPrintf ("Input options:\n") ;

    if (opts->tol <= SPQR_DEFAULT_TOL)
    {
        mexPrintf ("    opts.tol <= %g (use default tolerance)\n",
            (double) SPQR_DEFAULT_TOL) ;
    }
    else if (opts->tol < 0)
    {
        mexPrintf ("    %g < opts.tol < 0 (use no tolerance)\n",
            (double) SPQR_DEFAULT_TOL) ;
    }
    else
    {
        mexPrintf ("    opts.tol = %g (column 2-norm tolerance)\n", opts->tol) ;
    }

    mexPrintf ("    opts.Q = '") ;
    switch (opts->Qformat)
    {
        case SPQR_Q_DISCARD:      mexPrintf ("discard'\n") ;     break ;
        case SPQR_Q_MATRIX:       mexPrintf ("matrix'\n") ;      break ;
        case SPQR_Q_HOUSEHOLDER:  mexPrintf ("Householder'\n") ; break ;
        default:                  mexPrintf ("undefined'\n") ;   break ;
    }

    mexPrintf ("    opts.econ = %ld"
        " (# of rows of R is max (min (m, opts.econ), r)\n"
        "        where m = size(A,1) and r = rank(A) estimate)\n",
        opts->econ) ;

    mexPrintf ("    opts.ordering = '") ;
    switch (opts->ordering)
    {
        case SPQR_ORDERING_FIXED:   mexPrintf ("fixed'\n") ;   break ;
        case SPQR_ORDERING_NATURAL: mexPrintf ("natural'\n") ; break ;
        case SPQR_ORDERING_COLAMD:  mexPrintf ("colamd'\n") ;  break ;
        case SPQR_ORDERING_GIVEN:   mexPrintf ("given'\n") ;   break ;
        case SPQR_ORDERING_CHOLMOD: mexPrintf ("best'\n") ;    break ;
        case SPQR_ORDERING_AMD:     mexPrintf ("amd'\n") ;     break ;
#ifndef NPARTITION
        case SPQR_ORDERING_METIS:   mexPrintf ("metis'\n") ;   break ;
#endif
        case SPQR_ORDERING_DEFAULT: mexPrintf ("default'\n") ; break ;
        default: mexPrintf ("undefined'\n") ; break ;
    }

    mexPrintf ("    opts.permutation = ") ;
    if (opts->permvector)
    {
        mexPrintf ("'vector'\n") ;
    }
    else
    {
        mexPrintf ("'matrix'\n") ;
    }

    mexPrintf ("    opts.solution = ") ;
    if (opts->min2norm)
    {
        mexPrintf ("'min2norm'\n") ;
    }
    else
    {
        mexPrintf ("'basic'\n") ;
    }

#ifdef HAVE_TBB
    mexPrintf (
    "    opts.grain = %g, opts.small = %g, opts.nthreads = %d\n"
    "        The analysis for TBB parallelism constructs a task graph by\n"
    "        merging nodes in the frontal elimination tree, which is itself\n"
    "        a coalescing of the column elimination tree with one node per\n"
    "        column in the matrix.  The goal of the merging heuristic is to\n"
    "        create a task graph whose leaf nodes have flop counts >=\n"
    "        max ((total flops)/opts.grain, opts.small).  If opts.grain <= 1,\n"
    "        then no TBB parallelism is exploited.  The current default is\n"
    "        opts.grain=1 because in the current version of TBB and OpenMP,\n"
    "        TBB parallelism conflicts with BLAS OpenMP-based parallelism.\n"
    "        This will be resolved in a future version.\n"
    "        opts.nthreads is the number of threads that TBB should use.\n"
    "        If zero, the TBB default is used, which is normally the total\n"
    "        number of cores your computer has.\n",
        cc->SPQR_grain, cc->SPQR_small, cc->SPQR_nthreads) ;
#endif

    // -------------------------------------------------------------------------
    // output statistics
    // -------------------------------------------------------------------------

    mexPrintf ("Output statistics:\n") ;
    mexPrintf ("    upper bound on nnz(R): %ld\n",        cc->SPQR_istat [0]) ;
    mexPrintf ("    upper bound on nnz(H): %ld\n",        cc->SPQR_istat [1]) ;
    mexPrintf ("    number of frontal matrices: %ld\n",   cc->SPQR_istat [2]) ;
    mexPrintf ("    # tasks in TBB task tree: %ld\n",     cc->SPQR_istat [3]) ;
    mexPrintf ("    rank(A) estimate: %ld\n",             cc->SPQR_istat [4]) ;
    mexPrintf ("    # of column singletons: %ld\n",       cc->SPQR_istat [5]) ;
    mexPrintf ("    # of singleton rows: %ld\n",          cc->SPQR_istat [6]) ;
    mexPrintf ("    upper bound on flop count: %g\n",
        cc->SPQR_flopcount_bound * (is_complex ? 4 : 1)) ;
    mexPrintf ("    column 2-norm tolerance used: %g\n",  cc->SPQR_tol_used) ;
    mexPrintf ("    actual memory usage: %g (bytes)\n",
        ((double) cc->memory_usage)) ;

    // Place additional spumoni info here ...
}