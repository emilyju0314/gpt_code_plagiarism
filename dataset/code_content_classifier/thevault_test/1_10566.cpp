void IntFeatureMap::Init(const IntFeatureSpace &feature_space) {
  feature_space_ = feature_space;
  mapping_changed_ = false;
  int sparse_size = feature_space_.Size();
  feature_map_.Init(sparse_size, true);
  feature_map_.Setup();
  compact_size_ = feature_map_.CompactSize();
  // Initialize look-up tables if needed.
  FCOORD dir = FeatureDirection(0);
  if (dir.x() == 0.0f && dir.y() == 0.0f) {
    InitIntegerFX();
  }
  // Compute look-up tables to generate offset features.
  for (int dir = 0; dir < kNumOffsetMaps; ++dir) {
    delete[] offset_plus_[dir];
    delete[] offset_minus_[dir];
    offset_plus_[dir] = new int[sparse_size];
    offset_minus_[dir] = new int[sparse_size];
  }
  for (int dir = 1; dir <= kNumOffsetMaps; ++dir) {
    for (int i = 0; i < sparse_size; ++i) {
      int offset_index = ComputeOffsetFeature(i, dir);
      offset_plus_[dir - 1][i] = offset_index;
      offset_index = ComputeOffsetFeature(i, -dir);
      offset_minus_[dir - 1][i] = offset_index;
    }
  }
}