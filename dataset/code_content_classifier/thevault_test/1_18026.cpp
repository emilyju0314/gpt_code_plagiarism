int LinuxParser::RunningProcesses() {
  string title, runningProcess;
  string line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while(std::getline(stream, line)){
    std::istringstream linestream(line);
    linestream >> title >> runningProcess;
        if (title == "procs_running") {
            break;
        }
    }
  }
  if(runningProcess == ""){
    return 0;
  }
  return stoi(runningProcess.c_str());
}