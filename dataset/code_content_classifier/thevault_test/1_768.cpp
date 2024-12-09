static CvSeq* scale_space_extrema( IplImage*** dog_pyr, int octvs, int intvls,
                                   double contr_thr, int curv_thr,
                                   CvMemStorage* storage )
{
  CvSeq* features;
  double prelim_contr_thr = 0.5 * contr_thr / intvls;
  struct feature* feat;
  struct detection_data* ddata;
  int o, i, r, c;

  features = cvCreateSeq( 0, sizeof(CvSeq), sizeof(struct feature), storage );
  for( o = 0; o < octvs; o++ )
    for( i = 1; i <= intvls; i++ )
      for(r = SIFT_IMG_BORDER; r < dog_pyr[o][0]->height-SIFT_IMG_BORDER; r++)
        for(c = SIFT_IMG_BORDER; c < dog_pyr[o][0]->width-SIFT_IMG_BORDER; c++)
          /* perform preliminary check on contrast */
          if( std::abs( pixval32f( dog_pyr[o][i], r, c ) ) > prelim_contr_thr )
            if( is_extremum( dog_pyr, o, i, r, c ) )
              {
                feat = interp_extremum(dog_pyr, o, i, r, c, intvls, contr_thr);
                if( feat )
                  {
                    ddata = feat->feature_data;
                    if( ! is_too_edge_like( dog_pyr[ddata->octv][ddata->intvl],
                                            ddata->r, ddata->c, curv_thr ) )
                      {
                        cvSeqPush( features, feat );
                      }
                    else
                      free( ddata );
                    free( feat );
                  }
              }

  return features;
}