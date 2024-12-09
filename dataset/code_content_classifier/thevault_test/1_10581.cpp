int IndexMapBiDi::MapFeatures(const std::vector<int> &sparse, std::vector<int> *compact) const {
  compact->clear();
  int num_features = sparse.size();
  int missed_features = 0;
  int prev_good_feature = -1;
  for (int f = 0; f < num_features; ++f) {
    int feature = sparse_map_[sparse[f]];
    if (feature >= 0) {
      if (feature != prev_good_feature) {
        compact->push_back(feature);
        prev_good_feature = feature;
      }
    } else {
      ++missed_features;
    }
  }
  return missed_features;
}