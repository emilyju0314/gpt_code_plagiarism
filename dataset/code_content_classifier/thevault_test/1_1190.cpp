float LinuxParser::ProcessCpuUtil(int pid) 
{ 
  string line,pidString,pidDirectory;
  long systemUptime = UpTime();
  long uTime,sTime,cuTime, csTime,startTime, totalTime, seconds;
  float cpuUsage{0};

  pidString = to_string(pid);
  pidDirectory = "/" + pidString;

  std::ifstream filestream(kProcDirectory + pidDirectory + kStatFilename);
  if (filestream.is_open()) 
  {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    std::istream_iterator<std::string> begin(linestream);
    std::istream_iterator<std::string> end;
    std::vector<std::string> elemVec(begin, end);

    uTime = std::stol(elemVec[UTIME_INDEX]);
    sTime = std::stol(elemVec[STIME_INDEX]);
    cuTime = std::stol(elemVec[CUTIME_INDEX]);
    csTime = std::stol(elemVec[CSTIME_INDEX]);
    startTime = std::stol(elemVec[START_INDEX]);

    totalTime = uTime + sTime + cuTime + csTime;

    seconds = systemUptime - (startTime / sysconf(_SC_CLK_TCK) );
    cpuUsage = (float((totalTime / sysconf(_SC_CLK_TCK))) / float(seconds));
  }
  else
  {
    return 0; 
  }

  return cpuUsage; 
}