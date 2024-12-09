FEATURE_SET Classify::ExtractPicoFeatures(TBLOB *Blob) {
  auto FeatureSet = new FEATURE_SET_STRUCT(MAX_PICO_FEATURES);
  auto Outlines = ConvertBlob(Blob);
  float XScale, YScale;
  NormalizeOutlines(Outlines, &XScale, &YScale);
  auto RemainingOutlines = Outlines;
  iterate(RemainingOutlines) {
    auto Outline = static_cast<MFOUTLINE>(RemainingOutlines->first_node());
    ConvertToPicoFeatures2(Outline, FeatureSet);
  }
  if (classify_norm_method == baseline) {
    NormalizePicoX(FeatureSet);
  }
  FreeOutlines(Outlines);
  return (FeatureSet);

}