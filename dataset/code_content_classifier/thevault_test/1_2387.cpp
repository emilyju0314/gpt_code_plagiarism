double Analytic_TR_Eloss_Model::calculate_eloss(const double T, const double rho,
                                                const double v) const {

  Require(T >= 0.0);
  Require(rho >= 0.0);
  Require(v >= 0.0);

  const double keV = 1e3 * pc.eV();
  const double eloss_unit_fac = 1.e-8 / keV;
  const double hbar = pc.h() / (2. * pc.pi());

  const double nt = rho / mt;
  const double Tt = T * keV / pc.k();
  const double vp = v * 1.e8;
  const double vt = sqrt(2. * pc.k() * Tt / mt);
  const double Ep = 1. / 2. * mp * vp * vp;

  if (Ep < 2. * pc.k() * Tt)
    return rtt_cdi::constants::max_eloss;

  const double prefac = 4. * pc.pi() * nt * qtabs * qtabs * qpabs * qpabs / (mt * vp * vp);
  const double zeta = vp / vt;

  double Psi = 0.;
  double logL = 0.;

  if (zaidt == -1) {
    // Possibly degenerate electron target
    Psi = std::erf(zeta) - 2. * zeta / sqrt(pc.pi()) * (1. + mt / mp) * exp(-pow(zeta, 2));

    // Fermi temperature
    const double TF = pow(pc.pi(), 4. / 3.) * hbar * hbar * pow(nt, 2. / 3.) /
                      (pow(3., 1. / 3.) * pc.k() * pc.me());
    double lambsq = (12. * mt * pc.k() * pc.k()) * Tt * Tt *
                    (exp(-1.) + 4. / 9. * pow(TF / Tt, 2)) /
                    (hbar * hbar * 4. * pc.pi() * pc.e() * pc.e() * nt);
    Require(lambsq > -1.);
    double lamb_e = log(1. + lambsq);
    double lambcnst = 0.;
    if (lamb_e >= 2.) {
      lambcnst = 1.;
    } else if (lamb_e >= 1.) {
      lambcnst = lamb_e - 1.;
    }
    logL = 1. / 2. * (lamb_e - lambcnst);

    const double a1 = 4. / 5. - pc.pi() / 20.;
    constexpr double a2 = 1.317;
    constexpr double a4 = 0.303;
    constexpr double a6 = 0.177;
    constexpr double b2 = 1.317;
    constexpr double b4 = 0.120;
    constexpr double b6 = 0.0365;
    double Delta = log(1. + a1 * pow(zeta, 2));
    Delta += log((1. + a2 * pow(zeta, 2) + a4 * pow(zeta, 4) + a6 * pow(zeta, 6)) /
                 (1. + b2 * pow(zeta, 2) + b4 * pow(zeta, 4) + b6 * pow(zeta, 6)));

    logL += Delta;

  } else {
    // Assumed non-degenerate ion target
    Psi = std::erf(zeta) - 2. * zeta / sqrt(pc.pi()) * (1. + mt / mp) * exp(-pow(zeta, 2));

    double debye =
        sqrt(pc.k() * Tt / (4. * pc.pi() * nt * pc.e() * pc.e())); // Electron debye length
    double mu = mt * mp / (mt + mp);                               // Mean particle mass
    double vmin = std::min<double>(vp, vt);
    double vmax = std::max<double>(vp, vt);
    constexpr double vfac = 0.27323954;
    double vrel = vmax * (1. + vfac * (vmin / vmax)); // Mean relative speed
    double bmin = qtabs * qpabs / (mu * vrel * vrel); // Minimum impace parameter
    logL = log(debye / bmin);
  }

  return vp * prefac * Psi * logL * eloss_unit_fac;
}