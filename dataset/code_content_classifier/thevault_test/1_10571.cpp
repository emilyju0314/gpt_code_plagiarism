int IntFeatureMap::ComputeOffsetFeature(int index_feature, int dir) const {
  INT_FEATURE_STRUCT f = InverseIndexFeature(index_feature);
  ASSERT_HOST(IndexFeature(f) == index_feature);
  if (dir == 0) {
    return index_feature;
  } else if (dir == 1 || dir == -1) {
    FCOORD feature_dir = FeatureDirection(f.Theta);
    FCOORD rotation90(0.0f, 1.0f);
    feature_dir.rotate(rotation90);
    // Find the nearest existing feature.
    for (int m = 1; m < kMaxOffsetDist; ++m) {
      double x_pos = f.X + feature_dir.x() * (m * dir);
      double y_pos = f.Y + feature_dir.y() * (m * dir);
      int x = IntCastRounded(x_pos);
      int y = IntCastRounded(y_pos);
      if (x >= 0 && x <= UINT8_MAX && y >= 0 && y <= UINT8_MAX) {
        INT_FEATURE_STRUCT offset_f;
        offset_f.X = x;
        offset_f.Y = y;
        offset_f.Theta = f.Theta;
        int offset_index = IndexFeature(offset_f);
        if (offset_index != index_feature && offset_index >= 0) {
          return offset_index; // Found one.
        }
      } else {
        return -1; // Hit the edge of feature space.
      }
    }
  } else if (dir == 2 || dir == -2) {
    // Find the nearest existing index_feature.
    for (int m = 1; m < kMaxOffsetDist; ++m) {
      int theta = f.Theta + m * dir / 2;
      INT_FEATURE_STRUCT offset_f;
      offset_f.X = f.X;
      offset_f.Y = f.Y;
      offset_f.Theta = Modulo(theta, 256);
      int offset_index = IndexFeature(offset_f);
      if (offset_index != index_feature && offset_index >= 0) {
        return offset_index; // Found one.
      }
    }
  }
  return -1; // Nothing within the max distance.
}