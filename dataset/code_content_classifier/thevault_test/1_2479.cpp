GPU_Device::GPU_Device(void) : deviceCount(0), computeCapability(), deviceName() {

  // Get a device count, determine compute capability
  cudaError_t err = cudaGetDeviceCount(&deviceCount);
  checkForCudaError(err);
  Insist(deviceCount > 0, "No GPU devices found!");

  // Collect information about each GPU device found
  computeCapability.resize(deviceCount);

  for (int device = 0; device < deviceCount; device++) {
    int cudaDevice;
    err = cudaSetDevice(device);
    checkForCudaError(err);
    err = cudaGetDevice(&cudaDevice);
    checkForCudaError(err);
    Check(cudaDevice == device);

    // Compute capability revision
    int major = 0;
    int minor = 0;
    cudaDeviceGetAttribute(&major, cudaDevAttrComputeCapabilityMajor, device);
    cudaDeviceGetAttribute(&minor, cudaDevAttrComputeCapabilityMinor, device);
    computeCapability[device].push_back(major);
    computeCapability[device].push_back(minor);

    // Device name
    cudaDeviceProp device_properties;
    err = cudaGetDeviceProperties(&device_properties, device);
    checkForCudaError(err);
    deviceName.push_back(std::string(device_properties.name));

    // Query and archive device properties.
    {
      int tmp(0);
      m_maxthreadsperblock.push_back(device_properties.maxThreadsPerBlock);
      m_maxthreadsdim.push_back(std::array<int, 3>{device_properties.maxThreadsDim[0],
                                                   device_properties.maxThreadsDim[1],
                                                   device_properties.maxThreadsDim[2]});
      m_maxgridsize.push_back(std::array<int, 3>{device_properties.maxGridSize[0],
                                                 device_properties.maxGridSize[1],
                                                 device_properties.maxGridSize[2]});
      m_sharedmemperblock.push_back(device_properties.sharedMemPerBlock);

      err = cudaDeviceGetAttribute(&tmp, cudaDevAttrTotalConstantMemory, device);
      checkForCudaError(err);
      m_totalconstantmemory.push_back(tmp);

      m_simdwidth.push_back(device_properties.warpSize);
      m_mempitch.push_back(device_properties.memPitch);

      err = cudaDeviceGetAttribute(&tmp, cudaDevAttrMaxRegistersPerBlock, device);
      checkForCudaError(err);
      m_regsperblock.push_back(tmp);

      err = cudaDeviceGetAttribute(&tmp, cudaDevAttrClockRate, device);
      checkForCudaError(err);
      m_clockrate.push_back(tmp);

      err = cudaDeviceGetAttribute(&tmp, cudaDevAttrTextureAlignment, device);
      checkForCudaError(err);
      m_texturealign.push_back(tmp);
    }
  }
}