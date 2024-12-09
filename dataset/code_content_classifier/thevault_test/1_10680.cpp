INT_FEATURE_STRUCT IntFeatureSpace::PositionFromBuckets(int x, int y, int theta) const {
  INT_FEATURE_STRUCT pos((x * kIntFeatureExtent + kIntFeatureExtent / 2) / x_buckets_,
                         (y * kIntFeatureExtent + kIntFeatureExtent / 2) / y_buckets_,
                         DivRounded(theta * kIntFeatureExtent, theta_buckets_));
  return pos;
}