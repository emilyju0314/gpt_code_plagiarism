int LinuxParser::TotalProcesses() { 
    string key;
    int total;
    string line;
    std::ifstream stream(kProcDirectory +kStatFilename);
    if (stream) {
        while(std::getline(stream,line)){
          std::istringstream linestream(line);
          linestream >> key >> total;
          if (key == "processes") {
            break;
          }        
        }
    }
    return total;
}