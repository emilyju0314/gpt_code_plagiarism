std::vector<double> DummyGrayOpacity::getOpacity(const std::vector<double> &targetTemperature,
                                                 double targetDensity) const {
  std::vector<double> grayOpacity(targetTemperature.size());
  for (size_t i = 0; i < targetTemperature.size(); ++i)
    grayOpacity[i] = targetTemperature[i] + targetDensity / 1000.0;
  return grayOpacity;
}