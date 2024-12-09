IpcressMultigroupOpacity::IpcressMultigroupOpacity(
    std::shared_ptr<IpcressFile const> const &spIpcressFile, size_t in_materialID,
    rtt_cdi::Model in_opacityModel, rtt_cdi::Reaction in_opacityReaction)
    : ipcressFilename(spIpcressFile->getDataFilename()), materialID(in_materialID), fieldNames(),
      opacityModel(in_opacityModel), opacityReaction(in_opacityReaction),
      energyPolicyDescriptor("mg"), spIpcressDataTable() {
  // Verify that the requested material ID is available in the specified IPCRESS
  // file.
  Insist(spIpcressFile->materialFound(materialID),
         std::string("The requested material ID is not available in the ") +
             std::string("specified Ipcress file."));

  // Retrieve keys available for this material from the IPCRESS file.
  fieldNames = spIpcressFile->listDataFieldNames(materialID);
  Check(fieldNames.size() > 0);

  // Create the data table object and fill it with the table data from the
  // IPCRESS file.
  spIpcressDataTable = std::make_shared<IpcressDataTable>(
      energyPolicyDescriptor, opacityModel, opacityReaction, fieldNames, materialID, spIpcressFile);

}