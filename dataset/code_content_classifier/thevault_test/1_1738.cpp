uint64 FingerPrint(const char *s) {
  uint32 high = 0, low = 0;
  for (; (*s) != '\0'; ++s) {
    low = (low << 5) - low + (*s);
    high = (high << 5) + high + (*s);
  }

  return (static_cast<uint64>(high) << 32) + low;
}