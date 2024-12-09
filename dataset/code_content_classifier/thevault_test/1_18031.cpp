long LinuxParser::UpTime(int pid) { 
  string line, value;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  std::getline(stream, line);
  std::istringstream linestream(line);
  std::istream_iterator<string> beg(linestream), end;
  vector<string> values(beg, end);

  float seconds = float(stof(values[21].c_str()) / sysconf(_SC_CLK_TCK));
  return seconds; 
}