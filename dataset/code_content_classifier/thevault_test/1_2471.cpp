double Analytic_EoS::getNumFreeElectronsPerIon(double T, double rho) const {
  Require(T >= 0.0);
  Require(rho >= 0.0);

  double number = analytic_model->calculate_num_free_elec_per_ion(T, rho);

  Ensure(number >= 0.0);
  return number;
}