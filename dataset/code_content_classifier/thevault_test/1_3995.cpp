CUfunction
GPU_Module::getModuleFunction(std::string const &functionName) const {
  // Load the kernel from the module
  CUfunction kernel;
  cudaError_enum err =
      cuModuleGetFunction(&kernel, cuModule, functionName.c_str());
  GPU_Device::checkForCudaError(err);
  return kernel;
}