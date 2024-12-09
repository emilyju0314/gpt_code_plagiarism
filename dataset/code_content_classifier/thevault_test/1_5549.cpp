int spqr_mx_config (Long spumoni, cholmod_common *cc)
{
    if (cc == NULL) return (FALSE) ;

    // cholmod_l_solve must return a real or zomplex X for MATLAB
    cc->prefer_zomplex = TRUE ;

    // printing and error handling
    if (spumoni == 0)
    {
	// do not print anything from within CHOLMOD
	cc->print = -1 ;
	SuiteSparse_config.printf_func = NULL ;
    }
    else
    {
	// spumoni = 1: print warning and error messages.  cholmod_l_print_*
	//	routines will print a one-line summary of each object printed.
	// spumoni = 2: also print a short summary of each object.
	cc->print = spumoni + 2 ;
    }

    // error handler
    cc->error_handler = spqr_mx_error ;
    spqr_spumoni = spumoni ;

    // Turn off METIS memory guard.  It is not needed, because mxMalloc will
    // safely terminate the mexFunction and free any workspace without killing
    // all of MATLAB.  This assumes spqr_make was used to compile SuiteSparseQR
    // for MATLAB.
    cc->metis_memory = 0.0 ;

    cc->SPQR_grain = 1 ;    // opts.grain
    cc->SPQR_small = 1e6 ;  // opts.small
    cc->SPQR_shrink = 1 ;   // controls SPQR shrink realloc
    cc->SPQR_nthreads = 0 ; // number of TBB threads (0 = default)

    return (TRUE) ;
}