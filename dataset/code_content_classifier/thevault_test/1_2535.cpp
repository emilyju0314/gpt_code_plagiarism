std::vector<double> IpcressMultigroupOpacity::getOpacity(double targetTemperature,
                                                         double targetDensity) const {
  // number of groups in this multigroup set.
  size_t const numGroups = spIpcressDataTable->getNumGroupBoundaries() - 1;

  // temporary opacity vector used by the wrapper.  The returned data will be
  // copied into the opacityIterator.
  std::vector<double> opacity(numGroups, -99.0);

  // logarithmic interpolation:
  for (size_t g = 0; g < numGroups; ++g) {
    opacity[g] = spIpcressDataTable->interpOpac(targetTemperature, targetDensity, g);
    Check(opacity[g] >= 0.0);
  }
  return opacity;
}