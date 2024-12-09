static struct feature* new_feature( void )
{
  struct feature* feat;
  struct detection_data* ddata;

  feat = (feature*) malloc( sizeof( struct feature ) );
  memset( feat, 0, sizeof( struct feature ) );
  ddata = (detection_data*) malloc( sizeof( struct detection_data ) );
  memset( ddata, 0, sizeof( struct detection_data ) );
  feat->feature_data = ddata;

  return feat;
}