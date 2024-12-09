string LinuxParser::Uid(int pid) 
{ 
  string pidString,line,pidDirectory,Uidlabel, UidValue;
  pidString = to_string(pid);

  pidDirectory = "/" + pidString;
  std::ifstream filestream(kProcDirectory + pidDirectory + kStatusFilename);
  if (filestream.is_open()) 
  {
    
    while(std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> Uidlabel >> UidValue;
      if(Uidlabel == "Uid:")
      {
        break;
      }
    }

  }
  else
  {
    return string(); 
  }
 
  return UidValue;
}