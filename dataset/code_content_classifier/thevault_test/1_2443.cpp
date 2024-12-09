Analytic_Gray_Opacity::sf_double Analytic_Gray_Opacity::getOpacity(const sf_double &temperature,
                                                                   double density) const {
  Require(density >= 0.0);

  // define the return opacity field (same size as temperature field)
  sf_double opacity(temperature.size(), 0.0);

  // define an opacity iterator
  auto sig = opacity.begin();

  // loop through temperatures and solve for opacity
  for (auto T = temperature.begin(); T != temperature.end(); T++, sig++) {
    Check(*T >= 0.0);

    // define opacity
    *sig = analytic_model->calculate_opacity(*T, density);

    Check(*sig >= 0.0);
  }

  return opacity;
}