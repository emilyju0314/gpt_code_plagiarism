bool TessdataManager::LoadMemBuffer(const char *name, const char *data, int size) {
  // TODO: This method supports only the proprietary file format.
  Clear();
  data_file_name_ = name;
  TFile fp;
  fp.Open(data, size);
  uint32_t num_entries;
  if (!fp.DeSerialize(&num_entries)) {
    return false;
  }
  swap_ = num_entries > kMaxNumTessdataEntries;
  fp.set_swap(swap_);
  if (swap_) {
    ReverseN(&num_entries, sizeof(num_entries));
  }
  if (num_entries > kMaxNumTessdataEntries) {
    return false;
  }
  // TODO: optimize (no init required).
  std::vector<int64_t> offset_table(num_entries);
  if (!fp.DeSerialize(&offset_table[0], num_entries)) {
    return false;
  }
  for (unsigned i = 0; i < num_entries && i < TESSDATA_NUM_ENTRIES; ++i) {
    if (offset_table[i] >= 0) {
      int64_t entry_size = size - offset_table[i];
      unsigned j = i + 1;
      while (j < num_entries && offset_table[j] == -1) {
        ++j;
      }
      if (j < num_entries) {
        entry_size = offset_table[j] - offset_table[i];
      }
      entries_[i].resize(entry_size);
      if (!fp.DeSerialize(&entries_[i][0], entry_size)) {
        return false;
      }
    }
  }
  if (entries_[TESSDATA_VERSION].empty()) {
    SetVersionString("Pre-4.0.0");
  }
  is_loaded_ = true;
  return true;
}