static CvMat* hessian_3D( IplImage*** dog_pyr, int octv, int intvl, int r,
                          int c )
{
  CvMat* H;
  double v, dxx, dyy, dss, dxy, dxs, dys;

  v = pixval32f( dog_pyr[octv][intvl], r, c );
  dxx = ( pixval32f( dog_pyr[octv][intvl], r, c+1 ) +
          pixval32f( dog_pyr[octv][intvl], r, c-1 ) - 2 * v );
  dyy = ( pixval32f( dog_pyr[octv][intvl], r+1, c ) +
          pixval32f( dog_pyr[octv][intvl], r-1, c ) - 2 * v );
  dss = ( pixval32f( dog_pyr[octv][intvl+1], r, c ) +
          pixval32f( dog_pyr[octv][intvl-1], r, c ) - 2 * v );
  dxy = ( pixval32f( dog_pyr[octv][intvl], r+1, c+1 ) -
          pixval32f( dog_pyr[octv][intvl], r+1, c-1 ) -
          pixval32f( dog_pyr[octv][intvl], r-1, c+1 ) +
          pixval32f( dog_pyr[octv][intvl], r-1, c-1 ) ) / 4.0;
  dxs = ( pixval32f( dog_pyr[octv][intvl+1], r, c+1 ) -
          pixval32f( dog_pyr[octv][intvl+1], r, c-1 ) -
          pixval32f( dog_pyr[octv][intvl-1], r, c+1 ) +
          pixval32f( dog_pyr[octv][intvl-1], r, c-1 ) ) / 4.0;
  dys = ( pixval32f( dog_pyr[octv][intvl+1], r+1, c ) -
          pixval32f( dog_pyr[octv][intvl+1], r-1, c ) -
          pixval32f( dog_pyr[octv][intvl-1], r+1, c ) +
          pixval32f( dog_pyr[octv][intvl-1], r-1, c ) ) / 4.0;

  H = cvCreateMat( 3, 3, CV_64FC1 );
  cvmSet( H, 0, 0, dxx );
  cvmSet( H, 0, 1, dxy );
  cvmSet( H, 0, 2, dxs );
  cvmSet( H, 1, 0, dxy );
  cvmSet( H, 1, 1, dyy );
  cvmSet( H, 1, 2, dys );
  cvmSet( H, 2, 0, dxs );
  cvmSet( H, 2, 1, dys );
  cvmSet( H, 2, 2, dss );

  return H;
}