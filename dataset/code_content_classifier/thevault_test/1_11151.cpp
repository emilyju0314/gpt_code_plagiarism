static bool DecodeRadicalTable(std::string &radical_data, RSMap *radical_map) {
  std::vector<std::string> lines = split(radical_data, '\n');
  for (unsigned i = 0; i < lines.size(); ++i) {
    if (!DecodeRadicalLine(lines[i], radical_map)) {
      tprintf("Invalid format in radical table at line %d: %s\n", i, lines[i].c_str());
      return false;
    }
  }
  return true;
}