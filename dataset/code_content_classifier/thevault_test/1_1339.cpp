NumericVector log_segment(int n1, int n2, const IntegerVector &d, const IntegerVector &len,
                           double mu_f, double mu_m, double intercept, const NumericVector &male_map,
                           const NumericVector &female_map, const NumericVector &male_start,
                           const NumericVector &female_start, const NumericVector &male_end,
                           const NumericVector &female_end) {
  NumericVector result(d.size());
  // Optimization for small number of mutations... which should be fine for real mutation rate.
  static const double lgamma_lookup[] = {
      lgamma(1), lgamma(2), lgamma(3), lgamma(4),  lgamma(5),  lgamma(6),
      lgamma(7), lgamma(8), lgamma(9), lgamma(10), lgamma(11), lgamma(12)};
  for (size_t i = 0; i < d.size(); i++) {
    const double temp = lgamma_lookup[(int)d[i]];
    const double d1 = (n1 + 1) * female_map[i] + (n2 - 1) * male_map[i];
    const double d2 = (n1 - 1) * female_map[i] + (n2 + 1) * male_map[i];
    double w1 = log((n1 + 1) * female_start[i] + (n2 - 1) * male_start[i]) +
                log((n1 + 1) * female_end[i] + (n2 - 1) * male_end[i]);
    double w2 = log((n1 - 1) * female_start[i] + (n2 + 1) * male_start[i]) +
                log((n1 - 1) * female_end[i] + (n2 + 1) * male_end[i]);

    // Avoid taking log(0), start/end should be 0 when the points are around the boundary of the chromosome and so we shouldn't count them.
    if (male_end[i] == 0.0 && male_start[i] == 0.0) {
      w1 = 0.0;
      w2 = 0.0;
    } else if (male_end[i] == 0.0 || female_end[i] == 0.0) {
      w1 = log((n1 + 1) * female_start[i] + (n2 - 1) * male_start[i]);
      w2 = log((n1 - 1) * female_start[i] + (n2 + 1) * male_start[i]);
    } else if (male_start[i] == 0.0 || female_start[i] == 0.0) {
      w1 = log((n1 + 1) * female_end[i] + (n2 - 1) * male_end[i]);
      w2 = log((n1 - 1) * female_end[i] + (n2 + 1) * male_end[i]);
    }

    const double par1 = len[i] * (intercept + (n1 + 1) * mu_f + (n2 - 1) * mu_m);
    const double par2 = len[i] * (intercept + (n1 - 1) * mu_f + (n2 + 1) * mu_m);
    const double pois1 = log(0.5) + d[i] * log(par1) - par1 - temp - d1 + len[i]*w1;
    const double pois2 = log(0.5) + d[i] * log(par2) - par2 - temp - d2 + len[i]*w2;
    result[i] = logsumexp({pois1, pois2});
  }
  return (result);
}