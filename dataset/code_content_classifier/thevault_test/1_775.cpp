static void calc_feature_oris( CvSeq* features, IplImage*** gauss_pyr )
{
  struct feature* feat;
  struct detection_data* ddata;
  double* hist;
  double omax;
  int i, j, n = features->total;

  for( i = 0; i < n; i++ )
    {
      feat = (feature*) malloc( sizeof( struct feature ) );
      cvSeqPopFront( features, feat );
      ddata = feat->feature_data;
      hist = ori_hist( gauss_pyr[ddata->octv][ddata->intvl],
                       ddata->r, ddata->c, SIFT_ORI_HIST_BINS,
                       cvRound( SIFT_ORI_RADIUS * ddata->scl_octv ),
                       SIFT_ORI_SIG_FCTR * ddata->scl_octv );
      for( j = 0; j < SIFT_ORI_SMOOTH_PASSES; j++ )
        smooth_ori_hist( hist, SIFT_ORI_HIST_BINS );
      omax = dominant_ori( hist, SIFT_ORI_HIST_BINS );
      add_good_ori_features( features, hist, SIFT_ORI_HIST_BINS,
                             omax * SIFT_ORI_PEAK_RATIO, feat );
      free( ddata );
      free( feat );
      free( hist );
    }
}