vector<string> LinuxParser::CpuUtilization() {
  string line;
  vector<string> CpuUtilization;
  string key, user, nice, system, idle, iowait, irq, softirq, steal, guest,
      guest_nice;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    // only read the first row
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> key >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal >> guest >> guest_nice;
    CpuUtilization.push_back(user);
    CpuUtilization.push_back(nice);
    CpuUtilization.push_back(system);
    CpuUtilization.push_back(idle);
    CpuUtilization.push_back(iowait);
    CpuUtilization.push_back(irq);
    CpuUtilization.push_back(softirq);
    CpuUtilization.push_back(steal);
    CpuUtilization.push_back(guest);
    CpuUtilization.push_back(guest_nice);

    return CpuUtilization;
  }
  filestream.close();
  return CpuUtilization;
}