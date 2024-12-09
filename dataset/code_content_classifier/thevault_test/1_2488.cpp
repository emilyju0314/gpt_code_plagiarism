double Analytic_CP_Eloss::getEloss(double temperature, double density, double v0) const {
  Require(temperature >= 0.0);
  Require(density >= 0.0);
  Require(v0 >= 0.0);

  // define return eloss
  double eloss = analytic_model->calculate_eloss(temperature, density, v0);

  Ensure(eloss >= 0.0);
  return eloss;
}