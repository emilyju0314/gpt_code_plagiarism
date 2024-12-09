Analytic_Gray_Opacity::sf_double Analytic_Gray_Opacity::getOpacity(double temperature,
                                                                   const sf_double &density) const {
  Require(temperature >= 0.0);

  // define the return opacity field (same size as density field)
  sf_double opacity(density.size(), 0.0);

  // define an opacity iterator
  auto sig = opacity.begin();

  // loop through densities and solve for opacity
  for (auto rho = density.begin(); rho != density.end(); rho++, sig++) {
    Check(*rho >= 0.0);

    // define opacity
    *sig = analytic_model->calculate_opacity(temperature, *rho);

    Check(*sig >= 0.0);
  }

  return opacity;
}