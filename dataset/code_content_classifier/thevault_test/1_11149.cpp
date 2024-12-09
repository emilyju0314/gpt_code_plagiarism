static void PartialMatrixDotVector1(const int8_t *wi, const TFloat *scales, const int8_t *u,
                                    int num_in, TFloat *v) {
  TFloat total = IntDotProductSSE(u, wi, num_in);
  // Add in the bias and correct for integer values.
  *v = (total + wi[num_in] * INT8_MAX) * *scales;
}