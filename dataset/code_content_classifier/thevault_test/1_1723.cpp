bool HostTable::Load(const char* path) {
  FILE* file = fopen(path, "rb");
  if (file == NULL) return false;

  // Clear previous records first.
  Clear();

  // Read hostinfo from file and inserted it into hashtable.
  HostInfo info;
  while (fread(&info, sizeof(HostInfo), 1, file) == 1) {
    VisitHost(info.name, info.visit_count);
  }

  fclose(file);
  return true;
}