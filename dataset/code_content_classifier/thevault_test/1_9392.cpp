int LinuxParser::TotalProcesses() {
  string line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  string mark{"processes"};
  string res;
  if (stream) {
    while (std::getline(stream, line)) {
      if (line.compare(0, mark.size(), mark) == 0) {
        std::istringstream buf(line);
        std::istream_iterator<string> beg(buf), end;
        vector<string> words(beg, end);
        return std::stoi(words[1]);
      }
    }
  } else {
    throw std::runtime_error("no such file");
  }

  return 0;
}