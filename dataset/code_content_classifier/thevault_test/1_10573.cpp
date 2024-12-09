bool IndexMap::DeSerialize(bool swap, FILE *fp) {
  uint32_t sparse_size;
  if (!tesseract::DeSerialize(fp, &sparse_size)) {
    return false;
  }
  if (swap) {
    ReverseN(&sparse_size, sizeof(sparse_size));
  }
  // Arbitrarily limit the number of elements to protect against bad data.
  if (sparse_size > UINT16_MAX) {
    return false;
  }
  sparse_size_ = sparse_size;
  return tesseract::DeSerialize(swap, fp, compact_map_);
}