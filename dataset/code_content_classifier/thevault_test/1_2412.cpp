double DummyEICoupling::getElectronIonCoupling(const double etemperature, const double itemperature,
                                               const double density, const double w_e,
                                               const double w_i) const {
  return etemperature + 10.0 * itemperature + 100.0 * density + 1000.0 * w_e + 10000.0 * w_i;
}