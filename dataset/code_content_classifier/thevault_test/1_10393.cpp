void NormalizeOutline(MFOUTLINE Outline, float XOrigin) {
  if (Outline == NIL_LIST) {
    return;
  }

  MFOUTLINE EdgePoint = Outline;
  do {
    MFEDGEPT *Current = PointAt(EdgePoint);
    Current->Point.y = MF_SCALE_FACTOR * (Current->Point.y - kBlnBaselineOffset);
    Current->Point.x = MF_SCALE_FACTOR * (Current->Point.x - XOrigin);
    EdgePoint = NextPointAfter(EdgePoint);
  } while (EdgePoint != Outline);
}