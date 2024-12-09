void print_stat(int stat, 
                const std::string& prefix, 
                const std::string& path) {
  if (stat == ZNONODE) {
    std::cerr << prefix << ": Node missing" << path << std::endl;
  }
  else if (stat == ZNOAUTH) {
    std::cerr << prefix << ": No permission to list children of node " 
              << path << std::endl;
  }
  else if (stat == ZNODEEXISTS) {
    std::cerr << prefix << ": Node " << path << " already exists." << std::endl;
  }
  else if (stat == ZNOTEMPTY) {
    std::cerr << prefix << ": Node " << path << " not empty." << std::endl;
  }
  else if (stat != ZOK) {
    std::cerr << prefix << ": Unexpected error " << stat 
              << " on path " << path << std::endl;
  }
}