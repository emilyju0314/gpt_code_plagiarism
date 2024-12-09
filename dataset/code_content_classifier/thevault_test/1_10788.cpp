int TextlineProjection::BestMeanGradientInColumn(const DENORM *denorm, int16_t x, int16_t min_y,
                                                 int16_t max_y, bool best_is_max) const {
  TPOINT start_pt(x, min_y);
  TPOINT end_pt(x, max_y);
  int left = MeanPixelsInLineSegment(denorm, -2, start_pt, end_pt);
  int right = MeanPixelsInLineSegment(denorm, 2, start_pt, end_pt);
  int best_gradient = right - left;
  left = MeanPixelsInLineSegment(denorm, -1, start_pt, end_pt);
  right = MeanPixelsInLineSegment(denorm, 3, start_pt, end_pt);
  int gradient = right - left;
  if ((gradient > best_gradient) == best_is_max) {
    best_gradient = gradient;
  }
  left = MeanPixelsInLineSegment(denorm, -3, start_pt, end_pt);
  right = MeanPixelsInLineSegment(denorm, 1, start_pt, end_pt);
  gradient = right - left;
  if ((gradient > best_gradient) == best_is_max) {
    best_gradient = gradient;
  }
  return best_gradient;
}