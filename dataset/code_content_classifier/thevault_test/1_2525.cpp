Analytic_EICoupling::Analytic_EICoupling(const sf_char &packed) : analytic_model() {
  // the packed size must be at least 2 integers (size,
  // analytic model indicator)
  Require(packed.size() >= 2 * sizeof(int));

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
  for (size_t i = 0; i < static_cast<size_t>(size_analytic); ++i)
    unpacker >> packed_analytic[i];

  Check(unpacker.get_ptr() == &packed[0] + packed.size());

  // now reset the buffer so that we can determine the analytic model
  // indicator
  unpacker.set_buffer(size_analytic, &packed_analytic[0]);

  // unpack the indicator
  int indicator;
  unpacker >> indicator;

  // now determine which analytic model we need to build
  if (indicator == CONSTANT_ANALYTIC_EICOUPLING_MODEL) {
    analytic_model = std::make_shared<Constant_Analytic_EICoupling_Model>(packed_analytic);
  } else {
    Insist(0, "Unregistered analytic EICoupling model!");
  }

  Ensure(analytic_model);
}