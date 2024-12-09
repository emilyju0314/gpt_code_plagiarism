void IndexMapBiDi::Setup() {
  int compact_size = 0;
  for (int &i : sparse_map_) {
    if (i >= 0) {
      i = compact_size++;
    }
  }
  compact_map_.clear();
  compact_map_.resize(compact_size, -1);
  for (size_t i = 0; i < sparse_map_.size(); ++i) {
    if (sparse_map_[i] >= 0) {
      compact_map_[sparse_map_[i]] = i;
    }
  }
  sparse_size_ = sparse_map_.size();
}