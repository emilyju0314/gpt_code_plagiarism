void ConvertSegmentToPicoFeat(FPOINT *Start, FPOINT *End, FEATURE_SET FeatureSet) {
  float Angle;
  float Length;
  int NumFeatures;
  FPOINT Center;
  FPOINT Delta;
  int i;

  Angle = NormalizedAngleFrom(Start, End, 1.0);
  Length = DistanceBetween(*Start, *End);
  NumFeatures = static_cast<int>(floor(Length / classify_pico_feature_length + 0.5));
  if (NumFeatures < 1) {
    NumFeatures = 1;
  }

  /* compute vector for one pico feature */
  Delta.x = XDelta(*Start, *End) / NumFeatures;
  Delta.y = YDelta(*Start, *End) / NumFeatures;

  /* compute position of first pico feature */
  Center.x = Start->x + Delta.x / 2.0;
  Center.y = Start->y + Delta.y / 2.0;

  /* compute each pico feature in segment and add to feature set */
  for (i = 0; i < NumFeatures; i++) {
    auto Feature = new FEATURE_STRUCT(&PicoFeatDesc);
    Feature->Params[PicoFeatDir] = Angle;
    Feature->Params[PicoFeatX] = Center.x;
    Feature->Params[PicoFeatY] = Center.y;
    AddFeature(FeatureSet, Feature);

    Center.x += Delta.x;
    Center.y += Delta.y;
  }
}