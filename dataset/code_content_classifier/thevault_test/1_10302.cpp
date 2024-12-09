void write_stream(std::ostream& os, int width,
    int num, double impact_param, const Event& event) {
  using std::fixed;
  using std::setprecision;
  using std::setw;
  using std::scientific;

  // Write a nicely-formatted line of event properties.
  os << setprecision(10)
     << setw(width)            << num
     << setw(15) << fixed      << impact_param
     << setw(5)                << event.npart();
  if (event.with_ncoll()) os << setw(8)                << event.ncoll();
  os   << setw(18) << scientific << event.multiplicity()            
     << fixed;

  for (const auto& ecc : event.eccentricity())
    os << setw(14) << ecc.second;

  //for (const auto& psi : event.participant_plane())
  //  os << setw(14) << psi.second;

  os << '\n';
}