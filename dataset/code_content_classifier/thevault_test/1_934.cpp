string LinuxParser::User(int pid) {
  string user, pass, key, line;
  string uid_ = LinuxParser::Uid(pid);
  std::ifstream stream(kPasswordPath);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
        std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
    	while (linestream >> user >> pass >> key) {
               if (key==uid_){
                return user;
               }
        }
    }
  }
  return string();
}