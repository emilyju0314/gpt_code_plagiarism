static void SegmentLLSQ(const FCOORD &pt1, const FCOORD &pt2, LLSQ *accumulator) {
  FCOORD step(pt2);
  step -= pt1;
  int xstart = IntCastRounded(std::min(pt1.x(), pt2.x()));
  int xend = IntCastRounded(std::max(pt1.x(), pt2.x()));
  int ystart = IntCastRounded(std::min(pt1.y(), pt2.y()));
  int yend = IntCastRounded(std::max(pt1.y(), pt2.y()));
  if (xstart == xend && ystart == yend) {
    return; // Nothing to do.
  }
  double weight = step.length() / (xend - xstart + yend - ystart);
  // Compute and save the y-position at the middle of each x-step.
  for (int x = xstart; x < xend; ++x) {
    double y = pt1.y() + step.y() * (x + 0.5 - pt1.x()) / step.x();
    accumulator->add(x + 0.5, y, weight);
  }
  // Compute and save the x-position at the middle of each y-step.
  for (int y = ystart; y < yend; ++y) {
    double x = pt1.x() + step.x() * (y + 0.5 - pt1.y()) / step.y();
    accumulator->add(x, y + 0.5, weight);
  }
}