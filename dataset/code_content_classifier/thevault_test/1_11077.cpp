void IntFeatureDist::Init(const IntFeatureMap *feature_map) {
  size_ = feature_map->sparse_size();
  Clear();
  feature_map_ = feature_map;
  features_ = new bool[size_];
  features_delta_one_ = new bool[size_];
  features_delta_two_ = new bool[size_];
  memset(features_, false, size_ * sizeof(features_[0]));
  memset(features_delta_one_, false, size_ * sizeof(features_delta_one_[0]));
  memset(features_delta_two_, false, size_ * sizeof(features_delta_two_[0]));
  total_feature_weight_ = 0.0;
}