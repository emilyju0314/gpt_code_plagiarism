long LinuxParser::ActiveJiffies(int pid) {
  string line, info;
  long total = 0;
  int i = 0;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatFilename);
  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    // Tokenize
    while (std::getline(linestream, info, ' ')) {
      if ((i == 13) || (i == 14) || (i == 15)) {
        total += stol(info);
        i++;
        continue;
      } else if (i == 16) {
        total += stol(info);
        break;
      }
      i++;
    }
  }
  return total;
}