static int is_too_edge_like( IplImage* dog_img, int r, int c, int curv_thr )
{
  double d, dxx, dyy, dxy, tr, det;

  /* principal curvatures are computed using the trace and det of Hessian */
  d = pixval32f(dog_img, r, c);
  dxx = pixval32f( dog_img, r, c+1 ) + pixval32f( dog_img, r, c-1 ) - 2 * d;
  dyy = pixval32f( dog_img, r+1, c ) + pixval32f( dog_img, r-1, c ) - 2 * d;
  dxy = ( pixval32f(dog_img, r+1, c+1) - pixval32f(dog_img, r+1, c-1) -
          pixval32f(dog_img, r-1, c+1) + pixval32f(dog_img, r-1, c-1) ) / 4.0;
  tr = dxx + dyy;
  det = dxx * dyy - dxy * dxy;

  /* negative determinant -> curvatures have different signs; reject feature */
  if( det <= 0 )
    return 1;

  if( tr * tr / det < ( curv_thr + 1.0 )*( curv_thr + 1.0 ) / curv_thr )
    return 0;
  return 1;
}