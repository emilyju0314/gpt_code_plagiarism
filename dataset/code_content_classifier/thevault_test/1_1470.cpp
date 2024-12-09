void LinuxParser::ReadProcStatFile(vector<string> &statRecord) {
  string key;
  string value ;
  string line ;
  std::ifstream filestream(kProcDirectory + kStatFilename) ;
  int recordCounter = 0 ;
  if (filestream.is_open()) {
    while(std::getline(filestream, line) && recordCounter < 3) {
        std::istringstream linestream(line) ;
        linestream >> key ;
        if (key == "cpu") {
            while(linestream >> value) {
              statRecord.emplace_back(value) ; 
            }
            recordCounter += 1;
        }
        if (key == "processes") {
          linestream >> value ;
          statRecord.emplace_back(value) ;
          recordCounter += 1;
        }
        if (key == "procs_running") {
          linestream >> value ;
          statRecord.emplace_back(value) ;
          recordCounter += 1;
         }
    }
  }
  filestream.close() ;
}