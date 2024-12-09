std::vector<double>
DummyEoS::getSpecificIonInternalEnergy(const std::vector<double> &vtemperature,
                                       const std::vector<double> &vdensity) const {
  return getSpecificElectronInternalEnergy(vdensity, vtemperature);
}