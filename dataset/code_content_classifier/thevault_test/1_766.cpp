static struct feature* interp_extremum( IplImage*** dog_pyr, int octv,
                                        int intvl, int r, int c, int intvls,
                                        double contr_thr )
{
  struct feature* feat;
  struct detection_data* ddata;
  double xi=0, xr=0, xc=0, contr;
  int i = 0;

  while( i < SIFT_MAX_INTERP_STEPS )
    {
      interp_step( dog_pyr, octv, intvl, r, c, &xi, &xr, &xc );
      if( std::abs( xi ) < 0.5  &&  std::abs( xr ) < 0.5  &&  std::abs( xc ) < 0.5 )
        break;

      c += cvRound( xc );
      r += cvRound( xr );
      intvl += cvRound( xi );

      if( intvl < 1  ||
          intvl > intvls  ||
          c < SIFT_IMG_BORDER  ||
          r < SIFT_IMG_BORDER  ||
          c >= dog_pyr[octv][0]->width - SIFT_IMG_BORDER  ||
          r >= dog_pyr[octv][0]->height - SIFT_IMG_BORDER )
        {
          return NULL;
        }

      i++;
    }

  /* ensure convergence of interpolation */
  if( i >= SIFT_MAX_INTERP_STEPS )
    return NULL;

  contr = interp_contr( dog_pyr, octv, intvl, r, c, xi, xr, xc );
  if( std::abs( contr ) < contr_thr / intvls )
    return NULL;

  feat = new_feature();
  ddata = feat->feature_data;
  feat->x = ( c + xc ) * pow( 2.0, octv );
  feat->y = ( r + xr ) * pow( 2.0, octv );
  ddata->r = r;
  ddata->c = c;
  ddata->octv = octv;
  ddata->intvl = intvl;
  ddata->subintvl = xi;

  return feat;
}