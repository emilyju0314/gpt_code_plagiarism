static int is_extremum( IplImage*** dog_pyr, int octv, int intvl, int r, int c )
{
  double val = pixval32f( dog_pyr[octv][intvl], r, c );
  int i, j, k;

  /* check for maximum */
  if( val > 0 )
    {
      for( i = -1; i <= 1; i++ )
        for( j = -1; j <= 1; j++ )
          for( k = -1; k <= 1; k++ )
            if( val < pixval32f( dog_pyr[octv][intvl+i], r + j, c + k ) )
              return 0;
    }

  /* check for minimum */
  else
    {
      for( i = -1; i <= 1; i++ )
        for( j = -1; j <= 1; j++ )
          for( k = -1; k <= 1; k++ )
            if( val > pixval32f( dog_pyr[octv][intvl+i], r + j, c + k ) )
              return 0;
    }

  return 1;
}