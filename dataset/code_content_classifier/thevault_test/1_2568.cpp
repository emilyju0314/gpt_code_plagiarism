long LinuxParser::ActiveJiffies(int pid) {
  vector<std::string> data;
  string line;
  long jiffies = 0;
  std::ifstream filestream(kProcDirectory + "/" + std::to_string(pid) +kStatFilename);
  if (filestream) {
    std::getline(filestream, line);
    std::stringstream sstream(line);
    while (std::getline(sstream, line, ' ')) {
      data.push_back(line);
    }
    for (int ii =13;ii <17;ii++){
      jiffies+= std::stol(data[ii]);
    }
  }
  return jiffies;
}