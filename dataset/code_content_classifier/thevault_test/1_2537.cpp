std::vector<std::vector<double>>
IpcressMultigroupOpacity::getOpacity(double targetTemperature,
                                     const std::vector<double> &targetDensity) const {
  std::vector<std::vector<double>> opacity(targetDensity.size());
  for (size_t i = 0; i < targetDensity.size(); ++i)
    opacity[i] = getOpacity(targetTemperature, targetDensity[i]);
  return opacity;
}