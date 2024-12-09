string LinuxParser::Command(int pid) { 
  string line ;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kCmdlineFilename) ;
  if (filestream.is_open()) {
      std::getline(filestream, line) ;
  }
  filestream.close() ;
  return line; 
}