bool SaveDataToFile(const std::vector<char> &data, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == nullptr) {
    return false;
  }
  bool result = fwrite(&data[0], 1, data.size(), fp) == data.size();
  fclose(fp);
  return result;
}