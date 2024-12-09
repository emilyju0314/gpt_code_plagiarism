std::vector<double> DummyGrayOpacity::getOpacity(double targetTemperature,
                                                 const std::vector<double> &targetDensity) const {
  std::vector<double> grayOpacity(targetDensity.size());
  for (size_t i = 0; i < targetDensity.size(); ++i)
    grayOpacity[i] = targetTemperature + targetDensity[i] / 1000.0;
  return grayOpacity;
}