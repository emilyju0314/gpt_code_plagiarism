void macoptII
  (double *p,            /* starting vector                                */
   int    n,             /* number of dimensions                           */
   void   (*dfunc)(double *,double *, void *), 
                         /* evaluates the gradient of the optimized function */
   void   *dfunc_arg,    /* arguments that get passed to dfunc             */
   macopt_args *a        /* structure in which optimizer arguments stored  */
/*   int  do_newitfunc , 
   void (*newitfunc)(double *,int) */
                         /* function executed at beginning of each itn */
   )                     /* Note, (*func)(double *,void *) is not used     */
{
  int j ;
  double gg , gam , dgg ;
  double *g , *h , *xi ;
  int end_if_small_grad = 1 - a->end_if_small_step ;
  double step , tmpd ;

  /* A total of 7 double * 1..n are used by this optimizer. 
     p           is provided when the optimizer is called 
     pt          is used by the line minimizer as the temporary vector. 
                    this could be cut out with minor rewriting, using p alone
     g, h and xi are used by the cg method as in NR - could one of these
                     be cut out?
     the line minimizer uses an extra gx and gy to evaluate two gradients. 
     */
  
  a->n = n ; 
  a->g = dvector ( 1 , n ) ; g = a->g ;    /* vectors as in NR code */
  a->h = dvector ( 1 , n ) ; h = a->h ;    /*                       */
  a->xi = dvector ( 1 , n ) ; xi = a->xi ; /*                       */
  a->pt = dvector ( 1 , n ) ; /* scratch vector for sole use of macprod */
  a->gx = dvector ( 1 , n ) ; /* scratch gradients             */
  a->gy = dvector ( 1 , n ) ; /* used by maclinmin and macprod */

  (*dfunc)( p , xi , dfunc_arg );
  macopt_restart ( a , 1 ) ; 
  for ( a->its = 1 ; a->its <= a->itmax ; a->its ++ ) {

    for ( gg = 0.0 , j = 1 ; j <= n ; j ++ ) 
      gg += g[j]*g[j];          /* find the magnitude of the old gradient */
    a->gtyp = sqrt ( gg / (double)(n) ) ; 

    if ( a->verbose > 0 ) 
      printf ( "mac_it %d of %d : gg = %6.3g tol = %6.3g: ", a->its , a->itmax , gg , a->tol ) ;

    if ( a->do_newitfunc ) { /* print state of parameters to file */
      (*(a->newitfunc))(p, a->its, a->newitfuncarg); 
    }

    if ( ( end_if_small_grad && ( gg <= a->tol ) ) 
	|| ( gg <= a->grad_tol_tiny ) ) {
      macopt_free ( a ) ;
      if ( a->verbose > 0 ) printf ("\n");
      return;
    }

    step = maclinminII ( p , dfunc , dfunc_arg , a ) ; 

    if ( a->restart == 0 ) {
      if ( a->verbose > 1 ) printf (" (step %9.5g)",step);
      if ( a->verbose > 0 ) printf ("\n");
      if ( ( a->end_if_small_step  && ( step <= a->tol ) ) 
	  || ( step <= a->step_tol_tiny ) ) {
	macopt_free ( a ) ;
	return;
      }
    }

    /* if we are feeling rich, evaluate the gradient at the new
       `minimum'. alternatively, linmin has already estimated this
       gradient by linear combination of the last two evaluations and
       left it in xi */
    if ( a->rich || a->restart ) { 
      (*dfunc)( p , xi , dfunc_arg ) ; 
    }
    if ( a->restart ) {
      fprintf(stderr,"Restarting macopt\n" ) ; 
      macopt_restart ( a , 0 ) ;
/* this is not quite right
   should distinguish whether there was an overrun indicating that the 
   value of lastx needs to be bigger / smaller; 
   in which case resetting lastx to default value may be a bad idea, 
   giving an endless loop of resets 
*/
    } else {
      dgg=0.0;
      for ( j = 1 ; j <= n ; j ++ ) {
	dgg += ( xi[j] + g[j] ) * xi[j] ;
      }
      gam = dgg / gg ;
      for ( tmpd = 0.0 , j = 1 ; j <= n ; j ++ ) {
	g[j] = -xi[j];                /* g stores (-) the most recent gradient */
	xi[j] = h[j] = g[j] + gam * h[j] ;
	/* h stores xi, the current line direction */
	/* check that the inner product of gradient and line search is < 0 */
	tmpd -= xi[j] * g[j] ; 
      }
      if ( tmpd > 0.0  || a->verbose > 2 ) {
	fprintf(stderr,"new line search has inner prod %9.4g\n", tmpd ) ; 
      }
      if ( tmpd > 0.0 ) { 
	if ( a->rich == 0 ) {
	  fprintf (stderr, "Setting rich to 1; " ) ; 
	  a->rich = 1 ; 
	}
	a->restart = 2 ; /* signifies that g[j] = -xi[j] is already done */
	fprintf(stderr,"Restarting macopt (2)\n" ) ; 
	macopt_restart ( a , 0 ) ;
      }
    }
  }
  fprintf(stderr,"Reached iteration limit (%d) in macopt; continuing.\n" , a->itmax); 
  macopt_free ( a ) ;	
  return;
}