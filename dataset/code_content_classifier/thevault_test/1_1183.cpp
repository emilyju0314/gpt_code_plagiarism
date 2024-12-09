long LinuxParser::UpTime() 
{ 
  std::ifstream filestream(kProcDirectory + kUptimeFilename);  
  string line;
  string upTime,dummy;
  long upTimelong;

  if (filestream.is_open())
  {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> upTime;
    upTimelong = std::stol(upTime);
  }
  else
  {
    return 0;
  }
  
  return upTimelong; 
}