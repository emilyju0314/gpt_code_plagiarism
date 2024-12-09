MFOUTLINE NextDirectionChange(MFOUTLINE EdgePoint) {
  DIRECTION InitialDirection;

  InitialDirection = PointAt(EdgePoint)->Direction;

  MFOUTLINE next_pt = nullptr;
  do {
    EdgePoint = NextPointAfter(EdgePoint);
    next_pt = NextPointAfter(EdgePoint);
  } while (PointAt(EdgePoint)->Direction == InitialDirection && !PointAt(EdgePoint)->Hidden &&
           next_pt != nullptr && !PointAt(next_pt)->Hidden);

  return (EdgePoint);
}