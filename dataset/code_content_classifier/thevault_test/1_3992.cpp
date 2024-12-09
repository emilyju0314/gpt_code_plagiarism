GPU_Module::GPU_Module(std::string const &myPtxFile)
    : ptxFile(findPtxFile(myPtxFile)) {
  // load the module
  cudaError_enum err = cuModuleLoad(&cuModule, ptxFile.c_str());
  rtt_device::GPU_Device::checkForCudaError(err);
}