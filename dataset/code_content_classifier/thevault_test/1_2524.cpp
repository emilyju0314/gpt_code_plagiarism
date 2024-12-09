std::vector<double>
DummyEoS::getElectronThermalConductivity(const std::vector<double> &vtemperature,
                                         const std::vector<double> &vdensity) const {
  std::vector<double> ebtc(vdensity.size());
  for (unsigned i = 0; i < vdensity.size(); ++i)
    ebtc[i] = 1000.0 * vtemperature[i] + vdensity[i];
  return ebtc;
}