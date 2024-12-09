std::vector<double> DummyEoS::getNumFreeElectronsPerIon(const std::vector<double> &vtemperature,
                                                        const std::vector<double> &vdensity) const {
  std::vector<double> nfepi(vdensity.size());
  for (unsigned i = 0; i < vdensity.size(); ++i)
    nfepi[i] = vtemperature[i] / 100.0;
  return nfepi;
}