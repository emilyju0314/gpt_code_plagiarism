void Classify::ComputeIntCharNormArray(const FEATURE_STRUCT &norm_feature,
                                       uint8_t *char_norm_array) {
  for (unsigned i = 0; i < unicharset.size(); i++) {
    if (i < PreTrainedTemplates->NumClasses) {
      int norm_adjust =
          static_cast<int>(INT_CHAR_NORM_RANGE * ComputeNormMatch(i, norm_feature, false));
      char_norm_array[i] = ClipToRange(norm_adjust, 0, MAX_INT_CHAR_NORM);
    } else {
      // Classes with no templates (eg. ambigs & ligatures) default
      // to worst match.
      char_norm_array[i] = MAX_INT_CHAR_NORM;
    }
  }
}