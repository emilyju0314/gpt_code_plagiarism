FEATURE_SET Classify::ExtractIntCNFeatures(const TBLOB &blob, const INT_FX_RESULT_STRUCT &fx_info) {
  INT_FX_RESULT_STRUCT local_fx_info(fx_info);
  std::vector<INT_FEATURE_STRUCT> bl_features;
  tesseract::TrainingSample *sample =
      tesseract::BlobToTrainingSample(blob, false, &local_fx_info, &bl_features);
  if (sample == nullptr) {
    return nullptr;
  }

  uint32_t num_features = sample->num_features();
  const INT_FEATURE_STRUCT *features = sample->features();
  auto feature_set = new FEATURE_SET_STRUCT(num_features);
  for (uint32_t f = 0; f < num_features; ++f) {
    auto feature = new FEATURE_STRUCT(&IntFeatDesc);
    feature->Params[IntX] = features[f].X;
    feature->Params[IntY] = features[f].Y;
    feature->Params[IntDir] = features[f].Theta;
    AddFeature(feature_set, feature);
  }
  delete sample;

  return feature_set;
}