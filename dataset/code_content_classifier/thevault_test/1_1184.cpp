int LinuxParser::TotalProcesses() 
{ 
  std::ifstream filestream(kProcDirectory + kStatFilename);
  string processName,processNumber;
  int processNumberInt;
  string line;
  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
      {
        std::istringstream linestream(line);
        linestream >> processName >> processNumber;
        if(processName == "processes")
        {
          processNumberInt = std::stoi(processNumber);
          break;
        }

      }
  }
  return processNumberInt; 
}