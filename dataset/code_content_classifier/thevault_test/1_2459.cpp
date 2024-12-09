Analytic_MultigroupOpacity::Analytic_MultigroupOpacity(sf_double groups,
                                                       rtt_cdi::Reaction reaction_in,
                                                       rtt_cdi::Model model_in)
    : group_boundaries(std::move(groups)), reaction(reaction_in), model(model_in) {
  Require(reaction == rtt_cdi::TOTAL || reaction == rtt_cdi::ABSORPTION ||
          reaction == rtt_cdi::SCATTERING);
}