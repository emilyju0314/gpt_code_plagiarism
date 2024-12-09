Compound_Analytic_MultigroupOpacity::std_string
Compound_Analytic_MultigroupOpacity::getDataDescriptor() const {
  std_string descriptor;

  rtt_cdi::Reaction const rxn = getReactionType();

  if (rxn == rtt_cdi::TOTAL)
    descriptor = "Compound Multigroup Total";
  else if (rxn == rtt_cdi::ABSORPTION)
    descriptor = "Compound Multigroup Absorption";
  else if (rxn == rtt_cdi::SCATTERING)
    descriptor = "Compound Multigroup Scattering";
  else {
    Insist(rxn == rtt_cdi::TOTAL || rxn == rtt_cdi::ABSORPTION || rxn == rtt_cdi::SCATTERING,
           "Invalid Compound multigroup model opacity!");
  }

  return descriptor;
}