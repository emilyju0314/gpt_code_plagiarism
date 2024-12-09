int32_t QSPLINE::spline_index( // evaluate
    double x                   // coord to evaluate at
    ) const {
  int32_t index;  // segment index
  int32_t bottom; // bottom of range
  int32_t top;    // top of range

  bottom = 0;
  top = segments;
  while (top - bottom > 1) {
    index = (top + bottom) / 2; // centre of range
    if (x >= xcoords[index]) {
      bottom = index; // new min
    } else {
      top = index; // new max
    }
  }
  return bottom;
}