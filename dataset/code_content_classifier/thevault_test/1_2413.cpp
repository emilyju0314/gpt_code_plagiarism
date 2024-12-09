std::vector<double> DummyEICoupling::getElectronIonCoupling(const std::vector<double> &etemperature,
                                                            const std::vector<double> &itemperature,
                                                            const std::vector<double> &density,
                                                            const std::vector<double> &w_e,
                                                            const std::vector<double> &w_i) const {
  std::vector<double> ei_coupling(density.size());
  for (unsigned i = 0; i < density.size(); ++i)
    ei_coupling[i] = etemperature[i] + 10.0 * itemperature[i] + 100.0 * density[i] +
                     1000.0 * w_e[i] + 10000.0 * w_i[i];
  return ei_coupling;
}