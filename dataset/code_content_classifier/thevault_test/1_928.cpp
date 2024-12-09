long LinuxParser::ActiveJiffies(int pid) {
string value,line;
  long total_time;
vector<string> time_list;
std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
if(stream.is_open()) {
  std::getline(stream, line);
  std::istringstream linestream(line);
  while(linestream>>value) {
    time_list.push_back(value);
  }
}
  total_time = std::stol(time_list[13])+std::stol(time_list[14])+std::stol(time_list[15])+std::stol(time_list[16]);
  return total_time;
}