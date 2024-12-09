int TBLOB::NumOutlines() const {
  int result = 0;
  for (TESSLINE *outline = outlines; outline != nullptr; outline = outline->next) {
    ++result;
  }
  return result;
}