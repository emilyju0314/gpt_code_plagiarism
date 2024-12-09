string LinuxParser::Uid(int pid) {
  string line, key, value;
  string Uid;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == "Uid:") {
        Uid = value;
        return Uid;
      }
    }
  }
  filestream.close();
  return "no Uid";
}