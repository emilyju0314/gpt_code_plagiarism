string LinuxParser::User(int pid) {
  string line, key, x, value;
  string User;
  std::ifstream filestream(kPasswordPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');  // convert ':' to ' '
      std::istringstream linestream(line);
      linestream >> key >> x >> value;
      if (value == LinuxParser::Uid(pid)) {
        User = key;
        filestream.close();
        return User;
      }
    }
  }
  filestream.close();
  return string();
}