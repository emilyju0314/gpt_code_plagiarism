int LinuxParser::TotalProcesses() {
  int TotalProcesses;
  string key, value, line;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == "processes" && value != "") {
        TotalProcesses = stoi(value);
        return TotalProcesses;
      }
    }
  }
  filestream.close();
  return 0;
}