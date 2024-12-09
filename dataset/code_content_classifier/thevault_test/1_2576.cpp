string LinuxParser::User(int pid) {
  string key,temp_user,buffer,user;
  string line;
  string uid = LinuxParser::Uid(pid);
  std::ifstream stream(kPasswordPath);
  if (stream) {
    while(std::getline(stream, line)){
        std::replace(line.begin(), line.end(), ':', ' ');
        std::istringstream linestream(line);
        linestream >> temp_user >> buffer >> key;
        if (uid == key) {
          user = temp_user;
          break;
        }
    }  
  }
  return user;
}