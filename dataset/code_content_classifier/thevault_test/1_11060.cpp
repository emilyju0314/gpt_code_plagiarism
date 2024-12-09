void QSPLINE::extrapolate( // linear extrapolation
    double gradient,       // gradient to use
    int xmin,              // new left edge
    int xmax               // new right edge
) {
  int segment;        /*current segment of spline */
  int dest_segment;   // dest index
  int32_t *xstarts;   // new boundaries
  QUAD_COEFFS *quads; // new ones
  int increment;      // in size

  increment = xmin < xcoords[0] ? 1 : 0;
  if (xmax > xcoords[segments]) {
    increment++;
  }
  if (increment == 0) {
    return;
  }
  xstarts = new int32_t[segments + 1 + increment];
  quads = new QUAD_COEFFS[segments + increment];
  if (xmin < xcoords[0]) {
    xstarts[0] = xmin;
    quads[0].a = 0;
    quads[0].b = gradient;
    quads[0].c = y(xcoords[0]) - quads[0].b * xcoords[0];
    dest_segment = 1;
  } else {
    dest_segment = 0;
  }
  for (segment = 0; segment < segments; segment++) {
    xstarts[dest_segment] = xcoords[segment];
    quads[dest_segment] = quadratics[segment];
    dest_segment++;
  }
  xstarts[dest_segment] = xcoords[segment];
  if (xmax > xcoords[segments]) {
    quads[dest_segment].a = 0;
    quads[dest_segment].b = gradient;
    quads[dest_segment].c = y(xcoords[segments]) - quads[dest_segment].b * xcoords[segments];
    dest_segment++;
    xstarts[dest_segment] = xmax + 1;
  }
  segments = dest_segment;
  delete[] xcoords;
  delete[] quadratics;
  xcoords = xstarts;
  quadratics = quads;
}