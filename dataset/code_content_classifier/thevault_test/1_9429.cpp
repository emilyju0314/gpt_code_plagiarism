const char *FindUnterminatedCommentInLine(const char *line, size_t line_len) {
  // Search backwards.  If we find /*, return its location unless we've already
  // seen */.
  for (const char *ptr = line + line_len - 1; ptr > line; --ptr) {
    if (ptr[-1] == '*' && ptr[0] == '/') {
      return nullptr;
    }
    if (ptr[-1] == '/' && ptr[0] == '*') {
      return ptr - 1;
    }
  }

  return nullptr;
}