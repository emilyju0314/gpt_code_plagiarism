void SEAM::ApplySeam(bool italic_blob, TBLOB *blob, TBLOB *other_blob) const {
  for (int s = 0; s < num_splits_; ++s) {
    splits_[s].SplitOutlineList(blob->outlines);
  }
  blob->ComputeBoundingBoxes();

  divide_blobs(blob, other_blob, italic_blob, location_);

  blob->EliminateDuplicateOutlines();
  other_blob->EliminateDuplicateOutlines();

  blob->CorrectBlobOrder(other_blob);
}