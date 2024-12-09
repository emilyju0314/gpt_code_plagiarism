string LinuxParser::User(int pid) { 
  long uid = ReadPidStatusFile(pid, "Uid") ;
  string line ;
  string key = "*" ;
  long value = -1 ;
  std::ifstream filestream(kPasswordPath);
  if (filestream.is_open()) {
      while (std::getline(filestream, line)) {
          std::replace(line.begin(), line.end(), ':',' ') ;
          std::istringstream linestream(line) ;
          linestream >> key >> value ;
          if (value == uid) {
            break ;
          }
      }     
  }
  filestream.close() ;
  return key ;
}