long LinuxParser::UpTime() { 
  string line;
  long secondsUptime = 0;
  long cpuuptime = 0;
  std::ifstream filestream(kProcDirectory + kUptimeFilename);
  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::istringstream linestream(line) ;
    linestream >> secondsUptime >> cpuuptime ;
  }
  filestream.close() ;
  return secondsUptime; 
}