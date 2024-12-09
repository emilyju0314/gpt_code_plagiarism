void *GPU_Device::MemAlloc(unsigned const nbytes) {
  void *ptr;
  cudaError_t err = cudaMalloc(&ptr, nbytes);
  checkForCudaError(err);
  return ptr;
}