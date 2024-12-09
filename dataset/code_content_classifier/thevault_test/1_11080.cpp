double IntFeatureDist::DebugFeatureDistance(const std::vector<int> &features) const {
  const int num_test_features = features.size();
  const double denominator = total_feature_weight_ + num_test_features;
  double misses = denominator;
  for (int i = 0; i < num_test_features; ++i) {
    const int index = features[i];
    const double weight = 1.0;
    INT_FEATURE_STRUCT f = feature_map_->InverseMapFeature(features[i]);
    tprintf("Testing feature weight %g:", weight);
    f.print();
    if (features_[index]) {
      // A perfect match.
      misses -= 2.0 * weight;
      tprintf("Perfect hit\n");
    } else if (features_delta_one_[index]) {
      misses -= 1.5 * weight;
      tprintf("-1 hit\n");
    } else if (features_delta_two_[index]) {
      // A near miss.
      misses -= 1.0 * weight;
      tprintf("-2 hit\n");
    } else {
      tprintf("Total miss\n");
    }
  }
  tprintf("Features present:");
  for (int i = 0; i < size_; ++i) {
    if (features_[i]) {
      INT_FEATURE_STRUCT f = feature_map_->InverseMapFeature(i);
      f.print();
    }
  }
  tprintf("\nMinus one features:");
  for (int i = 0; i < size_; ++i) {
    if (features_delta_one_[i]) {
      INT_FEATURE_STRUCT f = feature_map_->InverseMapFeature(i);
      f.print();
    }
  }
  tprintf("\nMinus two features:");
  for (int i = 0; i < size_; ++i) {
    if (features_delta_two_[i]) {
      INT_FEATURE_STRUCT f = feature_map_->InverseMapFeature(i);
      f.print();
    }
  }
  tprintf("\n");
  return misses / denominator;
}