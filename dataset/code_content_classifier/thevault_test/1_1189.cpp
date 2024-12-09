long LinuxParser::UpTime(int pid) 
{
  string line,pidString,pidDirectory;
 
  long uptime,systemUptime;
  pidString = to_string(pid);
  pidDirectory = "/" + pidString;

  std::ifstream filestream(kProcDirectory + pidDirectory + kStatFilename);  
  if (filestream.is_open()) 
  {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    std::istream_iterator<std::string> begin(linestream);
    std::istream_iterator<std::string> end;
    std::vector<std::string> elemVec(begin, end);
    
    uptime = std::stol(elemVec[START_INDEX]);
    uptime = uptime /sysconf(_SC_CLK_TCK);
    systemUptime = UpTime();
    uptime = systemUptime - uptime;
  }
  else
  {
    return 0; 
  }
  
  return uptime; 
}