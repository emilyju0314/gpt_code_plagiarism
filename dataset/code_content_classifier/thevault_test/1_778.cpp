static void hist_to_descr( double*** hist, int d, int n, struct feature* feat )
{
  int int_val, i, r, c, o, k = 0;

  for( r = 0; r < d; r++ )
    for( c = 0; c < d; c++ )
      for( o = 0; o < n; o++ )
        feat->descr[k++] = hist[r][c][o];

  feat->d = k;
  normalize_descr( feat );
  for( i = 0; i < k; i++ )
    if( feat->descr[i] > SIFT_DESCR_MAG_THR )
      feat->descr[i] = SIFT_DESCR_MAG_THR;
  normalize_descr( feat );

  /* convert floating-point descriptor to integer valued descriptor */
  for( i = 0; i < k; i++ )
    {
      int_val = (int)(SIFT_INT_DESCR_FCTR * feat->descr[i]);
      feat->descr[i] = MIN( 255, int_val );
    }
}