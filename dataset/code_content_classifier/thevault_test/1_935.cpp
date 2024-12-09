long LinuxParser::UpTime(int pid) {
  string value, line;
  long int start_time, uptime;
  vector<string> time_list;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (linestream >> value) {
			time_list.push_back(value);
        }
  start_time = std::stol(time_list[21])/sysconf(_SC_CLK_TCK);
  uptime =  LinuxParser::UpTime() - start_time;
  return uptime;
  }
  return 0;
}