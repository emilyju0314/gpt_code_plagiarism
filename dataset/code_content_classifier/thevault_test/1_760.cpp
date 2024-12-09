static IplImage* create_init_img( IplImage* img, int img_dbl, double sigma )
{
  IplImage* gray, * dbl;
  double sig_diff;

  gray = convert_to_gray32( img );
  if( img_dbl )
    {
      sig_diff = sqrt( sigma * sigma - SIFT_INIT_SIGMA * SIFT_INIT_SIGMA * 4 );
      dbl = cvCreateImage( cvSize( img->width*2, img->height*2 ),
                           IPL_DEPTH_32F, 1 );
      cvResize( gray, dbl, CV_INTER_CUBIC );
      cvSmooth( dbl, dbl, CV_GAUSSIAN, 0, 0, sig_diff, sig_diff );
      cvReleaseImage( &gray );
      return dbl;
    }
  else
    {
      sig_diff = sqrt( sigma * sigma - SIFT_INIT_SIGMA * SIFT_INIT_SIGMA );
      cvSmooth( gray, gray, CV_GAUSSIAN, 0, 0, sig_diff, sig_diff );
      return gray;
    }
}