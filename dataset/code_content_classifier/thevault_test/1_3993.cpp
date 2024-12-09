GPU_Module::~GPU_Module() {
  // Unload the module
  cudaError_enum err = cuModuleUnload(cuModule);
  rtt_device::GPU_Device::checkForCudaError(err);
}