TrainingSample *TrainingSample::CopyFromFeatures(const INT_FX_RESULT_STRUCT &fx_info,
                                                 const TBOX &bounding_box,
                                                 const INT_FEATURE_STRUCT *features,
                                                 int num_features) {
  auto *sample = new TrainingSample;
  sample->num_features_ = num_features;
  sample->features_ = new INT_FEATURE_STRUCT[num_features];
  sample->outline_length_ = fx_info.Length;
  memcpy(sample->features_, features, num_features * sizeof(features[0]));
  sample->geo_feature_[GeoBottom] = bounding_box.bottom();
  sample->geo_feature_[GeoTop] = bounding_box.top();
  sample->geo_feature_[GeoWidth] = bounding_box.width();

  // Generate the cn_feature_ from the fx_info.
  sample->cn_feature_[CharNormY] = MF_SCALE_FACTOR * (fx_info.Ymean - kBlnBaselineOffset);
  sample->cn_feature_[CharNormLength] = MF_SCALE_FACTOR * fx_info.Length / LENGTH_COMPRESSION;
  sample->cn_feature_[CharNormRx] = MF_SCALE_FACTOR * fx_info.Rx;
  sample->cn_feature_[CharNormRy] = MF_SCALE_FACTOR * fx_info.Ry;

  sample->features_are_indexed_ = false;
  sample->features_are_mapped_ = false;
  return sample;
}