double DetLineFit::ConstrainedFit(double m, float *c) {
  // Do something sensible with no points.
  if (pts_.empty()) {
    *c = 0.0f;
    return 0.0;
  }
  double cos = 1.0 / sqrt(1.0 + m * m);
  FCOORD direction(cos, m * cos);
  ICOORD line_pt;
  double error = ConstrainedFit(direction, -FLT_MAX, FLT_MAX, false, &line_pt);
  *c = line_pt.y() - line_pt.x() * m;
  return error;
}