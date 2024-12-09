long LinuxParser::Jiffies() { 
  long jiffies;
  jiffies = ActiveJiffies() + IdleJiffies();
  return jiffies;
}