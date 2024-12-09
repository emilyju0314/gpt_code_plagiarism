QSPLINE::QSPLINE(               // constructor
    int xstarts[],              // spline boundaries
    int segcount,               // no of segments
    int xpts[],                 // points to fit
    int ypts[], int pointcount, // no of pts
    int degree                  // fit required
) {
  int pointindex;    /*no along text line */
  int segment;       /*segment no */
  int32_t *ptcounts; // no in each segment
  QLSQ qlsq;         /*accumulator */

  segments = segcount;
  xcoords = new int32_t[segcount + 1];
  ptcounts = new int32_t[segcount + 1];
  quadratics = new QUAD_COEFFS[segcount];
  memmove(xcoords, xstarts, (segcount + 1) * sizeof(int32_t));
  ptcounts[0] = 0; /*none in any yet */
  for (segment = 0, pointindex = 0; pointindex < pointcount; pointindex++) {
    while (segment < segcount && xpts[pointindex] >= xstarts[segment]) {
      segment++; /*try next segment */
                 /*cumulative counts */
      ptcounts[segment] = ptcounts[segment - 1];
    }
    ptcounts[segment]++; /*no in previous partition */
  }
  while (segment < segcount) {
    segment++;
    /*zero the rest */
    ptcounts[segment] = ptcounts[segment - 1];
  }

  for (segment = 0; segment < segcount; segment++) {
    qlsq.clear();
    /*first blob */
    pointindex = ptcounts[segment];
    if (pointindex > 0 && xpts[pointindex] != xpts[pointindex - 1] &&
        xpts[pointindex] != xstarts[segment]) {
      qlsq.add(xstarts[segment],
               ypts[pointindex - 1] + (ypts[pointindex] - ypts[pointindex - 1]) *
                                          (xstarts[segment] - xpts[pointindex - 1]) /
                                          (xpts[pointindex] - xpts[pointindex - 1]));
    }
    for (; pointindex < ptcounts[segment + 1]; pointindex++) {
      qlsq.add(xpts[pointindex], ypts[pointindex]);
    }
    if (pointindex > 0 && pointindex < pointcount && xpts[pointindex] != xstarts[segment + 1]) {
      qlsq.add(xstarts[segment + 1],
               ypts[pointindex - 1] + (ypts[pointindex] - ypts[pointindex - 1]) *
                                          (xstarts[segment + 1] - xpts[pointindex - 1]) /
                                          (xpts[pointindex] - xpts[pointindex - 1]));
    }
    qlsq.fit(degree);
    quadratics[segment].a = qlsq.get_a();
    quadratics[segment].b = qlsq.get_b();
    quadratics[segment].c = qlsq.get_c();
  }
  delete[] ptcounts;
}