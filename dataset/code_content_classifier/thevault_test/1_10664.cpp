int OpenclDevice::HistogramRectOCL(void *imageData, int bytes_per_pixel, int bytes_per_line,
                                   int left, // always 0
                                   int top,  // always 0
                                   int width, int height, int kHistogramSize,
                                   int *histogramAllChannels) {
  cl_int clStatus;
  int retVal = 0;
  KernelEnv histKern;
  SetKernelEnv(&histKern);
  KernelEnv histRedKern;
  SetKernelEnv(&histRedKern);
  /* map imagedata to device as read only */
  // USE_HOST_PTR uses onion+ bus which is slowest option; also happens to be
  // coherent which we don't need.
  // faster option would be to allocate initial image buffer
  // using a garlic bus memory type
  cl_mem imageBuffer =
      clCreateBuffer(histKern.mpkContext, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                     width * height * bytes_per_pixel * sizeof(char), imageData, &clStatus);
  CHECK_OPENCL(clStatus, "clCreateBuffer imageBuffer");

  /* setup work group size parameters */
  int block_size = 256;
  cl_uint numCUs;
  clStatus = clGetDeviceInfo(gpuEnv.mpDevID, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(numCUs), &numCUs,
                             nullptr);
  CHECK_OPENCL(clStatus, "clCreateBuffer imageBuffer");

  int requestedOccupancy = 10;
  int numWorkGroups = numCUs * requestedOccupancy;
  int numThreads = block_size * numWorkGroups;
  size_t local_work_size[] = {static_cast<size_t>(block_size)};
  size_t global_work_size[] = {static_cast<size_t>(numThreads)};
  size_t red_global_work_size[] = {
      static_cast<size_t>(block_size * kHistogramSize * bytes_per_pixel)};

  /* map histogramAllChannels as write only */

  cl_mem histogramBuffer = clCreateBuffer(
      histKern.mpkContext, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,
      kHistogramSize * bytes_per_pixel * sizeof(int), histogramAllChannels, &clStatus);
  CHECK_OPENCL(clStatus, "clCreateBuffer histogramBuffer");

  /* intermediate histogram buffer */
  int histRed = 256;
  int tmpHistogramBins = kHistogramSize * bytes_per_pixel * histRed;

  cl_mem tmpHistogramBuffer =
      clCreateBuffer(histKern.mpkContext, CL_MEM_READ_WRITE, tmpHistogramBins * sizeof(cl_uint),
                     nullptr, &clStatus);
  CHECK_OPENCL(clStatus, "clCreateBuffer tmpHistogramBuffer");

  /* atomic sync buffer */
  int *zeroBuffer = new int[1];
  zeroBuffer[0] = 0;
  cl_mem atomicSyncBuffer =
      clCreateBuffer(histKern.mpkContext, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, sizeof(cl_int),
                     zeroBuffer, &clStatus);
  CHECK_OPENCL(clStatus, "clCreateBuffer atomicSyncBuffer");
  delete[] zeroBuffer;
  // Create kernel objects based on bytes_per_pixel
  if (bytes_per_pixel == 1) {
    histKern.mpkKernel =
        clCreateKernel(histKern.mpkProgram, "kernel_HistogramRectOneChannel", &clStatus);
    CHECK_OPENCL(clStatus, "clCreateKernel kernel_HistogramRectOneChannel");

    histRedKern.mpkKernel = clCreateKernel(histRedKern.mpkProgram,
                                           "kernel_HistogramRectOneChannelReduction", &clStatus);
    CHECK_OPENCL(clStatus, "clCreateKernel kernel_HistogramRectOneChannelReduction");
  } else {
    histKern.mpkKernel =
        clCreateKernel(histKern.mpkProgram, "kernel_HistogramRectAllChannels", &clStatus);
    CHECK_OPENCL(clStatus, "clCreateKernel kernel_HistogramRectAllChannels");

    histRedKern.mpkKernel = clCreateKernel(histRedKern.mpkProgram,
                                           "kernel_HistogramRectAllChannelsReduction", &clStatus);
    CHECK_OPENCL(clStatus, "clCreateKernel kernel_HistogramRectAllChannelsReduction");
  }

  void *ptr;

  // Initialize tmpHistogramBuffer buffer
  ptr = clEnqueueMapBuffer(histKern.mpkCmdQueue, tmpHistogramBuffer, CL_TRUE, CL_MAP_WRITE, 0,
                           tmpHistogramBins * sizeof(cl_uint), 0, nullptr, nullptr, &clStatus);
  CHECK_OPENCL(clStatus, "clEnqueueMapBuffer tmpHistogramBuffer");

  memset(ptr, 0, tmpHistogramBins * sizeof(cl_uint));
  clEnqueueUnmapMemObject(histKern.mpkCmdQueue, tmpHistogramBuffer, ptr, 0, nullptr, nullptr);

  /* set kernel 1 arguments */
  clStatus = clSetKernelArg(histKern.mpkKernel, 0, sizeof(cl_mem), &imageBuffer);
  CHECK_OPENCL(clStatus, "clSetKernelArg imageBuffer");
  cl_uint numPixels = width * height;
  clStatus = clSetKernelArg(histKern.mpkKernel, 1, sizeof(cl_uint), &numPixels);
  CHECK_OPENCL(clStatus, "clSetKernelArg numPixels");
  clStatus = clSetKernelArg(histKern.mpkKernel, 2, sizeof(cl_mem), &tmpHistogramBuffer);
  CHECK_OPENCL(clStatus, "clSetKernelArg tmpHistogramBuffer");

  /* set kernel 2 arguments */
  int n = numThreads / bytes_per_pixel;
  clStatus = clSetKernelArg(histRedKern.mpkKernel, 0, sizeof(cl_int), &n);
  CHECK_OPENCL(clStatus, "clSetKernelArg imageBuffer");
  clStatus = clSetKernelArg(histRedKern.mpkKernel, 1, sizeof(cl_mem), &tmpHistogramBuffer);
  CHECK_OPENCL(clStatus, "clSetKernelArg tmpHistogramBuffer");
  clStatus = clSetKernelArg(histRedKern.mpkKernel, 2, sizeof(cl_mem), &histogramBuffer);
  CHECK_OPENCL(clStatus, "clSetKernelArg histogramBuffer");

  /* launch histogram */
  clStatus = clEnqueueNDRangeKernel(histKern.mpkCmdQueue, histKern.mpkKernel, 1, nullptr,
                                    global_work_size, local_work_size, 0, nullptr, nullptr);
  CHECK_OPENCL(clStatus, "clEnqueueNDRangeKernel kernel_HistogramRectAllChannels");
  clFinish(histKern.mpkCmdQueue);
  if (clStatus != 0) {
    retVal = -1;
  }
  /* launch histogram */
  clStatus = clEnqueueNDRangeKernel(histRedKern.mpkCmdQueue, histRedKern.mpkKernel, 1, nullptr,
                                    red_global_work_size, local_work_size, 0, nullptr, nullptr);
  CHECK_OPENCL(clStatus, "clEnqueueNDRangeKernel kernel_HistogramRectAllChannelsReduction");
  clFinish(histRedKern.mpkCmdQueue);
  if (clStatus != 0) {
    retVal = -1;
  }

  /* map results back from gpu */
  ptr = clEnqueueMapBuffer(histRedKern.mpkCmdQueue, histogramBuffer, CL_TRUE, CL_MAP_READ, 0,
                           kHistogramSize * bytes_per_pixel * sizeof(int), 0, nullptr, nullptr,
                           &clStatus);
  CHECK_OPENCL(clStatus, "clEnqueueMapBuffer histogramBuffer");
  if (clStatus != 0) {
    retVal = -1;
  }
  clEnqueueUnmapMemObject(histRedKern.mpkCmdQueue, histogramBuffer, ptr, 0, nullptr, nullptr);

  clReleaseMemObject(histogramBuffer);
  clReleaseMemObject(imageBuffer);
  return retVal;
}