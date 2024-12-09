FEATURE_SET ExtractCharNormFeatures(const INT_FX_RESULT_STRUCT &fx_info) {
  auto feature_set = new FEATURE_SET_STRUCT(1);
  auto feature = new FEATURE_STRUCT(&CharNormDesc);

  feature->Params[CharNormY] = MF_SCALE_FACTOR * (fx_info.Ymean - kBlnBaselineOffset);
  feature->Params[CharNormLength] = MF_SCALE_FACTOR * fx_info.Length / LENGTH_COMPRESSION;
  feature->Params[CharNormRx] = MF_SCALE_FACTOR * fx_info.Rx;
  feature->Params[CharNormRy] = MF_SCALE_FACTOR * fx_info.Ry;

  AddFeature(feature_set, feature);

  return feature_set;
}