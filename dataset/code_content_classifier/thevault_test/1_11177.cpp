void NormalizePicoX(FEATURE_SET FeatureSet) {
  int i;
  FEATURE Feature;
  float Origin = 0.0;

  for (i = 0; i < FeatureSet->NumFeatures; i++) {
    Feature = FeatureSet->Features[i];
    Origin += Feature->Params[PicoFeatX];
  }
  Origin /= FeatureSet->NumFeatures;

  for (i = 0; i < FeatureSet->NumFeatures; i++) {
    Feature = FeatureSet->Features[i];
    Feature->Params[PicoFeatX] -= Origin;
  }
}