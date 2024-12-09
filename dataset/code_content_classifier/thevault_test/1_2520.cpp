std::vector<double>
DummyEoS::getSpecificElectronInternalEnergy(const std::vector<double> &vtemperature,
                                            const std::vector<double> &vdensity) const {
  std::vector<double> seie(vdensity.size());
  for (unsigned i = 0; i < vdensity.size(); ++i)
    seie[i] = vtemperature[i] + 1000.0 * vdensity[i];
  return seie;
}