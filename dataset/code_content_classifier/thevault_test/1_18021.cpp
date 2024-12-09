float LinuxParser::MemoryUtilization() { 
  string mem_total, mem_free, mem_available, buffers; 
  string title, line;
  std::ifstream stream(kProcDirectory + kMeminfoFilename);
    if (stream.is_open()) {

    for (int i = 0; i < 4; i++){
      string value;
      std::getline(stream, line);
      std::istringstream linestream(line);
      linestream >> title >> value;

      if (title == "MemTotal:") {
          mem_total = value;
          if(mem_total == ""){
            return 0;
          }
        }else if (title == "MemFree:"){
          mem_free = value;
          if(mem_free == ""){
            return 0;
          }
        }else if (title == "MemAvailable:"){
          mem_available = value;
          if(mem_available == ""){
            return 0;
          }
        }else if (title == "Buffers:"){
          buffers = value;
          if(buffers == ""){
            return 0;
          }
        }
    }
  }

  float memUtil = (stof(mem_total.c_str()) - stof(mem_free.c_str())) / stof(mem_total.c_str());
  return memUtil;
}