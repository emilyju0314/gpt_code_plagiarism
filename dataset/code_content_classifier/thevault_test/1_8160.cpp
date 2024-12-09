wchar_t *Format64(wchar_t *ep, int width, int64_t v) {
  do {
    --width;
    *--ep = L'0' + (v % 10); // contiguous digits
  } while (v /= 10);
  while (--width >= 0) {
    *--ep = L'0'; // zero pad
  }
  return ep;
}