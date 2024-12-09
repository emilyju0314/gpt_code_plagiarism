Analytic_MultigroupOpacity::sf_char Analytic_MultigroupOpacity::pack() const {
  // make a packer
  rtt_dsxx::Packer packer;

  // now add up the total size; number of groups + 1 int for number of groups,
  // number of models + size in each model + models, 1 int for reaction type,
  // 1 int for model type
  Check(3 * sizeof(int) + group_boundaries.size() * sizeof(double) < INT_MAX);
  int size = static_cast<int>(3 * sizeof(int) + group_boundaries.size() * sizeof(double));

  // make a char array
  sf_char packed(size);

  // set the buffer
  packer.set_buffer(size, &packed[0]);

  // pack the number of groups and group boundaries
  packer << static_cast<int>(group_boundaries.size());
  for (auto &gb : group_boundaries)
    packer << gb;

  // now pack the reaction and model type
  packer << static_cast<int>(reaction) << static_cast<int>(model);

  Ensure(packer.get_ptr() == &packed[0] + size);
  return packed;
}