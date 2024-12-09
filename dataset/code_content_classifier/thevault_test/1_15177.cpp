static string elideQuote(const string &s, size_t thresh, size_t prefix,
                         size_t suffix) {
  if (s.size() < thresh) return s;
  size_t i = 0;
  while (i < prefix) {
    if (s[i] == '\\' && '0' <= s[i + 1] && s[i + 1] <= '7')
      i += 4;  // skip octal escape
    else if (s[i] == '\\')
      i += 2;  // skip other escape
    else
      i++;
  }
  prefix = i;
  size_t j = i;
  while (s.size() - i >= suffix) {
    j = i;
    if (s[i] == '\\' && '0' <= s[i + 1] && s[i + 1] <= '7')
      i += 4;  // skip octal escape
    else if (s[i] == '\\')
      i += 2;  // skip other escape
    else
      i++;
  }
  suffix = j;
  return s.substr(0, prefix) + "..." + s.substr(suffix);
}