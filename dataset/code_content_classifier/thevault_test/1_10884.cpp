void TBLOB::Rotate(const FCOORD rotation) {
  for (TESSLINE *outline = outlines; outline != nullptr; outline = outline->next) {
    outline->Rotate(rotation);
  }
}