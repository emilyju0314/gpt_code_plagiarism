void TBLOB::Move(const ICOORD vec) {
  for (TESSLINE *outline = outlines; outline != nullptr; outline = outline->next) {
    outline->Move(vec);
  }
}