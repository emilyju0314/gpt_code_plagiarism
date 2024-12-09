MICROFEATURES BlobMicroFeatures(TBLOB *Blob, const DENORM &cn_denorm) {
  MICROFEATURES MicroFeatures;
  LIST Outlines;
  LIST RemainingOutlines;

  if (Blob != nullptr) {
    Outlines = ConvertBlob(Blob);

    RemainingOutlines = Outlines;
    iterate(RemainingOutlines) {
      auto Outline = static_cast<MFOUTLINE>(RemainingOutlines->first_node());
      CharNormalizeOutline(Outline, cn_denorm);
    }

    RemainingOutlines = Outlines;
    iterate(RemainingOutlines) {
      auto Outline = static_cast<MFOUTLINE>(RemainingOutlines->first_node());
      FindDirectionChanges(Outline, classify_min_slope, classify_max_slope);
      MarkDirectionChanges(Outline);
      MicroFeatures = ConvertToMicroFeatures(Outline, MicroFeatures);
    }
    FreeOutlines(Outlines);
  }
  return MicroFeatures;
}