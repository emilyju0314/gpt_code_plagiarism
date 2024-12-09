double QSPLINE::y( // evaluate
    double x       // coord to evaluate at
    ) const {
  int32_t index; // segment index

  index = spline_index(x);
  return quadratics[index].y(x); // in correct segment
}