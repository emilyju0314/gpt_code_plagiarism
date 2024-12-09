float LinuxParser::MemoryUtilization() { 
  string key, value, line;
  float memTotal = 0.0, memFree = 0.0;
  std::ifstream stream(kProcDirectory + kMeminfoFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == "MemTotal:") {
        memTotal = stof(value);
      }
      if (key == "MemFree:") {
        memFree = stof(value);
      }
    }
    return (memTotal - memFree) / memTotal;
  }
  return 0.0; 
}