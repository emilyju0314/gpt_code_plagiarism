static int EvaluateSkinColorDifference(int cb, int cr) {
  const int cb_q6 = cb << 6;
  const int cr_q6 = cr << 6;
  const int cb_diff_q12 = (cb_q6 - skin_mean[0]) * (cb_q6 - skin_mean[0]);
  const int cbcr_diff_q12 = (cb_q6 - skin_mean[0]) * (cr_q6 - skin_mean[1]);
  const int cr_diff_q12 = (cr_q6 - skin_mean[1]) * (cr_q6 - skin_mean[1]);
  const int cb_diff_q2 = (cb_diff_q12 + (1 << 9)) >> 10;
  const int cbcr_diff_q2 = (cbcr_diff_q12 + (1 << 9)) >> 10;
  const int cr_diff_q2 = (cr_diff_q12 + (1 << 9)) >> 10;
  const int skin_diff =
      skin_inv_cov[0] * cb_diff_q2 + skin_inv_cov[1] * cbcr_diff_q2 +
      skin_inv_cov[2] * cbcr_diff_q2 + skin_inv_cov[3] * cr_diff_q2;
  return skin_diff;
}