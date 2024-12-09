string LinuxParser::Uid(int pid) { 
  string name = "Uid";
  string title, value;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  string line;
  while (std::getline(stream, line)){
    if(line.compare(0, name.size(), name) == 0){
      std::istringstream linestream(line);
      linestream >> title >> value;
      break;
    }
  }
  return value; 
}