bool ValidCharDescription(const FEATURE_DEFS_STRUCT &FeatureDefs, CHAR_DESC_STRUCT *CharDesc) {
  bool anything_written = false;
  bool well_formed = true;
  for (size_t Type = 0; Type < CharDesc->NumFeatureSets; Type++) {
    if (CharDesc->FeatureSets[Type]) {
      for (int i = 0; i < CharDesc->FeatureSets[Type]->NumFeatures; i++) {
        FEATURE feat = CharDesc->FeatureSets[Type]->Features[i];
        for (int p = 0; p < feat->Type->NumParams; p++) {
          if (std::isnan(feat->Params[p]) || std::isinf(feat->Params[p])) {
            well_formed = false;
          } else {
            anything_written = true;
          }
        }
      }
    } else {
      return false;
    }
  }
  return anything_written && well_formed;
}