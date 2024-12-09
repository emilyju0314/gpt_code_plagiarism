void AppendVersion(int version_number, bool version_es, std::string *result) {
  std::string version_string = flatbuffers::NumToString(version_number);
  if (version_es) {
    version_string.append(" es");
  }
  AppendVersion(version_string.c_str(), result);
}