string LinuxParser::User(int pid) 
{ 
  string userID = Uid(pid);
  string line, userName, x, userIDstring,token;

  std::ifstream filestream(kPasswordPath);

  if(filestream.is_open())
  {
    while(std::getline(filestream, line))
    {
      
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      linestream >> userName >> x >> userIDstring;

      if(userIDstring == userID)
      {
        break;
      }
    }
  }
  else
  {
    return string();
  }
  
  return userName;
}