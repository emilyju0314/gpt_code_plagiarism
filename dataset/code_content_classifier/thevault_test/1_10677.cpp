void IntFeatureSpace::IndexFeatures(const INT_FEATURE_STRUCT *features, int num_features,
                                    std::vector<int> *mapped_features) const {
  mapped_features->clear();
  for (int f = 0; f < num_features; ++f) {
    mapped_features->push_back(Index(features[f]));
  }
}