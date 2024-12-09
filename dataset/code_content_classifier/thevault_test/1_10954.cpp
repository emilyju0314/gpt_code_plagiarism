int OtsuStats(const int *histogram, int *H_out, int *omega0_out) {
  int H = 0;
  double mu_T = 0.0;
  for (int i = 0; i < kHistogramSize; ++i) {
    H += histogram[i];
    mu_T += static_cast<double>(i) * histogram[i];
  }

  // Now maximize sig_sq_B over t.
  // http://www.ctie.monash.edu.au/hargreave/Cornall_Terry_328.pdf
  int best_t = -1;
  int omega_0, omega_1;
  int best_omega_0 = 0;
  double best_sig_sq_B = 0.0;
  double mu_0, mu_1, mu_t;
  omega_0 = 0;
  mu_t = 0.0;
  for (int t = 0; t < kHistogramSize - 1; ++t) {
    omega_0 += histogram[t];
    mu_t += t * static_cast<double>(histogram[t]);
    if (omega_0 == 0) {
      continue;
    }
    omega_1 = H - omega_0;
    if (omega_1 == 0) {
      break;
    }
    mu_0 = mu_t / omega_0;
    mu_1 = (mu_T - mu_t) / omega_1;
    double sig_sq_B = mu_1 - mu_0;
    sig_sq_B *= sig_sq_B * omega_0 * omega_1;
    if (best_t < 0 || sig_sq_B > best_sig_sq_B) {
      best_sig_sq_B = sig_sq_B;
      best_t = t;
      best_omega_0 = omega_0;
    }
  }
  if (H_out != nullptr) {
    *H_out = H;
  }
  if (omega0_out != nullptr) {
    *omega0_out = best_omega_0;
  }
  return best_t;
}