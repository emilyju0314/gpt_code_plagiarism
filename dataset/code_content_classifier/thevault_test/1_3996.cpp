GPU_Device::GPU_Device(void)
    : deviceCount(0), computeCapability(), deviceName() {
  // Initialize the library
  cudaError_enum err = cuInit(0); // currently must be 0.
  checkForCudaError(err);

  // Get a device count, determine compute capability
  err = cuDeviceGetCount(&deviceCount);
  checkForCudaError(err);
  Insist(deviceCount > 0, "No GPU devices found!");

  // Collect information about each GPU device found
  computeCapability.resize(deviceCount);

  for (int device = 0; device < deviceCount; device++) {
    CUdevice cuDevice;
    err = cuDeviceGet(&cuDevice, device);
    checkForCudaError(err);

    // Compute capability revision
    int major = 0;
    int minor = 0;
    cuDeviceGetAttribute(&major, CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR,
                         cuDevice);
    cuDeviceGetAttribute(&minor, CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR,
                         cuDevice);
    computeCapability[device].push_back(major);
    computeCapability[device].push_back(minor);

    // Device name
    char name[200];
    err = cuDeviceGetName(name, 200, cuDevice);
    checkForCudaError(err);
    deviceName.push_back(std::string(name));

    // Query and archive device properties.
    {
      int tmp1(0), tmp2(0), tmp3(0);
      err = cuDeviceGetAttribute(
          &tmp1, CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK, cuDevice);
      checkForCudaError(err);
      m_maxthreadsperblock.push_back(tmp1);

      err = cuDeviceGetAttribute(&tmp1, CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
                                 cuDevice);
      checkForCudaError(err);
      err = cuDeviceGetAttribute(&tmp2, CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
                                 cuDevice);
      checkForCudaError(err);
      err = cuDeviceGetAttribute(&tmp3, CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
                                 cuDevice);
      checkForCudaError(err);
      m_maxthreadsdim.push_back(std::array<int, 3>{tmp1, tmp2, tmp3});

      err = cuDeviceGetAttribute(&tmp1, CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
                                 cuDevice);
      checkForCudaError(err);
      err = cuDeviceGetAttribute(&tmp2, CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
                                 cuDevice);
      checkForCudaError(err);
      err = cuDeviceGetAttribute(&tmp3, CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
                                 cuDevice);
      checkForCudaError(err);
      m_maxgridsize.push_back(std::array<int, 3>{tmp1, tmp2, tmp3});

      err = cuDeviceGetAttribute(
          &tmp1, CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK, cuDevice);
      checkForCudaError(err);
      m_sharedmemperblock.push_back(tmp1);

      err = cuDeviceGetAttribute(
          &tmp1, CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY, cuDevice);
      checkForCudaError(err);
      m_totalconstantmemory.push_back(tmp1);

      err =
          cuDeviceGetAttribute(&tmp1, CU_DEVICE_ATTRIBUTE_WARP_SIZE, cuDevice);
      checkForCudaError(err);
      m_simdwidth.push_back(tmp1);

      err =
          cuDeviceGetAttribute(&tmp1, CU_DEVICE_ATTRIBUTE_MAX_PITCH, cuDevice);
      checkForCudaError(err);
      m_mempitch.push_back(tmp1);

      err = cuDeviceGetAttribute(
          &tmp1, CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK, cuDevice);
      checkForCudaError(err);
      m_regsperblock.push_back(tmp1);

      err =
          cuDeviceGetAttribute(&tmp1, CU_DEVICE_ATTRIBUTE_CLOCK_RATE, cuDevice);
      checkForCudaError(err);
      m_clockrate.push_back(tmp1);

      err = cuDeviceGetAttribute(&tmp1, CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
                                 cuDevice);
      checkForCudaError(err);
      m_texturealign.push_back(tmp1);
    }

    // CUdevprop_st properties;
    // err = cuDeviceGetProperties(&properties, cuDevice);
    // checkForCudaError(err);
    // deviceProperties.push_back(properties);
  }

  // Save the handle and context for each device
  device_handle.resize(2);
  context.resize(2);
  for (int device = 0; device < deviceCount; device++) {
    // Only initialize if compute capability >= 2.0
    if (computeCapability[device][0] >= 2) {
      // Save the handle for each device
      err = cuDeviceGet(&device_handle[device], device);
      checkForCudaError(err);

      // Save the handle for each context
      err = cuCtxCreate(&context[device], device, device_handle[device]);
      checkForCudaError(err);
    }
  }
}