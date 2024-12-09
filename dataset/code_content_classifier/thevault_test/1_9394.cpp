string LinuxParser::Uid(int pid) {
  string UID{"Uid"};
  string line;
  string skip;
  std::ifstream stream(kProcDirectory + kSlash + std::to_string(pid) +
                       kStatusFilename);
  while (std::getline(stream, line)) {
    if (line.compare(0, UID.size(), UID) == 0) {
      std::istringstream buf(line);
      buf >> skip >> UID;
      return UID;
    }
  }
  return "";
}