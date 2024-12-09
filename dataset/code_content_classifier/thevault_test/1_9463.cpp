int LinuxParser::RunningProcesses() {
  return getFileValueByKey<int>(kProcDirectory + kStatFilename,
                                filterRunningProcesses);
  ;
}