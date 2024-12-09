void TWERD::MergeBlobs(unsigned start, unsigned end) {
  if (end > blobs.size()) {
    end = blobs.size();
  }
  if (start >= end) {
    return; // Nothing to do.
  }
  TESSLINE *outline = blobs[start]->outlines;
  for (auto i = start + 1; i < end; ++i) {
    TBLOB *next_blob = blobs[i];
    // Take the outlines from the next blob.
    if (outline == nullptr) {
      blobs[start]->outlines = next_blob->outlines;
      outline = blobs[start]->outlines;
    } else {
      while (outline->next != nullptr) {
        outline = outline->next;
      }
      outline->next = next_blob->outlines;
      next_blob->outlines = nullptr;
    }
    // Delete the next blob and move on.
    delete next_blob;
    blobs[i] = nullptr;
  }
  // Remove dead blobs from the vector.
  // TODO: optimize.
  for (auto i = start + 1; i < end && start + 1 < blobs.size(); ++i) {
    blobs.erase(blobs.begin() + start + 1);
  }
}