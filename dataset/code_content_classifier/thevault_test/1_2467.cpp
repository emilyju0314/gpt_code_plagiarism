double Analytic_EoS::getElectronHeatCapacity(double T, double rho) const {
  Require(T >= 0.0);
  Require(rho >= 0.0);

  double heat_capacity = analytic_model->calculate_electron_heat_capacity(T, rho);

  Ensure(heat_capacity >= 0.0);
  return heat_capacity;
}