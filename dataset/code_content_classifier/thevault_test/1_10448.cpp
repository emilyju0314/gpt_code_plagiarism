TFloat DotProductNEON(const TFloat *u, const TFloat *v, int n) {
  TFloat total = 0;
#if defined(OPENMP_SIMD) || defined(_OPENMP)
#pragma omp simd reduction(+:total)
#endif
  for (int k = 0; k < n; k++) {
    total += u[k] * v[k];
  }
  return total;
}