int LinuxParser::TotalProcesses() { 
  string value = LinuxParser::GetValueFromProcStat("processes");
  if (value != "") {
    return stoi(value);
  }
  return 0;
}