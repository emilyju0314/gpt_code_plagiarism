string LinuxParser::Ram(int pid) {
  string key, value, k, line;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
      std::istringstream linestream(line);
      while (linestream >> key >> value >> k) {
        if (key == "VmSize:") { 
          return std::to_string(std::stoi(value)/1000);
               }
        	}
      	}
    }
  return string();
}