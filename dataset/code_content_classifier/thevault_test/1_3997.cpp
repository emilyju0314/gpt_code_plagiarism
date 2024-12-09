GPU_Device::~GPU_Device() {
  // Free reserved contexts:
  for (int device = 0; device < deviceCount; device++) {
    // Only initialize if compute capability >= 2.0
    if (computeCapability[device][0] >= 2) {
      cudaError_enum err = cuCtxDestroy(context[device]);
      checkForCudaError(err);
    }
  }
}