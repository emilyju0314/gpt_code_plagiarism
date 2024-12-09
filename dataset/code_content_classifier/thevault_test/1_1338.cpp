NumericVector log_segment(int n1, int n2, const IntegerVector &d,
                           const IntegerVector &len, double mu_f, double mu_m, double intercept,
                           const NumericVector &male_map,
                           const NumericVector &female_map) {
  NumericVector result(d.size());
  // Optimization for small number of mutations... which should be fine for real mutation rate.
  static const double lgamma_lookup[] = {
      lgamma(1), lgamma(2), lgamma(3), lgamma(4),  lgamma(5),  lgamma(6),
      lgamma(7), lgamma(8), lgamma(9), lgamma(10), lgamma(11), lgamma(12)};
  for (size_t i = 0; i < d.size(); i++) {
    const double temp = lgamma_lookup[(int)d[i]];
    const double d1 = (n1 + 1) * female_map[i] + (n2 - 1) * male_map[i];
    const double d2 = (n1 - 1) * female_map[i] + (n2 + 1) * male_map[i];

    const double par1 = len[i] * (intercept + (n1 + 1) * mu_f + (n2 - 1) * mu_m);
    const double par2 = len[i] * (intercept + (n1 - 1) * mu_f + (n2 + 1) * mu_m);
    const double pois1 = log(0.5) + d[i] * log(par1) - par1 - temp - d1;
    const double pois2 = log(0.5) + d[i] * log(par2) - par2 - temp - d2;

    result[i] = logsumexp({pois1, pois2});
  }
  return (result);
}