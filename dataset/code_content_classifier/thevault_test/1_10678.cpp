void IntFeatureSpace::IndexAndSortFeatures(const INT_FEATURE_STRUCT *features, int num_features,
                                           std::vector<int> *sorted_features) const {
  sorted_features->clear();
  for (int f = 0; f < num_features; ++f) {
    sorted_features->push_back(Index(features[f]));
  }
  std::sort(sorted_features->begin(), sorted_features->end());
}