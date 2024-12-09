void TrainingSample::IndexFeatures(const IntFeatureSpace &feature_space) {
  std::vector<int> indexed_features;
  feature_space.IndexAndSortFeatures(features_, num_features_, &mapped_features_);
  features_are_indexed_ = true;
  features_are_mapped_ = false;
}