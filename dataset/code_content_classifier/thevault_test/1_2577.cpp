long LinuxParser::UpTime(int pid) {
  long up_time;
  string temp;
  vector<string> data;
  string line;
  std::ifstream stream(kProcDirectory + "/" + to_string(pid) + kStatFilename);
  if (stream) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while(linestream >> temp){
    data.push_back(temp);
    }
  }
  return up_time =(UpTime() - stol(data[21])/sysconf(_SC_CLK_TCK));
}