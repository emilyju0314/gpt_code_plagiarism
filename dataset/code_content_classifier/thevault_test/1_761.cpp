static IplImage* downsample( IplImage* img )
{
  IplImage* smaller = cvCreateImage( cvSize(img->width / 2, img->height / 2),
                                     img->depth, img->nChannels );
  cvResize( img, smaller, CV_INTER_NN );

  return smaller;
}