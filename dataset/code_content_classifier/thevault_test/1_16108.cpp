int LinuxParser::RunningProcesses() {
  int RunningProcesses;
  string key, value, line;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == "procs_running" && value != "") {
        RunningProcesses = stoi(value);
        return RunningProcesses;
      }
    }
  }
  filestream.close();
  return 0;
}