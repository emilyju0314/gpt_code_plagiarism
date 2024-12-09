void TBLOB::CorrectBlobOrder(TBLOB *next) {
  TBOX box = bounding_box();
  TBOX next_box = next->bounding_box();
  if (box.x_middle() > next_box.x_middle()) {
    std::swap(outlines, next->outlines);
  }
}