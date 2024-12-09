double Analytic_EoS::getSpecificIonInternalEnergy(double T, double rho) const {
  Require(T >= 0.0);
  Require(rho >= 0.0);

  double internal_energy = analytic_model->calculate_ion_internal_energy(T, rho);

  Ensure(internal_energy >= 0.0);
  return internal_energy;
}