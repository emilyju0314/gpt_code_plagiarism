float NormalizedAngleFrom(FPOINT *Point1, FPOINT *Point2, float FullScale) {
  float NumRadsInCircle = 2.0 * M_PI;

  float Angle = AngleFrom(*Point1, *Point2);
  if (Angle < 0.0) {
    Angle += NumRadsInCircle;
  }
  Angle *= FullScale / NumRadsInCircle;
  if (Angle < 0.0 || Angle >= FullScale) {
    Angle = 0.0;
  }
  return (Angle);
}