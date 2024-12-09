static int to_canonical(char *to, const char *from, size_t tolen) {
  char* c = fl_find_fontsize((char*)from);
  if (!c) return -1; // no point size found...
  const char* endptr;
  int size = strtol(c,(char**)&endptr,10);
  if (from[0] == '-') {
    // replace the "foundry" with -*-:
    *to++ = '-'; *to++ = '*';
    for (from++; *from && *from != '-'; from++);
    // skip to the registry-encoding:
    endptr = (char*)fl_font_word(endptr,6);
    if (*endptr && !use_registry(endptr+1)) endptr = "";
  }
  int n = c-from;
  // MRS: we want strncpy here, not strlcpy...
  if (n > (int)(tolen - 1)) return -1;
  strncpy(to,from,n);
  to[n++] = '*';
  strlcpy(to+n,endptr, tolen - n);
  return size;
}