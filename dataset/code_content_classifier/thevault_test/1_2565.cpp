float LinuxParser::MemoryUtilization() { 
  float data,MemTotal,MemFree,Buffers;
  string line, key;
    std::ifstream stream(kProcDirectory + kMeminfoFilename);
  if(stream){
    while(std::getline(stream,line)) {
      std::istringstream linestream(line);
      linestream >> key >> data;
      if (key == "MemTotal:") MemTotal= data;
      else if (key == "MemFree:") MemFree = data;
      else if (key == "Buffers:") {
        Buffers = data;
        break;
      }
    }
  }
  float TotalUsedMem = MemTotal - MemFree;
  float UsedMem = TotalUsedMem - Buffers; 
  return (UsedMem/MemTotal) ;
}