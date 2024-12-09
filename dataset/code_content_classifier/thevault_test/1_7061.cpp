int pacing() {
  static uint64_t last = 0;
  uint64_t now = monotime();
  int rc = 0;

  if ((now - last) > 1000000) {
    last = now;
    rc = 1;
  }

  return rc;
}