static struct feature* clone_feature( struct feature* feat )
{
  struct feature* new_feat;
  struct detection_data* ddata;

  new_feat = new_feature();
  ddata = new_feat->feature_data;
  memcpy( new_feat, feat, sizeof( struct feature ) );
  memcpy( ddata, feat->feature_data, sizeof( struct detection_data ) );
  new_feat->feature_data = ddata;

  return new_feat;
}