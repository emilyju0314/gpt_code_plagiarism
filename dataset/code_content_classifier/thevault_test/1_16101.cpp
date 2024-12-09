long LinuxParser::UpTime() {
  string UpTime;
  string IdleTime;
  string line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);  // get string stream of each line and
                                          // " " as delimiter to get each token
    linestream >> UpTime >> IdleTime;
    return stol(UpTime);
  }
  stream.close();
  return 0;
}