static TFloat DotProductGeneric(const TFloat *u, const TFloat *v, int n) {
  TFloat total = 0;
  for (int k = 0; k < n; ++k) {
    total += u[k] * v[k];
  }
  return total;
}