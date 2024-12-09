static double dominant_ori( double* hist, int n )
{
  double omax;
  int maxbin, i;

  omax = hist[0];
  maxbin = 0;
  for( i = 1; i < n; i++ )
    if( hist[i] > omax )
      {
        omax = hist[i];
        maxbin = i;
      }
  return omax;
}