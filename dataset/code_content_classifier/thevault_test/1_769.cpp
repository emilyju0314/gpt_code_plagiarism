static int calc_grad_mag_ori( IplImage* img, int r, int c, double* mag,
                              double* ori )
{
  double dx, dy;

  if( r > 0  &&  r < img->height - 1  &&  c > 0  &&  c < img->width - 1 )
    {
      dx = pixval32f( img, r, c+1 ) - pixval32f( img, r, c-1 );
      dy = pixval32f( img, r-1, c ) - pixval32f( img, r+1, c );
      *mag = sqrt( dx*dx + dy*dy );
      *ori = atan2( dy, dx );
      return 1;
    }

  else
    return 0;
}