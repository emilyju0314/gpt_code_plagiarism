void TessdataManager::Directory() const {
  tprintf("Version:%s\n", VersionString().c_str());
  auto offset = TESSDATA_NUM_ENTRIES * sizeof(int64_t);
  for (unsigned i = 0; i < TESSDATA_NUM_ENTRIES; ++i) {
    if (!entries_[i].empty()) {
      tprintf("%u:%s:size=%zu, offset=%zu\n", i, kTessdataFileSuffixes[i], entries_[i].size(),
              offset);
      offset += entries_[i].size();
    }
  }
}