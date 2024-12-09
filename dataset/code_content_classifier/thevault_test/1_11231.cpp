std::string CHAR_FRAGMENT::to_string(const char *unichar, int pos, int total,
                                     bool natural) {
  if (total == 1) {
    return std::string(unichar);
  }
  std::string result;
  result += kSeparator;
  result += unichar;
  char buffer[kMaxLen];
  snprintf(buffer, kMaxLen, "%c%d%c%d", kSeparator, pos,
           natural ? kNaturalFlag : kSeparator, total);
  result += buffer;
  return result;
}