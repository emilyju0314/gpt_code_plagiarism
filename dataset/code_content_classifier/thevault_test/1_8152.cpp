inline void NormalizeTicks(int64_t *sec, int64_t *ticks) {
  if (*ticks < 0) {
    --*sec;
    *ticks += kTicksPerSecond;
  }
}