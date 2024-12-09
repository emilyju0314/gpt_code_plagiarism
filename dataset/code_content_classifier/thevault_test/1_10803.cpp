void TrainingSample::ExtractCharDesc(int int_feature_type, int micro_type, int cn_type,
                                     int geo_type, CHAR_DESC_STRUCT *char_desc) {
  // Extract the INT features.
  delete[] features_;
  FEATURE_SET_STRUCT *char_features = char_desc->FeatureSets[int_feature_type];
  if (char_features == nullptr) {
    tprintf("Error: no features to train on of type %s\n", kIntFeatureType);
    num_features_ = 0;
    features_ = nullptr;
  } else {
    num_features_ = char_features->NumFeatures;
    features_ = new INT_FEATURE_STRUCT[num_features_];
    for (uint32_t f = 0; f < num_features_; ++f) {
      features_[f].X = static_cast<uint8_t>(char_features->Features[f]->Params[IntX]);
      features_[f].Y = static_cast<uint8_t>(char_features->Features[f]->Params[IntY]);
      features_[f].Theta = static_cast<uint8_t>(char_features->Features[f]->Params[IntDir]);
      features_[f].CP_misses = 0;
    }
  }
  // Extract the Micro features.
  delete[] micro_features_;
  char_features = char_desc->FeatureSets[micro_type];
  if (char_features == nullptr) {
    tprintf("Error: no features to train on of type %s\n", kMicroFeatureType);
    num_micro_features_ = 0;
    micro_features_ = nullptr;
  } else {
    num_micro_features_ = char_features->NumFeatures;
    micro_features_ = new MicroFeature[num_micro_features_];
    for (uint32_t f = 0; f < num_micro_features_; ++f) {
      for (int d = 0; d < (int)MicroFeatureParameter::MFCount; ++d) {
        micro_features_[f][d] = char_features->Features[f]->Params[d];
      }
    }
  }
  // Extract the CN feature.
  char_features = char_desc->FeatureSets[cn_type];
  if (char_features == nullptr) {
    tprintf("Error: no CN feature to train on.\n");
  } else {
    ASSERT_HOST(char_features->NumFeatures == 1);
    cn_feature_[CharNormY] = char_features->Features[0]->Params[CharNormY];
    cn_feature_[CharNormLength] = char_features->Features[0]->Params[CharNormLength];
    cn_feature_[CharNormRx] = char_features->Features[0]->Params[CharNormRx];
    cn_feature_[CharNormRy] = char_features->Features[0]->Params[CharNormRy];
  }
  // Extract the Geo feature.
  char_features = char_desc->FeatureSets[geo_type];
  if (char_features == nullptr) {
    tprintf("Error: no Geo feature to train on.\n");
  } else {
    ASSERT_HOST(char_features->NumFeatures == 1);
    geo_feature_[GeoBottom] = char_features->Features[0]->Params[GeoBottom];
    geo_feature_[GeoTop] = char_features->Features[0]->Params[GeoTop];
    geo_feature_[GeoWidth] = char_features->Features[0]->Params[GeoWidth];
  }
  features_are_indexed_ = false;
  features_are_mapped_ = false;
}