std::string GPU_Module::findPtxFile(std::string const &myPtxFile) {
  Require(myPtxFile.length() > 0);

  // Location of GPU ptx files - read from config.h
  std::string const testDir(rtt_device::test_kernel_bindir);
  // return value
  std::string ptxFile;

  // std::cout << "Looking at:\n"
  //           << myPtxFile << "\n"
  //           << testDir + std::string("/") + myPtxFile << std::endl;

  // Find the ptx file
  if (rtt_dsxx::fileExists(myPtxFile))
    ptxFile = myPtxFile;
  else if (rtt_dsxx::fileExists(std::string("../") + myPtxFile))
    ptxFile = std::string("../") + myPtxFile;
  else if (rtt_dsxx::fileExists(testDir + std::string("/") + myPtxFile))
    ptxFile = testDir + std::string("/") + myPtxFile;

  Insist(rtt_dsxx::fileExists(ptxFile),
         (std::string("Cannot find requested file: ") + myPtxFile).c_str());

  return ptxFile;
}