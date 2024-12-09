long LinuxParser::Jiffies() {
  long TotalJiffies = 0;
  auto Jiffies = LinuxParser::CpuUtilization();
  for(auto & elem : Jiffies){
      TotalJiffies += std::stoi(elem);
  }
  return TotalJiffies;
}