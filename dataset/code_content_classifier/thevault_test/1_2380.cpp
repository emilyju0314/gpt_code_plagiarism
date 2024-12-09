void Tabular_CP_Eloss::skip_lines(uint32_t nlines) {
  std::string line;
  for (uint32_t nline = 0; nline < nlines; nline++) {
    std::getline(file, line);
  }
}