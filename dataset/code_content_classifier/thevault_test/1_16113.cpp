long LinuxParser::UpTime(int pid) {
  string value, line;
  long UpTime;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatFilename);
  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    int i = 0;
    while (linestream >> value) {
      if (i == 21) {
        UpTime = LinuxParser::UpTime() - stol(value) / sysconf(_SC_CLK_TCK);
        filestream.close();
        return UpTime;
      }
      i++;
    }
  }
  filestream.close();
  return 0;
}