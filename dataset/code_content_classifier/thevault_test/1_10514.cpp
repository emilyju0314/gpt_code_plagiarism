bool LoadDataFromFile(const char *filename, std::vector<char> *data) {
  bool result = false;
  FILE *fp = fopen(filename, "rb");
  if (fp != nullptr) {
    fseek(fp, 0, SEEK_END);
    auto size = std::ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // Trying to open a directory on Linux sets size to LONG_MAX. Catch it here.
    if (size > 0 && size < LONG_MAX) {
      // reserve an extra byte in case caller wants to append a '\0' character
      data->reserve(size + 1);
      data->resize(size); // TODO: optimize no init
      result = static_cast<long>(fread(&(*data)[0], 1, size, fp)) == size;
    }
    fclose(fp);
  }
  return result;
}