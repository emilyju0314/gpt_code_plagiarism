float LinuxParser::MemoryUtilization() {
  float tot_mem = getFileValueByKey<float>(kProcDirectory + kMeminfoFilename,
                                           filterMemTotalString);
  float avail_mem = getFileValueByKey<float>(kProcDirectory + kMeminfoFilename,
                                             filterMemAvailableString);
  return (tot_mem - avail_mem) / tot_mem;
}