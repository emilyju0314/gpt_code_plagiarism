static bool IsFnmatchPattern(const char* pattern) {
  bool nesting = false;
  for (; *pattern != '\0'; ++pattern) {
    switch (*pattern) {
      // *, ? glob
      case '?':
      case '*':
        return true;

      // [] glob
      case '[':
        nesting = true;
        break;
      case ']':
        if (nesting) return true;
        break;

      // escape chars
      case '\\':
        ++pattern;
        if (*pattern == '\0') {
          return false;
        }
        break;
    }
  }

  return false;
}