void TBLOB::ComputeBoundingBoxes() {
  for (TESSLINE *outline = outlines; outline != nullptr; outline = outline->next) {
    outline->ComputeBoundingBox();
  }
}