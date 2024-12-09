double Analytic_EoS::getElectronTemperature(double rho, double Ue, double Tguess) const {
  Require(Tguess >= 0.0);
  Require(Ue >= 0.0);
  Require(rho > 0.0);

  double T_new = analytic_model->calculate_elec_temperature(rho, Ue, Tguess);

  Ensure(T_new >= 0.0);
  return T_new;
}