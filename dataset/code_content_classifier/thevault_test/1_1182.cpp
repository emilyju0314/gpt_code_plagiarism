float LinuxParser::MemoryUtilization() 
{ 
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  string line;
  string memTotalStringValue;
  string memTotalName;
  float memTotalValue;

  string memFreeStringValue;
  string memFreeName;
  float memFreeValue;

  float utlMem = 0;

  if (filestream.is_open()) 
  {
    std::getline(filestream, line);
    std::istringstream linestream(line);

    linestream >> memTotalName >> memTotalStringValue;
    memTotalValue = std::stof(memTotalStringValue);

    std::getline(filestream, line);
    std::istringstream linestream2(line);
    linestream2 >> memFreeName >> memFreeStringValue;
    memFreeValue = std::stof(memFreeStringValue);

    utlMem = (memTotalValue - memFreeValue)/memTotalValue;
  }
  else
  {
    return 0.0;
  }
  
  return utlMem; 
}