static double* ori_hist( IplImage* img, int r, int c, int n, int rad,
                         double sigma )
{
  double* hist;
  double mag, ori, w, exp_denom, PI2 = CV_PI * 2.0;
  int bin, i, j;

  hist = (double*) calloc( n, sizeof( double ) );
  exp_denom = 2.0 * sigma * sigma;
  for( i = -rad; i <= rad; i++ )
    for( j = -rad; j <= rad; j++ )
      if( calc_grad_mag_ori( img, r + i, c + j, &mag, &ori ) )
        {
          w = exp( -( i*i + j*j ) / exp_denom );
          bin = cvRound( n * ( ori + CV_PI ) / PI2 );
          bin = ( bin < n )? bin : 0;
          hist[bin] += w * mag;
        }

  return hist;
}