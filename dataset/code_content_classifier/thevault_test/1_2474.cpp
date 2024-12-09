Analytic_EoS::sf_double Analytic_EoS::getElectronThermalConductivity(const sf_double &T,
                                                                     const sf_double &rho) const {
  Require(T.size() == rho.size());

  // define the return electron thermal conductivity field
  sf_double thermal_conductivity(T.size(), 0.0);

  // loop through T/rho field and solve for the thermal conductivity
  for (size_t i = 0; i < T.size(); i++) {
    Check(T[i] >= 0.0);
    Check(rho[i] >= 0.0);

    thermal_conductivity[i] = analytic_model->calculate_elec_thermal_conductivity(T[i], rho[i]);

    Check(thermal_conductivity[i] >= 0.0);
  }

  return thermal_conductivity;
}