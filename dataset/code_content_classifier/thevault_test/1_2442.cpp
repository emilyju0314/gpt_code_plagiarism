double Analytic_Gray_Opacity::getOpacity(double temperature, double density) const {
  Require(temperature >= 0.0);
  Require(density >= 0.0);

  // define return opacity
  double opacity = analytic_model->calculate_opacity(temperature, density);

  Ensure(opacity >= 0.0);
  return opacity;
}