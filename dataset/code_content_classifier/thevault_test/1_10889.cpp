TBOX TBLOB::bounding_box() const {
  if (outlines == nullptr) {
    return TBOX(0, 0, 0, 0);
  }
  TESSLINE *outline = outlines;
  TBOX box = outline->bounding_box();
  for (outline = outline->next; outline != nullptr; outline = outline->next) {
    box += outline->bounding_box();
  }
  return box;
}