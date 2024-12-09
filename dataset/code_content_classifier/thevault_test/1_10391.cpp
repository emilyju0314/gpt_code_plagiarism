void MarkDirectionChanges(MFOUTLINE Outline) {
  MFOUTLINE Current;
  MFOUTLINE Last;
  MFOUTLINE First;

  if (DegenerateOutline(Outline)) {
    return;
  }

  First = NextDirectionChange(Outline);
  Last = First;
  do {
    Current = NextDirectionChange(Last);
    PointAt(Current)->MarkPoint();
    Last = Current;
  } while (Last != First);

}