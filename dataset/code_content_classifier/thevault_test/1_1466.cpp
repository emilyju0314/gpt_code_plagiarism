string LinuxParser::Uid(int pid) { 
  string uid ;
  uid = to_string(ReadPidStatusFile(pid, "Uid")) ;
  return uid ;
}