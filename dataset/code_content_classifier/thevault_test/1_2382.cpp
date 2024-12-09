Analytic_Gray_Opacity::std_string Analytic_Gray_Opacity::getDataDescriptor() const {
  std_string descriptor;

  if (reaction == rtt_cdi::TOTAL)
    descriptor = "Analytic Gray Total";
  else if (reaction == rtt_cdi::ABSORPTION)
    descriptor = "Analytic Gray Absorption";
  else if (reaction == rtt_cdi::SCATTERING)
    descriptor = "Analytic Gray Scattering";
  else
    Insist(0, "Invalid analytic gray model opacity!");

  return descriptor;
}