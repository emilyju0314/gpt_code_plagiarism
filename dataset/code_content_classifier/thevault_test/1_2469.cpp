double Analytic_EoS::getIonHeatCapacity(double T, double rho) const {
  Require(T >= 0.0);
  Require(rho >= 0.0);

  double heat_capacity = analytic_model->calculate_ion_heat_capacity(T, rho);

  Ensure(heat_capacity >= 0.0);
  return heat_capacity;
}