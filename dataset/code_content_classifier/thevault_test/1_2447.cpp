IpcressDataTable::IpcressDataTable(std::string in_opacityEnergyDescriptor,
                                   rtt_cdi::Model in_opacityModel,
                                   rtt_cdi::Reaction in_opacityReaction,
                                   std::vector<std::string> const &in_fieldNames, size_t in_matID,
                                   std::shared_ptr<const IpcressFile> const &spIpcressFile)
    : ipcressDataTypeKey(""), dataDescriptor(""),
      opacityEnergyDescriptor(std::move(in_opacityEnergyDescriptor)), opacityModel(in_opacityModel),
      opacityReaction(in_opacityReaction), fieldNames(in_fieldNames), matID(in_matID),
      logTemperatures(), temperatures(), logDensities(), densities(), groupBoundaries(),
      logOpacities() {
  // Obtain the Ipcress keyword for the opacity data type specified by the
  // EnergyPolicy, opacityModel and the opacityReaction.  Valid keywords are:
  // {ramg, rsmg, rtmg, pmg, rgray, ragray, rsgray, pgray} This function also
  // ensures that the requested data type is available in the IPCRESS file.
  setIpcressDataTypeKey();

  // Retrieve the data set and resize the vector containers.
  temperatures = spIpcressFile->getData(matID, "tgrid");
  densities = spIpcressFile->getData(matID, "rgrid");
  groupBoundaries = spIpcressFile->getData(matID, "hnugrid");

  // Retrieve table data (temperatures, densities, group boundaries and
  // opacities.  These are stored as logorithmic values.
  loadDataTable(spIpcressFile);

}