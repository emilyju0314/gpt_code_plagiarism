inline int64_t FloorToUnit(bela::Duration d, bela::Duration unit) {
  bela::Duration rem;
  int64_t q = bela::IDivDuration(d, unit, &rem);
  return (q > 0 || rem >= ZeroDuration() || q == (std::numeric_limits<int64_t>::min)()) ? q : q - 1;
}