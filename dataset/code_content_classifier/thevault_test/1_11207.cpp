uint32_t ShortNameToFeatureType(const FEATURE_DEFS_STRUCT &FeatureDefs, const char *ShortName) {
  for (int i = 0; i < FeatureDefs.NumFeatureTypes; i++) {
    if (!strcmp((FeatureDefs.FeatureDesc[i]->ShortName), ShortName)) {
      return static_cast<uint32_t>(i);
    }
  }
  ASSERT_HOST(!"Illegal short name for a feature");
  return 0;
}