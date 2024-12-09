string LinuxParser::User(int pid) { 
  string name = "x:" + Uid(pid);
  string title, value;
  std::ifstream stream(kPasswordPath);
  string line;
  while (std::getline(stream, line)){
    if(line.find(name) != std::string::npos){
      value = line.substr(0, line.find(":"));
    }
  }
  return value; 
}