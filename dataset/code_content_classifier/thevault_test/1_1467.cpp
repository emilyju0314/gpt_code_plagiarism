long LinuxParser::UpTime(int pid) { 
    long pidStartTime = ReadPidStatFile(pid, "StartTime")/sysconf(_SC_CLK_TCK) ;
    long systemUpTime = UpTime() ;
    long pidUpTime = systemUpTime - pidStartTime ;
    return pidUpTime ;
}