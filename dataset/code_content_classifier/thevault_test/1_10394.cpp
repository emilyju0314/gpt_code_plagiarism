void Classify::NormalizeOutlines(LIST Outlines, float *XScale, float *YScale) {
  MFOUTLINE Outline;

  switch (classify_norm_method) {
    case character:
      ASSERT_HOST(!"How did NormalizeOutlines get called in character mode?");
      break;

    case baseline:
      iterate(Outlines) {
        Outline = static_cast<MFOUTLINE>(Outlines->first_node());
        NormalizeOutline(Outline, 0.0);
      }
      *XScale = *YScale = MF_SCALE_FACTOR;
      break;
  }