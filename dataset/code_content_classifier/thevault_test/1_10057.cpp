int64_t JitterFilter::MeanUs() {
  const double kPi = 3.1415926535897932;
  double max_jitter_us = static_cast<double>(kN * stddev_jitter_us_);
  double right_sided_mean_us =
      static_cast<double>(stddev_jitter_us_) / sqrt(kPi / 2.0);
  double truncated_mean_us =
      right_sided_mean_us *
          (1.0 - exp(-pow(static_cast<double>(kN), 2.0) / 2.0)) +
      max_jitter_us * erfc(static_cast<double>(kN));
  return static_cast<int64_t>(truncated_mean_us + 0.5);
}