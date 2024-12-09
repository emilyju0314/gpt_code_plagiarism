MicroFeature ExtractMicroFeature(MFOUTLINE Start, MFOUTLINE End) {
  MFEDGEPT *P1, *P2;

  P1 = PointAt(Start);
  P2 = PointAt(End);

  MicroFeature NewFeature;
  NewFeature[(int)MicroFeatureParameter::MFXPosition] = AverageOf(P1->Point.x, P2->Point.x);
  NewFeature[(int)MicroFeatureParameter::MFYPosition] = AverageOf(P1->Point.y, P2->Point.y);
  NewFeature[(int)MicroFeatureParameter::MFLength] = DistanceBetween(P1->Point, P2->Point);
  NewFeature[(int)MicroFeatureParameter::MFDirection] = NormalizedAngleFrom(&P1->Point, &P2->Point, 1.0);
  NewFeature[(int)MicroFeatureParameter::MFBulge1] = 0.0f;  // deprecated
  NewFeature[(int)MicroFeatureParameter::MFBulge2] = 0.0f; // deprecated

  return NewFeature;
}