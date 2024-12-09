static void add_good_ori_features( CvSeq* features, double* hist, int n,
                                   double mag_thr, struct feature* feat )
{
  struct feature* new_feat;
  double bin, PI2 = CV_PI * 2.0;
  int l, r, i;

  for( i = 0; i < n; i++ )
    {
      l = ( i == 0 )? n - 1 : i-1;
      r = ( i + 1 ) % n;

      if( hist[i] > hist[l]  &&  hist[i] > hist[r]  &&  hist[i] >= mag_thr )
        {
          bin = i + interp_hist_peak( hist[l], hist[i], hist[r] );
          bin = ( bin < 0 )? n + bin : ( bin >= n )? bin - n : bin;
          new_feat = clone_feature( feat );
          new_feat->ori = ( ( PI2 * bin ) / n ) - CV_PI;
          cvSeqPush( features, new_feat );
          free( new_feat );
        }
    }
}