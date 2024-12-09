double Analytic_EoS::getElectronThermalConductivity(double T, double rho) const {
  Require(T >= 0.0);
  Require(rho >= 0.0);

  double thermal_conductivity = analytic_model->calculate_elec_thermal_conductivity(T, rho);

  Ensure(thermal_conductivity >= 0.0);
  return thermal_conductivity;
}