CUdeviceptr GPU_Device::MemAlloc(unsigned const nbytes) {
  CUdeviceptr ptr;
  cudaError_enum err = cuMemAlloc(&ptr, nbytes);
  checkForCudaError(err);
  return ptr;
}