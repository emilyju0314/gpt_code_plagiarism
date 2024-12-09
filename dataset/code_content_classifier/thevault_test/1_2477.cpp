Analytic_EoS::sf_char Analytic_EoS::pack() const {
  Require(analytic_model);

  // make a packer
  rtt_dsxx::Packer packer;

  // first pack up the analytic model
  sf_char anal_model = analytic_model->pack();

  // now add up the total size (in bytes): size of analytic model + 1
  // int for size of analytic model
  Check(anal_model.size() + 1 * sizeof(int) < INT_MAX);
  int size = static_cast<int>(anal_model.size() + 1 * sizeof(int));

  // make a char array
  sf_char packed(size);

  // set the buffer
  packer.set_buffer(size, &packed[0]);

  // pack the anal_model size
  packer << static_cast<int>(anal_model.size());

  // now pack the anal model
  for (auto &am : anal_model)
    packer << am;

  Ensure(packer.get_ptr() == &packed[0] + size);
  return packed;
}