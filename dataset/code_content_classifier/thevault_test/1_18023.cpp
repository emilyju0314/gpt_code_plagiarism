long LinuxParser::Jiffies() { 
    vector<string> jiffies = CpuUtilization();
  long total_jiffies_since_boot = 0;
  for(string s : jiffies){
    total_jiffies_since_boot += atol(s.c_str());
  }
  return total_jiffies_since_boot; 
}