static cl_int pixDilateCL_55(l_int32 wpl, l_int32 h) {
  size_t globalThreads[2];
  cl_mem pixtemp;
  cl_int status;
  int gsize;
  size_t localThreads[2];

  // Horizontal pass
  gsize = (wpl * h + GROUPSIZE_HMORX - 1) / GROUPSIZE_HMORX * GROUPSIZE_HMORX;
  globalThreads[0] = gsize;
  globalThreads[1] = GROUPSIZE_HMORY;
  localThreads[0] = GROUPSIZE_HMORX;
  localThreads[1] = GROUPSIZE_HMORY;

  rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "morphoDilateHor_5x5", &status);
  CHECK_OPENCL(status, "clCreateKernel morphoDilateHor_5x5");

  status = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &pixsCLBuffer);
  status = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(cl_mem), &pixdCLBuffer);
  status = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(wpl), &wpl);
  status = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(h), &h);

  status = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 2, nullptr, globalThreads,
                                  localThreads, 0, nullptr, nullptr);

  // Swap source and dest buffers
  pixtemp = pixsCLBuffer;
  pixsCLBuffer = pixdCLBuffer;
  pixdCLBuffer = pixtemp;

  // Vertical
  gsize = (wpl + GROUPSIZE_X - 1) / GROUPSIZE_X * GROUPSIZE_X;
  globalThreads[0] = gsize;
  gsize = (h + GROUPSIZE_Y - 1) / GROUPSIZE_Y * GROUPSIZE_Y;
  globalThreads[1] = gsize;
  localThreads[0] = GROUPSIZE_X;
  localThreads[1] = GROUPSIZE_Y;

  rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "morphoDilateVer_5x5", &status);
  CHECK_OPENCL(status, "clCreateKernel morphoDilateVer_5x5");

  status = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &pixsCLBuffer);
  status = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(cl_mem), &pixdCLBuffer);
  status = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(wpl), &wpl);
  status = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(h), &h);
  status = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 2, nullptr, globalThreads,
                                  localThreads, 0, nullptr, nullptr);

  return status;
}