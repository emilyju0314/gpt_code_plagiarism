bool matchSeparator(const char** pp, char ch) {
  const char* p = *pp;
  if (LIKELY(*p == ch)) { *pp = p + 1; return true; };
  p = skipSpace(p);
  if (LIKELY(*p == ch)) { *pp = p + 1; return true; }
  return false;
}