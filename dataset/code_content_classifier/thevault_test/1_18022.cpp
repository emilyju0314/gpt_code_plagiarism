long LinuxParser::UpTime() { 
  string upTime, waitTime, line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> upTime >> waitTime;
  }

  return atol(upTime.c_str());
}