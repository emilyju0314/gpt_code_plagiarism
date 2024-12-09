string LinuxParser::Uid(int pid) {
    string key, value,line;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "Uid:") { 
          return value;
               }
      }
    }
    }
  return string();
}