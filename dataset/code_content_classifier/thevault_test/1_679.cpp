long LinuxParser::IdleJiffies() { 
  long total = 0;
  vector<string> cpuUtilization = LinuxParser::CpuUtilization();
  for(int i = kIdle_; i <= kIOwait_; i++) {
    total += stol(cpuUtilization[i]);
  }
  return total; 
}