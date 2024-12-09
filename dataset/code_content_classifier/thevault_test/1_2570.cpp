long LinuxParser::IdleJiffies() {
  long idle ;
  vector<string> data = CpuUtilization();
  idle = stol(data[kIdle_]) + stol(data[kIOwait_]);
  return idle;
}