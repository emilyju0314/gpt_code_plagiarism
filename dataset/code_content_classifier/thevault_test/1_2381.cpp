std::vector<std::string> const Tabular_CP_Eloss::read_line() {
  std::string line;
  std::getline(file, line);
  return rtt_dsxx::tokenize(line);
}