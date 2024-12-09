long LinuxParser::IdleJiffies() {
  long IdleJiffies = 0;
  vector<string> CpuUtilization = LinuxParser::CpuUtilization();
  for (int i = 3; i <= 4; i++) {
    IdleJiffies += stol(CpuUtilization[i]);
  }
  return IdleJiffies;
}