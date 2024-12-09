int LinuxParser::RunningProcesses() {
  string value = LinuxParser::GetValueFromProcStat("procs_running");
  if (value != "") {
    return stoi(value);
  }
  return 0;
}