void QSPLINE::move( // reposition spline
    ICOORD vec      // by vector
) {
  int32_t segment; // index of segment
  int16_t x_shift = vec.x();

  for (segment = 0; segment < segments; segment++) {
    xcoords[segment] += x_shift;
    quadratics[segment].move(vec);
  }
  xcoords[segment] += x_shift;
}