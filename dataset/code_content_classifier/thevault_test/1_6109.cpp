float SegmenterMS::my_sampling( int rect, float T[Max_rects][p_max])
{ 
  register int  k, c;
  register float L,U,V,Res;
  register float my_dist=max_dist, my_sqrt_dist=fix_RADIUS[0];
  float	TJ[Max_J][p_max];
  int	l =  0;       //contor of number of subsample sets
  int	ll = 0;       //contor of trials
  float	Xmean[p_max];
  float	Obj_fct[Max_J];
 
  //Max_trials = max number of failed trials
  //_NJ = max number of subsample sets
   
  while ( (ll < Max_trials) && (l < _NJ ) )
    {
      if ( subsample(Xmean) )    // the subsample procedure succeeded
	{ 
	      ll = 0; c=0;

	      // Save the mean
	      for ( k = 0; k < _p; k++ ) TJ[l][k] = Xmean[k];

	      // Compute the square residuals (Euclid dist.)
	      if(auto_segm)
                  for ( register int p = 0; p < _n_col_remain; p++ )
		    {
		     k=_col_remain[p];
                     L=_col0[k]-Xmean[0]; if(my_abs(L)>=my_sqrt_dist) continue;
		     U=_col1[k]-Xmean[1]; if(my_abs(U)>=my_sqrt_dist) continue;
		     V=_col2[k]-Xmean[2]; if(my_abs(V)>=my_sqrt_dist) continue;
		     if(L*L+U*U+V*V<my_dist) c+=_m_col_remain[k];
		    }
	      else
	          for ( k = 0; k < _n_points; k++ )
		    {
                     L=_data[0][k]-Xmean[0]; 
                     if(my_abs(L)>=my_sqrt_dist) continue; 
		     U=_data[1][k]-Xmean[1]; 
                     if(my_abs(U)>=my_sqrt_dist) continue; 
		     V=_data[2][k]-Xmean[2]; 
                     if(my_abs(V)>=my_sqrt_dist) continue; 
                     if(L*L+U*U+V*V<my_dist) c++;
		    }
	      
              //  Objective functions
	      Obj_fct[l]=c;
              l++;
	    }
      else ++ll;	
    }
  if ( ll == Max_trials && l < 1) return( BIG_NUM ); // Cannot find a kernel

  //  Choose the highest density  
  L = -BIG_NUM; c=0;
  for ( k = 0; k < _NJ; k++ )
      if ( Obj_fct[k] > L)
	{
	  L = Obj_fct[k];
	  c = k;
	}
  if(Obj_fct[c]>0)
    for(k=0;k<_p;k++)
       T[rect][k]=TJ[c][k];
  else return -BIG_NUM; // Not enough points
  return ( 0 );
}