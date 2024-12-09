std::string SkipVersion(const std::string& str) {
  // Version is expected to be at the beginning of the string.
  if (str.compare(0, 8, "#version") == 0) {
    return str.substr(str.find('\n') + 1);
  }
  return str;
}