Analytic_EoS::sf_double
Analytic_EoS::getSpecificElectronInternalEnergy(const sf_double &T, const sf_double &rho) const {
  Require(T.size() == rho.size());

  // define the return electron internal energy field
  sf_double internal_energy(T.size(), 0.0);

  // loop through T/rho field and solve for internal energy
  for (size_t i = 0; i < T.size(); i++) {
    Check(T[i] >= 0.0);
    Check(rho[i] >= 0.0);

    internal_energy[i] = analytic_model->calculate_electron_internal_energy(T[i], rho[i]);

    Check(internal_energy[i] >= 0.0);
  }

  return internal_energy;
}