string LinuxParser::Ram(int pid) { 
  long ram ;
  ram =  ReadPidStatusFile(pid, "VmSize")/1024 ;
  return to_string(ram) ;
}