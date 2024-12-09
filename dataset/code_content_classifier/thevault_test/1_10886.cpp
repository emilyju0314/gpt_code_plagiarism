void TBLOB::Scale(float factor) {
  for (TESSLINE *outline = outlines; outline != nullptr; outline = outline->next) {
    outline->Scale(factor);
  }
}