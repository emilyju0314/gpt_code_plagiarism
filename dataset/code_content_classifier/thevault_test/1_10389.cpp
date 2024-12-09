void FindDirectionChanges(MFOUTLINE Outline, float MinSlope, float MaxSlope) {
  MFEDGEPT *Current;
  MFEDGEPT *Last;
  MFOUTLINE EdgePoint;

  if (DegenerateOutline(Outline)) {
    return;
  }

  Last = PointAt(Outline);
  Outline = NextPointAfter(Outline);
  EdgePoint = Outline;
  do {
    Current = PointAt(EdgePoint);
    ComputeDirection(Last, Current, MinSlope, MaxSlope);

    Last = Current;
    EdgePoint = NextPointAfter(EdgePoint);
  } while (EdgePoint != Outline);

}