double Analytic_EoS::getIonTemperature(double rho, double Uic, double Tguess) const {
  Require(Tguess >= 0.0);
  Require(Uic >= 0.0);
  Require(rho > 0.0);

  double T_new = analytic_model->calculate_ion_temperature(rho, Uic, Tguess);

  Ensure(T_new >= 0.0);
  return T_new;
}