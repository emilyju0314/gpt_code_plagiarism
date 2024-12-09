Analytic_EoS::sf_double Analytic_EoS::getIonHeatCapacity(const sf_double &T,
                                                         const sf_double &rho) const {
  Require(T.size() == rho.size());

  // define the return ion heat capacity field
  sf_double heat_capacity(T.size(), 0.0);

  // loop through T/rho field and solve for the heat capacity
  for (size_t i = 0; i < T.size(); i++) {
    Check(T[i] >= 0.0);
    Check(rho[i] >= 0.0);

    heat_capacity[i] = analytic_model->calculate_ion_heat_capacity(T[i], rho[i]);

    Check(heat_capacity[i] >= 0.0);
  }

  return heat_capacity;
}