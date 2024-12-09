string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);  // get string stream of each line and
                                          // " " as delimiter to get each token
    linestream >> os >> version >>
        kernel;  // store the 3rd token in string kernal
  }
  stream.close();
  return kernel;
}