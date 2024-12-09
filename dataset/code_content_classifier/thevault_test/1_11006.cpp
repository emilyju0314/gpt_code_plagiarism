bool WERD_RES::PiecesAllNatural(int start, int count) const {
  // all seams must have no splits.
  for (int index = start; index < start + count - 1; ++index) {
    if (index >= 0 && static_cast<size_t>(index) < seam_array.size()) {
      SEAM *seam = seam_array[index];
      if (seam != nullptr && seam->HasAnySplits()) {
        return false;
      }
    }
  }
  return true;
}