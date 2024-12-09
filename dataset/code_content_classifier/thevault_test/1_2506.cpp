double F2inv(double f) {
  double constexpr an = 2.0;
  int constexpr m1 = 4;
  int constexpr k1 = 3;
  int constexpr m2 = 4;
  int constexpr k2 = 3;

  std::array<double, m1 + 1> constexpr a1 = {125.829, 35974.8, 7993.89, 307.849, 1.0e0};
  std::array<double, k1 + 1> constexpr b1 = {251.657, 71940.5, 11494.2, -0.0140884};
  std::array<double, m2 + 1> constexpr a2 = {-3.04879, 714344, 23834.7, -1.08562e6, 1.0e0};
  std::array<double, k2 + 1> constexpr b2 = {-9.14637, 495569, 13194.3, 48419.5};

  if (f < 4.0e0) {
    double rn = f + a1[m1 - 1];
    for (int i = m1 - 2; i >= 0; i--) {
      rn = rn * f + a1[i];
    }
    double den = b1[k1];
    for (int i = k1 - 1; i >= 0; i--) {
      den = den * f + b1[i];
    }
    return log(f * rn / den);
  } else {
    double ff = 1.0 / std::pow(f, (1.0 / (1.0 + an)));
    double rn = ff + a2[m2 - 1];
    for (int i = m2 - 2; i >= 0; i--) {
      rn = rn * ff + a2[i];
    }
    double den = b2[k2];
    for (int i = k2 - 1; i >= 0; i--) {
      den = den * ff + b2[i];
    }
    return rn / (den * ff);
  }
}