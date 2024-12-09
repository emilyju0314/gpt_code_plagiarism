void IpcressDataTable::loadDataTable(std::shared_ptr<const IpcressFile> const &spIpcressFile) {
  // The interpolation routines expect everything to be in log form so we only
  // store the logorithmic temperature, density and opacity data.
  logTemperatures.resize(temperatures.size());
  std::transform(temperatures.begin(), temperatures.end(), logTemperatures.begin(), unary_log);
  logDensities.resize(densities.size());
  std::transform(densities.begin(), densities.end(), logDensities.begin(), unary_log);

  std::vector<double> opacities = spIpcressFile->getData(matID, ipcressDataTypeKey);
  logOpacities.resize(opacities.size());
  std::transform(opacities.begin(), opacities.end(), logOpacities.begin(), unary_log);
}