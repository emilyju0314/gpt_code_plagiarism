double maclinminII 
(
 double *p , 
 void   (*dfunc)(double *,double *, void *), /* evaluates the gradient */
 void   *arg ,
 macopt_args *a )
{
  int n = a->n ; 

  double x , y ;
  double s , t , m ;
  int    its = 1 , i ;
  double step , tmpd ; 
  double  *gx = a->gx , *gy = a->gy ;

/* MNG added stuff */
  double x_new;
  double temp1,max;

  /* at x=0, the gradient (uphill) satisfies s < 0 */
  if ( a->verbose > 2 ) { /* check this is true: (no need to do this really
			   as it is already checked at the end of the main
			   loop of macopt) */
    fprintf (stderr, "inner product at 0 = %9.4g\n" ,
	     tmpd = macprodII ( p , gy , 0.0 , dfunc , arg , a ) ) ; 
    if ( tmpd > 0.0 ) { 
      a->restart = 1 ; 
      return 0.0 ; 
    }
  }

  x = a->lastx / a->gtyp ;

/* MNG alteration :

   Here we check to make sure that the step in x is not going
   to change the value of the hyperparameters by anything more
   than 1.0 on the first go. This is to avoid initial massive
   steps that are making things screw up
*/
  
  max = 0.0;
  x_new = x;
  for(i=1; i <= n; ++i){
    temp1 = fabs(a->xi[i]*x);
    if( temp1 > max && temp1 > 1.0){
      max = temp1;
      x_new = fabs(1.0 / a->xi[i]);
    }
  }
  if( x != x_new ){
    if ( a->verbose > 1 ) 
      printf("Note : maclinmin step truncated\n");
    x = x_new;
  }

  s = macprodII ( p , gx , x , dfunc , arg , a ) ; 
  
  if ( s < 0 )  {  /* we need to go further */
    do {
      y = x * a->linmin_g1 ;
      t = macprodII ( p , gy , y , dfunc , arg , a ) ; 
      if ( a->verbose > 1 ) 
	printf ("s = %6.3g: t = %6.3g; x = %6.3g y = %6.3g\n",s, t , x , y );
      else if ( a->verbose >= 1 ) 
	printf ("-") ; 
      if ( t >= 0.0 ) break ;
      x = y ; s = t ; a->gunused = gx ; gx = gy ; gy = a->gunused ; 
      its++ ;
/* replaces: for ( i = 1 ; i <= n ; i ++ ) gx[i] = gy[i] ; */
    }
    while ( its <= a->linmin_maxits ) ;
  } else if ( s > 0 ) { /* need to step back inside interval */
    do {
      y = x * a->linmin_g3 ;
      t = macprodII ( p , gy , y , dfunc , arg , a ) ; 
      if ( a->verbose > 1 ) 
	printf ("s = %6.3g: t = %6.3g; x = %6.3g y = %6.3g\n",s, t , x , y );
      if ( t <= 0.0 ) break ;
      x = y ; s = t ; a->gunused = gx ; gx = gy ; gy = a->gunused ; 
      its ++ ;
    } while ( its <= a->linmin_maxits ) ;
  } else { /* hole in one s = 0.0 */
    t = 1.0 ; y = x;
  }

  if ( its > a->linmin_maxits )  {
    fprintf (stderr, "Warning! maclinmin overran" );
/* this can happen where the function goes \_ and doesn't buck up
 again; it also happens if the initial `gradient' does not satisfy
 gradient.`gradient' > 0, so that there is no minimum in the supposed
 downhill direction.  I don't know if this actually happens... If it
 does then I guess a->rich should be 1.

 If the overrun is because too big a step was taken then
 the interpolation should be made between zero and the most 
 recent measurement. 

 If the overrun is because too small a step was taken then 
 the best place to go is the most distant point. 
 I will assume that this doesn't happen for the moment.

 Also need to check up what happens to t and s in the case of overrun.
 And gx and gy. 

 Maybe sort this out when writing a macopt that makes use of the gradient 
 at zero? 
*/
    fprintf (stderr, "- inner product at 0 = %9.4g\n" ,
	     tmpd = macprodII ( p , gy , 0.0 , dfunc , arg , a ) ) ; 
    if ( tmpd > 0 && a->rich == 0 ) {
      fprintf (stderr, "setting rich to 1\n" ) ;       a->rich = 1 ; 
    }
    if ( tmpd > 0 ) a->restart = 1 ; 
  }


/*  Linear interpolate between the last two. 
     This assumes that x and y do bracket. */
  if ( s < 0.0 ) s = - s ;
  if ( t < 0.0 ) t = - t ;
  m = ( s + t ) ;
  s /= m ; t /= m ;
  
  m =  s * y + t * x ; 
/* evaluate the step length, not that it necessarily means anything */
  for ( step = 0.0 , i = 1 ; i <= n ; i ++ ) {
    tmpd = m * a->xi[i] ;
    p[i] += tmpd ; /* this is the point where the parameter vector steps */
    step += fabs ( tmpd ) ; 
    a->xi[i] = s * gy[i] + t * gx[i] ;
/* send back the estimated gradient in xi (NB not like linmin) */
  }
  a->lastx = m * a->linmin_g2 *  a->gtyp ;
  
  return ( step / (double) ( n ) ) ; 
}