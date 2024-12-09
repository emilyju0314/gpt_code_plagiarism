bool SEAM::FindBlobWidth(const std::vector<TBLOB *> &blobs, int index, bool modify) {
  int num_found = 0;
  if (modify) {
    widthp_ = 0;
    widthn_ = 0;
  }
  for (int s = 0; s < num_splits_; ++s) {
    const SPLIT &split = splits_[s];
    bool found_split = split.ContainedByBlob(*blobs[index]);
    // Look right.
    for (unsigned b = index + 1; !found_split && b < blobs.size(); ++b) {
      found_split = split.ContainedByBlob(*blobs[b]);
      if (found_split && b - index > widthp_ && modify) {
        widthp_ = b - index;
      }
    }
    // Look left.
    for (int b = index - 1; !found_split && b >= 0; --b) {
      found_split = split.ContainedByBlob(*blobs[b]);
      if (found_split && index - b > widthn_ && modify) {
        widthn_ = index - b;
      }
    }
    if (found_split) {
      ++num_found;
    }
  }
  return num_found == num_splits_;
}