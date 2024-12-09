bool TessdataManager::SaveFile(const char *filename, FileWriter writer) const {
  // TODO: This method supports only the proprietary file format.
  ASSERT_HOST(is_loaded_);
  std::vector<char> data;
  Serialize(&data);
  if (writer == nullptr) {
    return SaveDataToFile(data, filename);
  } else {
    return (*writer)(data, filename);
  }
}