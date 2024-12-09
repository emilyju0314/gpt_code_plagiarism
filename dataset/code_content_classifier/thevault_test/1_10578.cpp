void IndexMapBiDi::CompleteMerges() {
  // Ensure each sparse_map_entry contains a master compact_map_ index.
  int compact_size = 0;
  for (int &i : sparse_map_) {
    int compact_index = MasterCompactIndex(i);
    i = compact_index;
    if (compact_index >= compact_size) {
      compact_size = compact_index + 1;
    }
  }
  // Re-generate the compact_map leaving holes for unused indices.
  compact_map_.clear();
  compact_map_.resize(compact_size, -1);
  for (size_t i = 0; i < sparse_map_.size(); ++i) {
    if (sparse_map_[i] >= 0) {
      if (compact_map_[sparse_map_[i]] == -1) {
        compact_map_[sparse_map_[i]] = i;
      }
    }
  }
  // Compact the compact_map, leaving tmp_compact_map saying where each
  // index went to in the compacted map.
  std::vector<int32_t> tmp_compact_map(compact_size, -1);
  compact_size = 0;
  for (size_t i = 0; i < compact_map_.size(); ++i) {
    if (compact_map_[i] >= 0) {
      tmp_compact_map[i] = compact_size;
      compact_map_[compact_size++] = compact_map_[i];
    }
  }
  compact_map_.resize(compact_size);
  // Now modify the entries in the sparse map to point to the new locations.
  for (int &i : sparse_map_) {
    if (i >= 0) {
      i = tmp_compact_map[i];
    }
  }
}