string LinuxParser::Command(int pid) { 
  string line, cmd;
  std::ifstream stream(kProcDirectory + to_string(pid) + kCmdlineFilename);
  if (stream.is_open()){
    std::getline(stream, line);
    for (int i = 0; i < 50; i++){
        cmd = cmd + line[i];
    }
  }
  return cmd; 
}