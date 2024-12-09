int IndexMap::SparseToCompact(int sparse_index) const {
  auto pos = std::upper_bound(compact_map_.begin(), compact_map_.end(), sparse_index);
  if (pos > compact_map_.begin()) {
    --pos;
  }
  auto result = pos - compact_map_.begin();
  return compact_map_[result] == sparse_index ? result : -1;
}