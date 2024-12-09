int LinuxParser::TotalProcesses() { 
  string title, totalProcess;
  string line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while(std::getline(stream, line)){
    std::istringstream linestream(line);
    linestream >> title >> totalProcess;
        if (title == "processes") {
            break;
        }
    }
  }
  
  if(totalProcess == ""){
    return 0;
  }
  return stoi(totalProcess.c_str());
}