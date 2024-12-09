IpcressMultigroupOpacity::IpcressMultigroupOpacity(std::vector<char> const &packed)
    : ipcressFilename(), materialID(0), fieldNames(), opacityModel(), opacityReaction(),
      energyPolicyDescriptor("mg"), spIpcressDataTable() {
  Require(packed.size() >= 5 * sizeof(int));

  // make an unpacker
  rtt_dsxx::Unpacker unpacker;
  unpacker.set_buffer(packed.size(), &packed[0]);

  // unpack and check the descriptor
  int packed_descriptor_size = 0;
  unpacker >> packed_descriptor_size;
  Check(packed_descriptor_size > 0);

  // make a vector<char> for the packed descriptor
  std::vector<char> packed_descriptor(packed_descriptor_size);

  // unpack it
  std::string descriptor;
  for (size_t i = 0; i < static_cast<size_t>(packed_descriptor_size); i++)
    unpacker >> packed_descriptor[i];
  rtt_dsxx::unpack_data(descriptor, packed_descriptor);

  // make sure it is "gray"
  Insist(descriptor == "mg", "Tried to unpack a non-mg opacity in IpcressMultigroupOpacity.");

  // unpack the size of the packed filename
  int packed_filename_size(0);
  unpacker >> packed_filename_size;

  // make a vector<char> for the packed filename
  std::vector<char> packed_filename(packed_filename_size);

  // unpack it
  for (size_t i = 0; i < static_cast<size_t>(packed_filename_size); i++)
    unpacker >> packed_filename[i];
  rtt_dsxx::unpack_data(ipcressFilename, packed_filename);

  // unpack the material id
  int itmp(0);
  unpacker >> itmp;
  materialID = static_cast<size_t>(itmp);

  // unpack the model and reaction
  int model = 0;
  int reaction = 0;
  unpacker >> model >> reaction;

  opacityModel = static_cast<rtt_cdi::Model>(model);
  opacityReaction = static_cast<rtt_cdi::Reaction>(reaction);

  Ensure(unpacker.get_ptr() == &packed[0] + packed.size());

  // build a new IpcressFile
  std::shared_ptr<IpcressFile> spIpcressFile;
  spIpcressFile = std::make_shared<IpcressFile>(ipcressFilename);
  Check(spIpcressFile);

  // Verify that the requested material ID is available in the specified IPCRESS
  // file.
  Insist(spIpcressFile->materialFound(materialID),
         "Requested material ID is not found in the specified Ipcress file.");

  // Retrieve keys available fo this material from the IPCRESS file.
  fieldNames = spIpcressFile->listDataFieldNames(materialID);
  Check(fieldNames.size() > 0);

  // Create the data table object and fill it with the table data from the
  // IPCRESS file.
  spIpcressDataTable = std::make_shared<IpcressDataTable>(
      energyPolicyDescriptor, opacityModel, opacityReaction, fieldNames, materialID, spIpcressFile);

  Ensure(spIpcressFile);
  Ensure(spIpcressDataTable);
}