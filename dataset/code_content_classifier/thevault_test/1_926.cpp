float LinuxParser::MemoryUtilization() {
  string key,value,line,k;
  float Total,Free;
  std::ifstream stream(kProcDirectory  + kMeminfoFilename);
  if(stream.is_open()) {
    while(std::getline(stream,line)) {
      std::replace(line.begin(),line.end(),':',' ');
      std::istringstream linestream(line);
    while(linestream>>key>>value>>k) {
      if(key=="MemTotal") {Total = std::stof(value);}
      if(key=="MemFree") {Free = std::stof(value);}
    }
    }
    return (Total-Free)/Total;
  }
  else
    return 0.0;
}