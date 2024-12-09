float LinuxParser::MemoryUtilization() {
  float MemTotal = 0.0, MemFree = 0.0, MemBuffers = 0.0;
  float MemoryUtilization = 0.0;
  string name, value, unit;
  string line;
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> name >> value >> unit;
      if (name == "MemTotal:") {
        MemTotal = stof(value);
      } else if (name == "MemFree:") {
        MemFree = stof(value);
      } else if (name == "Buffers:") {
        MemBuffers = stof(value);
      }
    }
  }
  filestream.close();
  MemoryUtilization = 1 - (MemFree / (MemTotal - MemBuffers));
  return MemoryUtilization;
}