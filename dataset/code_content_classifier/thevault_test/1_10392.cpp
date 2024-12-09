MFOUTLINE NextExtremity(MFOUTLINE EdgePoint) {
  EdgePoint = NextPointAfter(EdgePoint);
  while (!PointAt(EdgePoint)->ExtremityMark) {
    EdgePoint = NextPointAfter(EdgePoint);
  }

  return (EdgePoint);

}