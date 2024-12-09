static char *Append(char *out, const AlphaNum &x) {
  // memcpy is allowed to overwrite arbitrary memory, so doing this after the
  // call would force an extra fetch of x.size().
  char *after = out + x.size();
  memcpy(out, x.data(), x.size());
  return after;
}