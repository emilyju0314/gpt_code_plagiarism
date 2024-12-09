float LinuxParser::CalculateCpuUtilization (int pid) {
    float cpuUsage = 0;
    //long  systemUptime = UpTime();
    float totalCpu = ActiveJiffies(pid)/sysconf(_SC_CLK_TCK);
    float startTimeSeconds = UpTime(pid) ;
    //float netCpu = systemUptime - startTimeSeconds ;
    if (startTimeSeconds == 0) {
        cpuUsage = 0 ;
    }
    else {
        cpuUsage = totalCpu / startTimeSeconds ;
    }
    return cpuUsage ;
}