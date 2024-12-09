double Analytic_Spitzer_Eloss_Model::calculate_eloss(const double T, const double rho,
                                                     const double v) const {
  Require(T >= 0.0);
  Require(rho >= 0.0);
  Require(v >= 0.0);

  const double keV = 1e3 * pc.eV();
  const double eloss_unit_fac = 1.e-8 / keV;

  const double nt = rho / mt;
  const double Tt = T * keV / pc.k();
  const double vp = v * 1.e8;
  const double vt = sqrt(2. * pc.k() * Tt / mt);
  const double Ep = 1. / 2. * mp * vp * vp;

  const double prefac = 4. * pc.pi() * nt * qtabs * qtabs * qpabs * qpabs / (mt * vp * vp);

  // Spitzer approach: Argument of the Coulomb logarithm is the ratio of Debye
  // length to distance of closest approach
  const double debye_length = sqrt(pc.k() * Tt / (4. * pc.pi() * nt * qtabs * qtabs));
  const double vrel = sqrt(vp * vp + vt * vt);
  const double mreduced = (mt * mp) / (mt + mp);
  const double bmin = qtabs * qpabs / (mreduced * vrel * vrel);
  const double coulomb_log = log(std::max<double>(exp(1.), debye_length / bmin));

  double eloss = prefac * coulomb_log;

  if (Ep < 2. * pc.k() * Tt) {
    return rtt_cdi::constants::max_eloss;
  }

  return vp * eloss * eloss_unit_fac;
}