static real normalizeL1(real* x, int n) {
  real sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += x[i];
  }
  // Right now, we just bet that sum won't be zero. If this really happens,
  // we will figure out what should be done then.
  CHECK_GT(sum, 0);
  real s = 1 / sum;
  for (int i = 0; i < n; ++i) {
    x[i] *= s;
  }
  return sum;
}