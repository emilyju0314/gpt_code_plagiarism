FEATURE_SET ExtractMicros(TBLOB *Blob, const DENORM &cn_denorm) {
  auto features = BlobMicroFeatures(Blob, cn_denorm);
  if (features.empty()) {
    return nullptr;
  }
  int n = 0;
  for ([[maybe_unused]] auto &f: features) {
    ++n;
  }
  auto FeatureSet = new FEATURE_SET_STRUCT(n);

  for (auto &f : features) {
    auto Feature = new FEATURE_STRUCT(&MicroFeatureDesc);
    for (int i = 0; i < (int)MicroFeatureParameter::MFCount; ++i)
      Feature->Params[i] = f[i];
    // Bulge features are deprecated and should not be used. Set to 0.
    Feature->Params[(int)MicroFeatureParameter::MFBulge1] = 0.0f;
    Feature->Params[(int)MicroFeatureParameter::MFBulge2] = 0.0f;

#ifndef _WIN32
    // Assert that feature parameters are well defined.
    for (int i = 0; i < Feature->Type->NumParams; i++) {
      ASSERT_HOST(!std::isnan(Feature->Params[i]));
    }
#endif

    AddFeature(FeatureSet, Feature);
  }
  return FeatureSet;
}