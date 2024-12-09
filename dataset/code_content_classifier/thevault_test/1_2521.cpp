std::vector<double> DummyEoS::getElectronHeatCapacity(const std::vector<double> &vtemperature,
                                                      const std::vector<double> &vdensity) const {
  std::vector<double> ehc(vdensity.size());
  for (unsigned i = 0; i < vdensity.size(); ++i)
    ehc[i] = vtemperature[i] + vdensity[i] / 1000.0;
  return ehc;
}