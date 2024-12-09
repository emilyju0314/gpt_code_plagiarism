bool IndexMapBiDi::Serialize(FILE *fp) const {
  if (!IndexMap::Serialize(fp)) {
    return false;
  }
  // Make a vector containing the rest of the map. If the map is many-to-one
  // then each additional sparse entry needs to be stored.
  // Normally we store only the compact map to save space.
  std::vector<int32_t> remaining_pairs;
  for (unsigned i = 0; i < sparse_map_.size(); ++i) {
    if (sparse_map_[i] >= 0 && static_cast<unsigned>(compact_map_[sparse_map_[i]]) != i) {
      remaining_pairs.push_back(i);
      remaining_pairs.push_back(sparse_map_[i]);
    }
  }
  return tesseract::Serialize(fp, remaining_pairs);
}