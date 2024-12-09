AsteriskFilter::AsteriskFilter(const std::string& pattern) {
  std::vector<std::string> patterns;

  // If the first character is "*", an empty pattern should be put at first.
  // This is for convenience of matching, PatternFinder always use the first
  // pattern to match the beginning of string.
  // For example, "*hello**world" could be viewed as:
  // "[EMPTY_STRING][ANY_STRING][hello][ANY_STRING][world]
  if (pattern.length() > 0 && pattern[0] == '*') {
    patterns.push_back("");
  }

  // Split pattern according to "*". Duplicated "*" is ignored.
  for (int i = 0, len = static_cast<int>(pattern.length()); i < len; ) {
    while (i < len && pattern[i] == '*') ++i;
    int j = i + 1;
    while (j < len && pattern[j] != '*') ++j;
    patterns.push_back(pattern.substr(i, j - i));
    i = j;
  }

  // Check whether the last character is "*".
  if (pattern.length() > 0 && pattern[pattern.length() - 1] == '*') {
    patterns.push_back("");
  }

  finder_ = new PatternFinder(patterns);
}