void IndexMapBiDi::Init(int size, bool all_mapped) {
  if (!all_mapped) {
    sparse_map_.clear();
  }
  sparse_map_.resize(size, -1);
  if (all_mapped) {
    for (int i = 0; i < size; ++i) {
      sparse_map_[i] = i;
    }
  }
}