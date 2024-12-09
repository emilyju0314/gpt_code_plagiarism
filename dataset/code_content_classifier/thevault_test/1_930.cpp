int LinuxParser::RunningProcesses() {
  string key, value, line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "procs_running") { 
              return std::stoi(value);
        }
      }
    }
  }
    return 0;
}