int IntFeatureSpace::XYToFeatureIndex(int x, int y) const {
  // Round the x,y position to a feature. Search for a valid theta.
  INT_FEATURE_STRUCT feature(x, y, 0);
  int index = -1;
  for (int theta = 0; theta <= UINT8_MAX && index < 0; ++theta) {
    feature.Theta = theta;
    index = Index(feature);
  }
  if (index < 0) {
    tprintf("(%d,%d) does not exist in feature space!\n", x, y);
    return -1;
  }
  feature = PositionFromIndex(index);
  tprintf("Click at (%d, %d) ->(%d, %d), ->(%d, %d)\n", x, y, feature.X, feature.Y, x - feature.X,
          y - feature.Y);
  // Get the relative position of x,y from the rounded feature.
  x -= feature.X;
  y -= feature.Y;
  if (x != 0 || y != 0) {
    double angle = atan2(static_cast<double>(y), static_cast<double>(x)) + M_PI;
    angle *= kIntFeatureExtent / (2.0 * M_PI);
    feature.Theta = static_cast<uint8_t>(angle + 0.5);
    index = Index(feature);
    if (index < 0) {
      tprintf("Feature failed to map to a valid index:");
      feature.print();
      return -1;
    }
    feature = PositionFromIndex(index);
  }
  feature.print();
  return index;
}