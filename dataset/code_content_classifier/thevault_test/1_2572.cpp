int LinuxParser::RunningProcesses() {    
    string key;
    int running;
    string line;
    std::ifstream stream(kProcDirectory +kStatFilename);
    if (stream) {
        while(std::getline(stream,line)){
          std::istringstream linestream(line);
          linestream >> key >> running;
          if (key == "procs_running") {
              break;
            }
        }
    }
    return running;
}