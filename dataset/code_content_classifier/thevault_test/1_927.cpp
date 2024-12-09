long LinuxParser::UpTime() {  
  long up_Time;
  string line;
  std::ifstream stream(kProcDirectory+kUptimeFilename);
  if(stream.is_open()) {
    std::getline(stream,line);
    std::istringstream linestream(line);
    linestream>>up_Time;
  return up_Time;
  }
  else
    return 0;
  }