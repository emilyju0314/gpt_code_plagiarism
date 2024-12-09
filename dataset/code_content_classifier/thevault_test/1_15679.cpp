float Process::CpuUtilization( ) 
{
 long uptime = LinuxParser::UpTime();
 vector<float> cpuVal = LinuxParser:: CpuUtilization( Pid() );
 float totalTime    = 0.0;
 float seconds      = 0.0;
 float cpuUtil      = 0.0;


if (cpuVal.size() == (Process::totalIndecies ) )
 {
    for (int i = 0; i < (Process::totalIndecies -1) ;i++)
 {
    totalTime +=cpuVal[i];
 }
 
  totalTime /=sysconf(_SC_CLK_TCK);
  seconds = uptime - ( cpuVal[Process::starttime] / sysconf(_SC_CLK_TCK) );
  cpuUtil = (totalTime/seconds ) ;
 }
  processUtil_ = cpuUtil;
 return processUtil_;
}