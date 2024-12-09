std::vector<std::vector<double>>
IpcressMultigroupOpacity::getOpacity(std::vector<double> const &targetTemperature,
                                     double targetDensity) const {
  std::vector<std::vector<double>> opacity(targetTemperature.size());
  for (size_t i = 0; i < targetTemperature.size(); ++i)
    opacity[i] = getOpacity(targetTemperature[i], targetDensity);
  return opacity;
}