bool QSPLINE::overlap( // test overlap
    QSPLINE *spline2,  // 2 cannot be smaller
    double fraction    // by more than this
) {
  int leftlimit = xcoords[1];             /*common left limit */
  int rightlimit = xcoords[segments - 1]; /*common right limit */
                                          /*or too non-overlap */
  return !(spline2->segments < 3 ||
           spline2->xcoords[1] > leftlimit + fraction * (rightlimit - leftlimit) ||
           spline2->xcoords[spline2->segments - 1] <
               rightlimit - fraction * (rightlimit - leftlimit));
}