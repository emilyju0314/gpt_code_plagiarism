void IntFeatureDist::Set(const std::vector<int> &indexed_features, int canonical_count,
                         bool value) {
  total_feature_weight_ = canonical_count;
  for (int f : indexed_features) {
    features_[f] = value;
    for (int dir = -kNumOffsetMaps; dir <= kNumOffsetMaps; ++dir) {
      if (dir == 0) {
        continue;
      }
      const int mapped_f = feature_map_->OffsetFeature(f, dir);
      if (mapped_f >= 0) {
        features_delta_one_[mapped_f] = value;
        for (int dir2 = -kNumOffsetMaps; dir2 <= kNumOffsetMaps; ++dir2) {
          if (dir2 == 0) {
            continue;
          }
          const int mapped_f2 = feature_map_->OffsetFeature(mapped_f, dir2);
          if (mapped_f2 >= 0) {
            features_delta_two_[mapped_f2] = value;
          }
        }
      }
    }
  }
}