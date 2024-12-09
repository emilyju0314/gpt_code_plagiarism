float LinuxParser::MemoryUtilization() { 
  string line = "" ;
  string key ;
  int value;
  float perc_utilization = 0.0 ;
  float total_memory = 0.0 ;
  float avail_memory = 0.0 ;
  int counter = 0 ;
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);

  if (filestream.is_open()) {
    while ((std::getline(filestream, line)) && counter < 2) {
      std::replace(line.begin(), line.end(), ':', ' ') ;
      std::istringstream linestream(line) ;
      linestream >> key >> value  ;
      if (key == "MemTotal") {
        total_memory = value ;
        counter += 1 ;
      }
      else if (key == "MemFree") {
        avail_memory = value ;
        counter += 1 ;
      }
    }
  }
  filestream.close();
  if (total_memory > 0) {
      perc_utilization = ((total_memory - avail_memory) / total_memory) ;
  }
  else {
    cout << "From LinuxParse.cpp: MemoryUtilization - Total_memory is 0 or " << total_memory << "\n";
  }
  return perc_utilization; 
  }