long LinuxParser::ActiveJiffies() {
  long ActiveJiffies = 0;
  ActiveJiffies = LinuxParser::Jiffies() - LinuxParser::IdleJiffies();
  return ActiveJiffies;
}