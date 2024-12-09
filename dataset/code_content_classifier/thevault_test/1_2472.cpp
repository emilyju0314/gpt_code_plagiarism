Analytic_EoS::sf_double Analytic_EoS::getNumFreeElectronsPerIon(const sf_double &T,
                                                                const sf_double &rho) const {
  Require(T.size() == rho.size());

  // define the return ion heat capacity field
  sf_double number(T.size(), 0.0);

  // loop through T/rho field and solve for the number of free electrons
  // per ion
  for (size_t i = 0; i < T.size(); i++) {
    Check(T[i] >= 0.0);
    Check(rho[i] >= 0.0);

    number[i] = analytic_model->calculate_num_free_elec_per_ion(T[i], rho[i]);

    Check(number[i] >= 0.0);
  }

  return number;
}