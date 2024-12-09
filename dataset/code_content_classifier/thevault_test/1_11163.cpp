void TessdataManager::OverwriteEntry(TessdataType type, const char *data, int size) {
  is_loaded_ = true;
  entries_[type].resize(size);
  memcpy(&entries_[type][0], data, size);
}