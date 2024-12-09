long LinuxParser::IdleJiffies() { 
  vector<string> jiffies = CpuUtilization();
  long idle_jiffies_since_boot = atol(jiffies[3].c_str());

  return idle_jiffies_since_boot; 
}