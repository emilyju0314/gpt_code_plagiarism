string LinuxParser::GetValueFromProcStat(string keyToFind) {
  string key, value, line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == keyToFind) {
        return value;
      }
    }
  }
  return value;
}