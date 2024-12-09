Analytic_Gray_Opacity::Analytic_Gray_Opacity(SP_Analytic_Model model_in,
                                             rtt_cdi::Reaction reaction_in,
                                             rtt_cdi::Model cdi_model_in)
    : analytic_model(std::move(model_in)), reaction(reaction_in), model(cdi_model_in) {
  Require(reaction == rtt_cdi::TOTAL || reaction == rtt_cdi::ABSORPTION ||
          reaction == rtt_cdi::SCATTERING);

  Ensure(analytic_model);
}