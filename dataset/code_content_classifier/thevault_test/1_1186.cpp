string LinuxParser::Ram(int pid) 
{ 
  string line,pidString,pidDirectory, vmLabel,vmSizeValue;
  float size{0};
  int intsize{0};


  pidString = to_string(pid);
  pidDirectory = "/" + pidString;

  std::ifstream filestream(kProcDirectory + pidDirectory + kStatusFilename);
  if (filestream.is_open()) 
  {
    while(std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> vmLabel >> vmSizeValue;
      if(vmLabel == "VmSize:")
      {
        size = std::stof(vmSizeValue);
        size = size * KBTOMEG;
        size = round(size);
        intsize = int(size);
        vmSizeValue = to_string(intsize); 
        break;        
      }
    }
  }
  else
  {
    return string();
  }
  

  return vmSizeValue; 
}