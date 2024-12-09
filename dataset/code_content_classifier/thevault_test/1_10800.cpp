FEATURE_STRUCT *TrainingSample::GetCNFeature() const {
  auto feature = new FEATURE_STRUCT(&CharNormDesc);
  for (int i = 0; i < kNumCNParams; ++i) {
    feature->Params[i] = cn_feature_[i];
  }
  return feature;
}