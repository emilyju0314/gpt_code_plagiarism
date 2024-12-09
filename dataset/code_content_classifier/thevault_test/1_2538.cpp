std::vector<char> IpcressMultigroupOpacity::pack() const {
  using std::string;
  using std::vector;

  // pack up the energy policy descriptor
  vector<char> packed_descriptor;
  rtt_dsxx::pack_data(energyPolicyDescriptor, packed_descriptor);

  // pack up the ipcress file name
  vector<char> packed_filename;
  rtt_dsxx::pack_data(ipcressFilename, packed_filename);

  // determine the total size: 3 ints (reaction, model, material id) + 2 ints
  // for packed_filename size and packed_descriptor size + char in
  // packed_filename and packed_descriptor
  size_t size = 5 * sizeof(int) + packed_filename.size() + packed_descriptor.size();

  // make a container to hold packed data
  vector<char> packed(size);

  // make a packer and set it
  rtt_dsxx::Packer packer;
  packer.set_buffer(size, &packed[0]);

  // pack the descriptor
  packer << static_cast<int>(packed_descriptor.size());
  for (char &c : packed_descriptor)
    packer << c;

  // pack the filename (size and elements)
  packer << static_cast<int>(packed_filename.size());
  for (char &c : packed_filename)
    packer << c;

  // pack the material id
  packer << static_cast<int>(materialID);

  // pack the model and reaction
  packer << static_cast<int>(opacityModel) << static_cast<int>(opacityReaction);

  Ensure(packer.get_ptr() == &packed[0] + size);
  return packed;
}