string LinuxParser::Command(int pid) {
string cmd_val, line;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kCmdlineFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
      std::istringstream linestream(line);
      std::replace(line.begin(), line.end(), ' ', '*');
      while (linestream >> cmd_val) {
          std::replace(cmd_val.begin(), cmd_val.end(), '*', ' ');
          return cmd_val;
        }
    }
  }
    return string();
}