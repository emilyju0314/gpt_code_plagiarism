string LinuxParser::Command(int pid) {
  string Command;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kCmdlineFilename);
  if (filestream.is_open()) {
    std::getline(filestream, Command);
    return Command;
  }
  filestream.close();
  return "no command";
}