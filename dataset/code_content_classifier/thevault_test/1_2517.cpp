void F12inv(double const f, double &eta, double &deta) {
  double constexpr an = 0.5;
  int constexpr m1 = 4;
  int constexpr k1 = 3;
  int constexpr m2 = 6;
  int constexpr k2 = 5;
  std::array<double, m1 + 1> constexpr a1 = {1.999266880833e4, 5.702479099336e3, 6.610132843877e2,
                                             3.818838129486e1, 1.0e0};
  std::array<double, k1 + 1> constexpr b1 = {1.771804140488e4, -2.014785161019e3, 9.130355392717e1,
                                             -1.670718177489e0};
  std::array<double, m2 + 1> constexpr a2 = {-1.277060388085e-2,
                                             7.187946804945e-2,
                                             -4.262314235106e-1,
                                             4.997559426872e-1,
                                             -1.285579118012e0,
                                             -3.930805454272e-1,
                                             1.0e0};
  std::array<double, k2 + 1> constexpr b2 = {-9.745794806288e-3, 5.485432756838e-2,
                                             -3.299466243260e-1, 4.077841975923e-1,
                                             -1.145531476975e0,  -6.067091689181e-2};

  if (f < 4.0e0) {
    double rn = f + a1[m1 - 1];
    double drndf = 1;
    for (int i = m1 - 2; i >= 0; i--) {
      drndf = rn + drndf * f;
      rn = rn * f + a1[i];
    }
    double den = b1[k1];
    double ddendf = 0;
    for (int i = k1 - 1; i >= 0; i--) {
      ddendf = ddendf * f + den;
      den = den * f + b1[i];
    }
    eta = log(f * rn / den);
    deta = (rn + f * drndf - f * rn * ddendf / den) / (f * rn);
  } else {
    double ff = 1.0 / std::pow(f, (1.0 / (1.0 + an)));
    double dffdf = -(1.0 / (1.0 + an)) * ff / f;
    double rn = ff + a2[m2 - 1];
    double drndf = dffdf;
    for (int i = m2 - 2; i >= 0; i--) {
      drndf = drndf * ff + rn * dffdf;
      rn = rn * ff + a2[i];
    }
    double den = b2[k2];
    double ddendf = 0.0;
    for (int i = k2 - 1; i >= 0; i--) {
      ddendf = ddendf * ff + den * dffdf;
      den = den * ff + b2[i];
    }
    eta = rn / (den * ff);
    deta = drndf / (den * ff) - rn * (ddendf * ff + den * dffdf) / (den * den * ff * ff);
  }
}