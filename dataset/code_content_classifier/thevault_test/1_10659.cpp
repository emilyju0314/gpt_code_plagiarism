static cl_int pixDilateCL(l_int32 hsize, l_int32 vsize, l_int32 wpl, l_int32 h) {
  l_int32 xp, yp, xn, yn;
  SEL *sel;
  size_t globalThreads[2];
  cl_mem pixtemp;
  cl_int status = 0;
  int gsize;
  size_t localThreads[2];
  char isEven;

  OpenclDevice::SetKernelEnv(&rEnv);

  if (hsize == 5 && vsize == 5) {
    // Specific case for 5x5
    status = pixDilateCL_55(wpl, h);
    return status;
  }

  sel = selCreateBrick(vsize, hsize, vsize / 2, hsize / 2, SEL_HIT);

  selFindMaxTranslations(sel, &xp, &yp, &xn, &yn);
  selDestroy(&sel);
  // global and local work dimensions for Horizontal pass
  gsize = (wpl + GROUPSIZE_X - 1) / GROUPSIZE_X * GROUPSIZE_X;
  globalThreads[0] = gsize;
  gsize = (h + GROUPSIZE_Y - 1) / GROUPSIZE_Y * GROUPSIZE_Y;
  globalThreads[1] = gsize;
  localThreads[0] = GROUPSIZE_X;
  localThreads[1] = GROUPSIZE_Y;

  if (xp > 31 || xn > 31) {
    // Generic case.
    rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "morphoDilateHor", &status);
    CHECK_OPENCL(status, "clCreateKernel morphoDilateHor");

    status = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &pixsCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(cl_mem), &pixdCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(xp), &xp);
    status = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(xn), &xn);
    status = clSetKernelArg(rEnv.mpkKernel, 4, sizeof(wpl), &wpl);
    status = clSetKernelArg(rEnv.mpkKernel, 5, sizeof(h), &h);
    status = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 2, nullptr, globalThreads,
                                    localThreads, 0, nullptr, nullptr);

    if (yp > 0 || yn > 0) {
      pixtemp = pixsCLBuffer;
      pixsCLBuffer = pixdCLBuffer;
      pixdCLBuffer = pixtemp;
    }
  } else if (xp > 0 || xn > 0) {
    // Specific Horizontal pass kernel for half width < 32
    rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "morphoDilateHor_32word", &status);
    CHECK_OPENCL(status, "clCreateKernel morphoDilateHor_32word");
    isEven = (xp != xn);

    status = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &pixsCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(cl_mem), &pixdCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(xp), &xp);
    status = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(wpl), &wpl);
    status = clSetKernelArg(rEnv.mpkKernel, 4, sizeof(h), &h);
    status = clSetKernelArg(rEnv.mpkKernel, 5, sizeof(isEven), &isEven);
    status = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 2, nullptr, globalThreads,
                                    localThreads, 0, nullptr, nullptr);

    if (yp > 0 || yn > 0) {
      pixtemp = pixsCLBuffer;
      pixsCLBuffer = pixdCLBuffer;
      pixdCLBuffer = pixtemp;
    }
  }

  if (yp > 0 || yn > 0) {
    rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "morphoDilateVer", &status);
    CHECK_OPENCL(status, "clCreateKernel morphoDilateVer");

    status = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &pixsCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(cl_mem), &pixdCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(yp), &yp);
    status = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(wpl), &wpl);
    status = clSetKernelArg(rEnv.mpkKernel, 4, sizeof(h), &h);
    status = clSetKernelArg(rEnv.mpkKernel, 5, sizeof(yn), &yn);
    status = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 2, nullptr, globalThreads,
                                    localThreads, 0, nullptr, nullptr);
  }

  return status;
}