double IntFeatureDist::FeatureDistance(const std::vector<int> &features) const {
  const int num_test_features = features.size();
  const double denominator = total_feature_weight_ + num_test_features;
  double misses = denominator;
  for (int i = 0; i < num_test_features; ++i) {
    const int index = features[i];
    const double weight = 1.0;
    if (features_[index]) {
      // A perfect match.
      misses -= 2.0 * weight;
    } else if (features_delta_one_[index]) {
      misses -= 1.5 * weight;
    } else if (features_delta_two_[index]) {
      // A near miss.
      misses -= 1.0 * weight;
    }
  }
  return misses / denominator;
}