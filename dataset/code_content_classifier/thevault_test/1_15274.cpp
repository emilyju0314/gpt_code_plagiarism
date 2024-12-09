static const char* SkipSpaces(const char* str) {
  while (isspace(*str))
    str++;
  return str;
}