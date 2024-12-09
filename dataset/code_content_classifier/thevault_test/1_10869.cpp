bool TPOINT::IsCrossed(const TPOINT &a0, const TPOINT &a1, const TPOINT &b0, const TPOINT &b1) {
  TPOINT b0a1, b0a0, a1b1, b0b1, a1a0;

  b0a1.x = a1.x - b0.x;
  b0a0.x = a0.x - b0.x;
  a1b1.x = b1.x - a1.x;
  b0b1.x = b1.x - b0.x;
  a1a0.x = a0.x - a1.x;
  b0a1.y = a1.y - b0.y;
  b0a0.y = a0.y - b0.y;
  a1b1.y = b1.y - a1.y;
  b0b1.y = b1.y - b0.y;
  a1a0.y = a0.y - a1.y;

  int b0a1xb0b1 = b0a1.cross(b0b1);
  int b0b1xb0a0 = b0b1.cross(b0a0);
  int a1b1xa1a0 = a1b1.cross(a1a0);
  // For clarity, we want a1a0.cross(a1b0) here but we have b0a1 instead of a1b0
  // so use -a1b0.cross(b0a1) instead, which is the same.
  int a1a0xa1b0 = -a1a0.cross(b0a1);

  return ((b0a1xb0b1 > 0 && b0b1xb0a0 > 0) || (b0a1xb0b1 < 0 && b0b1xb0a0 < 0)) &&
         ((a1b1xa1a0 > 0 && a1a0xa1b0 > 0) || (a1b1xa1a0 < 0 && a1a0xa1b0 < 0));
}