void Classify::ComputeIntFeatures(FEATURE_SET Features, INT_FEATURE_ARRAY IntFeatures) {
  float YShift;

  if (classify_norm_method == baseline) {
    YShift = BASELINE_Y_SHIFT;
  } else {
    YShift = Y_SHIFT;
  }

  for (int Fid = 0; Fid < Features->NumFeatures; Fid++) {
    FEATURE Feature = Features->Features[Fid];

    IntFeatures[Fid].X = Bucket8For(Feature->Params[PicoFeatX], X_SHIFT, INT_FEAT_RANGE);
    IntFeatures[Fid].Y = Bucket8For(Feature->Params[PicoFeatY], YShift, INT_FEAT_RANGE);
    IntFeatures[Fid].Theta =
        CircBucketFor(Feature->Params[PicoFeatDir], ANGLE_SHIFT, INT_FEAT_RANGE);
    IntFeatures[Fid].CP_misses = 0;
  }
}