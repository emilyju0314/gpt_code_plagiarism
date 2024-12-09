QSPLINE::QSPLINE(     // constructor
    int32_t count,    // no of segments
    int32_t *xstarts, // start coords
    double *coeffs    // coefficients
) {
  int32_t index; // segment index

  // get memory
  xcoords = new int32_t[count + 1];
  quadratics = new QUAD_COEFFS[count];
  segments = count;
  for (index = 0; index < segments; index++) {
    // copy them
    xcoords[index] = xstarts[index];
    quadratics[index] =
        QUAD_COEFFS(coeffs[index * 3], coeffs[index * 3 + 1], coeffs[index * 3 + 2]);
  }
  // right edge
  xcoords[index] = xstarts[index];
}