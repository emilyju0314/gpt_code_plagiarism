Analytic_Gray_Opacity::sf_char Analytic_Gray_Opacity::pack() const {
  Require(analytic_model);

  // make a packer
  rtt_dsxx::Packer packer;

  // first pack up the analytic model
  sf_char anal_model = analytic_model->pack();

  // now add up the total size (in bytes): size of analytic model + 3
  // int--one for reaction type, one for model type, and one for size of
  // analytic model
  Check(anal_model.size() + 3 * sizeof(int) < INT_MAX);
  int size = static_cast<int>(anal_model.size() + 3 * sizeof(int));

  // make a char array
  sf_char packed(size);

  // set the buffer
  packer.set_buffer(size, &packed[0]);

  // pack the anal_model size
  packer << static_cast<int>(anal_model.size());

  // now pack the anal model
  for (auto &am : anal_model)
    packer << am;

  // pack the reaction and model type
  packer << static_cast<int>(reaction) << static_cast<int>(model);

  Ensure(packer.get_ptr() == &packed[0] + size);
  return packed;
}