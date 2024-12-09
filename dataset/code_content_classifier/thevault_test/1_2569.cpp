long LinuxParser::ActiveJiffies() {
  vector<string> data = CpuUtilization();
  long active = stol(data[kUser_]) + stol(data[kNice_]) + stol(data[kSystem_]) + stol(data[kIRQ_]) +
            stol(data[kSoftIRQ_]) + stol(data[kSteal_]);
  return active;
}