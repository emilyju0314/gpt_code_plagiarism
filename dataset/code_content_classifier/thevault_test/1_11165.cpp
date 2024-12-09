void TessdataManager::Serialize(std::vector<char> *data) const {
  // TODO: This method supports only the proprietary file format.
  ASSERT_HOST(is_loaded_);
  // Compute the offset_table and total size.
  int64_t offset_table[TESSDATA_NUM_ENTRIES];
  int64_t offset = sizeof(int32_t) + sizeof(offset_table);
  for (unsigned i = 0; i < TESSDATA_NUM_ENTRIES; ++i) {
    if (entries_[i].empty()) {
      offset_table[i] = -1;
    } else {
      offset_table[i] = offset;
      offset += entries_[i].size();
    }
  }
  data->resize(offset, 0);
  int32_t num_entries = TESSDATA_NUM_ENTRIES;
  TFile fp;
  fp.OpenWrite(data);
  fp.Serialize(&num_entries);
  fp.Serialize(&offset_table[0], countof(offset_table));
  for (const auto &entry : entries_) {
    if (!entry.empty()) {
      fp.Serialize(&entry[0], entry.size());
    }
  }
}