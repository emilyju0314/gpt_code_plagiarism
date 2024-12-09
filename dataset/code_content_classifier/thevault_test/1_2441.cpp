Analytic_Gray_Opacity::Analytic_Gray_Opacity(const sf_char &packed)
    : analytic_model(), reaction(), model() {
  // the packed size must be at least 4 integers (size, reaction type,
  // model type, analytic model indicator)
  Require(packed.size() >= 4 * sizeof(int));

  // make an unpacker
  rtt_dsxx::Unpacker unpacker;

  // set the buffer
  unpacker.set_buffer(packed.size(), &packed[0]);

  // unpack the size of the analytic model
  int size_analytic;
  unpacker >> size_analytic;
  Check(static_cast<size_t>(size_analytic) >= sizeof(int));

  // unpack the packed analytic model
  std::vector<char> packed_analytic(size_analytic);
  for (int i = 0; i < size_analytic; i++)
    unpacker >> packed_analytic[i];

  // unpack the reaction and model type
  int react_int, model_int;
  unpacker >> react_int >> model_int;
  Check(unpacker.get_ptr() == &packed[0] + packed.size());

  // assign the reaction and type
  reaction = static_cast<rtt_cdi::Reaction>(react_int);
  model = static_cast<rtt_cdi::Model>(model_int);
  Check(reaction == rtt_cdi::ABSORPTION || reaction == rtt_cdi::SCATTERING ||
        reaction == rtt_cdi::TOTAL);

  // now reset the buffer so that we can determine the analytic model
  // indicator
  unpacker.set_buffer(size_analytic, &packed_analytic[0]);

  // unpack the indicator
  int indicator;
  unpacker >> indicator;

  // now determine which analytic model we need to build
  if (indicator == CONSTANT_ANALYTIC_OPACITY_MODEL) {
    analytic_model = std::make_shared<Constant_Analytic_Opacity_Model>(packed_analytic);
  } else if (indicator == POLYNOMIAL_ANALYTIC_OPACITY_MODEL) {
    analytic_model = std::make_shared<Polynomial_Analytic_Opacity_Model>(packed_analytic);
  } else {
    Insist(0, "Unregistered analytic opacity model!");
  }

  Ensure(analytic_model);
}