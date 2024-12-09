int TextlineProjection::BestMeanGradientInRow(const DENORM *denorm, int16_t min_x, int16_t max_x,
                                              int16_t y, bool best_is_max) const {
  TPOINT start_pt(min_x, y);
  TPOINT end_pt(max_x, y);
  int upper = MeanPixelsInLineSegment(denorm, -2, start_pt, end_pt);
  int lower = MeanPixelsInLineSegment(denorm, 2, start_pt, end_pt);
  int best_gradient = lower - upper;
  upper = MeanPixelsInLineSegment(denorm, -1, start_pt, end_pt);
  lower = MeanPixelsInLineSegment(denorm, 3, start_pt, end_pt);
  int gradient = lower - upper;
  if ((gradient > best_gradient) == best_is_max) {
    best_gradient = gradient;
  }
  upper = MeanPixelsInLineSegment(denorm, -3, start_pt, end_pt);
  lower = MeanPixelsInLineSegment(denorm, 1, start_pt, end_pt);
  gradient = lower - upper;
  if ((gradient > best_gradient) == best_is_max) {
    best_gradient = gradient;
  }
  return best_gradient;
}