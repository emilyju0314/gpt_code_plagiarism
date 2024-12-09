long LinuxParser::ActiveJiffies(int pid) {
  long ActiveJiffies = 0;
  string value, line;
  vector<string> info{};
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatFilename);
  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    
    for(int i = 0 ; i < 22 ; i++){
      linestream >> value;
      info.push_back(value);
    }
    ActiveJiffies = stol(info[13]) + stol(info[14]) + stol(info[15]) + stol(info[16]);
    
  }
  filestream.close();
  return ActiveJiffies;
}