bool SEAM::PrepareToInsertSeam(const std::vector<SEAM *> &seams,
                               const std::vector<TBLOB *> &blobs, int insert_index, bool modify) {
  for (int s = 0; s < insert_index; ++s) {
    if (!seams[s]->FindBlobWidth(blobs, s, modify)) {
      return false;
    }
  }
  if (!FindBlobWidth(blobs, insert_index, modify)) {
    return false;
  }
  for (unsigned s = insert_index; s < seams.size(); ++s) {
    if (!seams[s]->FindBlobWidth(blobs, s + 1, modify)) {
      return false;
    }
  }
  return true;
}