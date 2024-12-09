LIST ConvertOutlines(TESSLINE *outline, LIST mf_outlines, OUTLINETYPE outline_type) {
  MFOUTLINE mf_outline;

  while (outline != nullptr) {
    mf_outline = ConvertOutline(outline);
    if (mf_outline != nullptr) {
      mf_outlines = push(mf_outlines, mf_outline);
    }
    outline = outline->next;
  }
  return mf_outlines;
}