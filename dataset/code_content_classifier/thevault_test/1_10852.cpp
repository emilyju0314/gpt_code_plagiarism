void SEAM::UndoSeam(TBLOB *blob, TBLOB *other_blob) const {
  if (blob->outlines == nullptr) {
    blob->outlines = other_blob->outlines;
    other_blob->outlines = nullptr;
  }

  TESSLINE *outline = blob->outlines;
  while (outline->next) {
    outline = outline->next;
  }
  outline->next = other_blob->outlines;
  other_blob->outlines = nullptr;
  delete other_blob;

  for (int s = 0; s < num_splits_; ++s) {
    splits_[s].UnsplitOutlineList(blob);
  }
  blob->ComputeBoundingBoxes();
  blob->EliminateDuplicateOutlines();
}