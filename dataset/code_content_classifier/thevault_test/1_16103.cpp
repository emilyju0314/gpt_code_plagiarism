long LinuxParser::Jiffies() {
  long Jiffies = 0;
  vector<string> CpuUtilization = LinuxParser::CpuUtilization();
  for (int i = 0; i < 8; i++) {
    Jiffies += stol(CpuUtilization[i]);
  }
  return Jiffies;
}