string LinuxParser::Ram(int pid) {
  string line, key, value;
  string Ram;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == "VmSize:") {
        Ram = to_string(stoi(value) / 1024);
        return Ram;
      }
    }
  }
  filestream.close();
  return "0";
}