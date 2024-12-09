string LinuxParser::Command(int pid) 
{ 
  string line,pidString,pidDirectory;
  pidString = to_string(pid);
  pidDirectory = "/" + pidString;

  std::ifstream filestream(kProcDirectory + pidDirectory + kCmdlineFilename);
  if (filestream.is_open()) 
  {
    std::getline(filestream, line);
  }
  else
  {
    return string(); 
  }
  
  return line; 
}