bool IndexMapBiDi::DeSerialize(bool swap, FILE *fp) {
  if (!IndexMap::DeSerialize(swap, fp)) {
    return false;
  }
  std::vector<int32_t> remaining_pairs;
  if (!tesseract::DeSerialize(swap, fp, remaining_pairs)) {
    return false;
  }
  sparse_map_.clear();
  sparse_map_.resize(sparse_size_, -1);
  for (unsigned i = 0; i < compact_map_.size(); ++i) {
    sparse_map_[compact_map_[i]] = i;
  }
  for (size_t i = 0; i < remaining_pairs.size(); ++i) {
    int sparse_index = remaining_pairs[i++];
    sparse_map_[sparse_index] = remaining_pairs[i];
  }
  return true;
}