int OpenclDevice::ThresholdRectToPixOCL(unsigned char *imageData, int bytes_per_pixel,
                                        int bytes_per_line, int *thresholds, int *hi_values,
                                        Image *pix, int height, int width, int top, int left) {
  int retVal = 0;
  /* create pix result buffer */
  *pix = pixCreate(width, height, 1);
  uint32_t *pixData = pixGetData(*pix);
  int wpl = pixGetWpl(*pix);
  int pixSize = wpl * height * sizeof(uint32_t); // number of pixels

  cl_int clStatus;
  KernelEnv rEnv;
  SetKernelEnv(&rEnv);

  /* setup work group size parameters */
  int block_size = 256;
  cl_uint numCUs = 6;
  clStatus = clGetDeviceInfo(gpuEnv.mpDevID, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(numCUs), &numCUs,
                             nullptr);
  CHECK_OPENCL(clStatus, "clCreateBuffer imageBuffer");

  int requestedOccupancy = 10;
  int numWorkGroups = numCUs * requestedOccupancy;
  int numThreads = block_size * numWorkGroups;
  size_t local_work_size[] = {(size_t)block_size};
  size_t global_work_size[] = {(size_t)numThreads};

  /* map imagedata to device as read only */
  // USE_HOST_PTR uses onion+ bus which is slowest option; also happens to be
  // coherent which we don't need.
  // faster option would be to allocate initial image buffer
  // using a garlic bus memory type
  cl_mem imageBuffer =
      clCreateBuffer(rEnv.mpkContext, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     width * height * bytes_per_pixel * sizeof(char), imageData, &clStatus);
  CHECK_OPENCL(clStatus, "clCreateBuffer imageBuffer");

  /* map pix as write only */
  pixThBuffer = clCreateBuffer(rEnv.mpkContext, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, pixSize,
                               pixData, &clStatus);
  CHECK_OPENCL(clStatus, "clCreateBuffer pix");

  /* map thresholds and hi_values */
  cl_mem thresholdsBuffer = clCreateBuffer(rEnv.mpkContext, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                                           bytes_per_pixel * sizeof(int), thresholds, &clStatus);
  CHECK_OPENCL(clStatus, "clCreateBuffer thresholdBuffer");
  cl_mem hiValuesBuffer = clCreateBuffer(rEnv.mpkContext, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                                         bytes_per_pixel * sizeof(int), hi_values, &clStatus);
  CHECK_OPENCL(clStatus, "clCreateBuffer hiValuesBuffer");

  /* compile kernel */
  if (bytes_per_pixel == 4) {
    rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "kernel_ThresholdRectToPix", &clStatus);
    CHECK_OPENCL(clStatus, "clCreateKernel kernel_ThresholdRectToPix");
  } else {
    rEnv.mpkKernel =
        clCreateKernel(rEnv.mpkProgram, "kernel_ThresholdRectToPix_OneChan", &clStatus);
    CHECK_OPENCL(clStatus, "clCreateKernel kernel_ThresholdRectToPix_OneChan");
  }

  /* set kernel arguments */
  clStatus = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &imageBuffer);
  CHECK_OPENCL(clStatus, "clSetKernelArg imageBuffer");
  clStatus = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(int), &height);
  CHECK_OPENCL(clStatus, "clSetKernelArg height");
  clStatus = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(int), &width);
  CHECK_OPENCL(clStatus, "clSetKernelArg width");
  clStatus = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(int), &wpl);
  CHECK_OPENCL(clStatus, "clSetKernelArg wpl");
  clStatus = clSetKernelArg(rEnv.mpkKernel, 4, sizeof(cl_mem), &thresholdsBuffer);
  CHECK_OPENCL(clStatus, "clSetKernelArg thresholdsBuffer");
  clStatus = clSetKernelArg(rEnv.mpkKernel, 5, sizeof(cl_mem), &hiValuesBuffer);
  CHECK_OPENCL(clStatus, "clSetKernelArg hiValuesBuffer");
  clStatus = clSetKernelArg(rEnv.mpkKernel, 6, sizeof(cl_mem), &pixThBuffer);
  CHECK_OPENCL(clStatus, "clSetKernelArg pixThBuffer");

  /* launch kernel & wait */
  clStatus = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 1, nullptr, global_work_size,
                                    local_work_size, 0, nullptr, nullptr);
  CHECK_OPENCL(clStatus, "clEnqueueNDRangeKernel kernel_ThresholdRectToPix");
  clFinish(rEnv.mpkCmdQueue);
  if (clStatus != 0) {
    tprintf("Setting return value to -1\n");
    retVal = -1;
  }
  /* map results back from gpu */
  void *ptr = clEnqueueMapBuffer(rEnv.mpkCmdQueue, pixThBuffer, CL_TRUE, CL_MAP_READ, 0, pixSize, 0,
                                 nullptr, nullptr, &clStatus);
  CHECK_OPENCL(clStatus, "clEnqueueMapBuffer histogramBuffer");
  clEnqueueUnmapMemObject(rEnv.mpkCmdQueue, pixThBuffer, ptr, 0, nullptr, nullptr);

  clReleaseMemObject(imageBuffer);
  clReleaseMemObject(thresholdsBuffer);
  clReleaseMemObject(hiValuesBuffer);

  return retVal;
}