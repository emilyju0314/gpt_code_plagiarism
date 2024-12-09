int IntFeatureMap::OffsetFeature(int index_feature, int dir) const {
  if (dir > 0 && dir <= kNumOffsetMaps) {
    return offset_plus_[dir - 1][index_feature];
  } else if (dir < 0 && -dir <= kNumOffsetMaps) {
    return offset_minus_[-dir - 1][index_feature];
  } else if (dir == 0) {
    return index_feature;
  } else {
    return -1;
  }
}