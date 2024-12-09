int LinuxParser::TotalProcesses() {
  int val;
  string key, value, line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "processes") { 
          val = std::stoi(value);
          return val;
        }
      }
    }
  }
  return 0;
}