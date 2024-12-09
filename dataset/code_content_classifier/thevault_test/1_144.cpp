static int count_fields(const char *line) {
  const char *ptr;
  int cnt, fQuote;

  for (cnt = 1, fQuote = 0, ptr = line; *ptr; ptr++) {
    if (fQuote) {
      if (*ptr == '\"') {
        if (ptr[1] == '\"') {
          ptr++;
          continue;
        }
        fQuote = 0;
      }
      continue;
    }

    switch (*ptr) {
    case '\"':
      fQuote = 1;
      continue;
    case ',':
      cnt++;
      continue;
    default:
      continue;
    }
  }

  if (fQuote) {
    return -1;
  }

  return cnt;
}