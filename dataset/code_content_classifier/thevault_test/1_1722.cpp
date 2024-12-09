bool HostTable::Save(const char* path) const {
  FILE* file = fopen(path, "wb");
  if (file == NULL) return false;

  // Write hashtable entry to file.
  HashTable::const_iterator itr = hosts_.begin();
  for (; itr != hosts_.end(); ++itr) {
    if (fwrite(&(itr->second), sizeof(HostInfo), 1, file) != 1) {
      fclose(file);
      return false;
    }
  }

  fclose(file);
  return true;
}