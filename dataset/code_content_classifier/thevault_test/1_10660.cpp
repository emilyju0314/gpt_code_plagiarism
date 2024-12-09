static cl_int pixErodeCL(l_int32 hsize, l_int32 vsize, l_uint32 wpl, l_uint32 h) {
  l_int32 xp, yp, xn, yn;
  SEL *sel;
  size_t globalThreads[2];
  size_t localThreads[2];
  cl_mem pixtemp;
  cl_int status = 0;
  int gsize;
  char isAsymmetric = (MORPH_BC == ASYMMETRIC_MORPH_BC);
  l_uint32 rwmask, lwmask;
  char isEven;

  sel = selCreateBrick(vsize, hsize, vsize / 2, hsize / 2, SEL_HIT);

  selFindMaxTranslations(sel, &xp, &yp, &xn, &yn);
  selDestroy(&sel);
  OpenclDevice::SetKernelEnv(&rEnv);

  if (hsize == 5 && vsize == 5 && isAsymmetric) {
    // Specific kernel for 5x5
    status = pixErodeCL_55(wpl, h);
    return status;
  }

  lwmask = lmask32[31 - (xn & 31)];
  rwmask = rmask32[31 - (xp & 31)];

  // global and local work dimensions for Horizontal pass
  gsize = (wpl + GROUPSIZE_X - 1) / GROUPSIZE_X * GROUPSIZE_X;
  globalThreads[0] = gsize;
  gsize = (h + GROUPSIZE_Y - 1) / GROUPSIZE_Y * GROUPSIZE_Y;
  globalThreads[1] = gsize;
  localThreads[0] = GROUPSIZE_X;
  localThreads[1] = GROUPSIZE_Y;

  // Horizontal Pass
  if (xp > 31 || xn > 31) {
    // Generic case.
    rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "morphoErodeHor", &status);

    status = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &pixsCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(cl_mem), &pixdCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(xp), &xp);
    status = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(xn), &xn);
    status = clSetKernelArg(rEnv.mpkKernel, 4, sizeof(wpl), &wpl);
    status = clSetKernelArg(rEnv.mpkKernel, 5, sizeof(h), &h);
    status = clSetKernelArg(rEnv.mpkKernel, 6, sizeof(isAsymmetric), &isAsymmetric);
    status = clSetKernelArg(rEnv.mpkKernel, 7, sizeof(rwmask), &rwmask);
    status = clSetKernelArg(rEnv.mpkKernel, 8, sizeof(lwmask), &lwmask);
    status = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 2, nullptr, globalThreads,
                                    localThreads, 0, nullptr, nullptr);

    if (yp > 0 || yn > 0) {
      pixtemp = pixsCLBuffer;
      pixsCLBuffer = pixdCLBuffer;
      pixdCLBuffer = pixtemp;
    }
  } else if (xp > 0 || xn > 0) {
    rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "morphoErodeHor_32word", &status);
    isEven = (xp != xn);

    status = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &pixsCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(cl_mem), &pixdCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(xp), &xp);
    status = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(wpl), &wpl);
    status = clSetKernelArg(rEnv.mpkKernel, 4, sizeof(h), &h);
    status = clSetKernelArg(rEnv.mpkKernel, 5, sizeof(isAsymmetric), &isAsymmetric);
    status = clSetKernelArg(rEnv.mpkKernel, 6, sizeof(rwmask), &rwmask);
    status = clSetKernelArg(rEnv.mpkKernel, 7, sizeof(lwmask), &lwmask);
    status = clSetKernelArg(rEnv.mpkKernel, 8, sizeof(isEven), &isEven);
    status = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 2, nullptr, globalThreads,
                                    localThreads, 0, nullptr, nullptr);

    if (yp > 0 || yn > 0) {
      pixtemp = pixsCLBuffer;
      pixsCLBuffer = pixdCLBuffer;
      pixdCLBuffer = pixtemp;
    }
  }

  // Vertical Pass
  if (yp > 0 || yn > 0) {
    rEnv.mpkKernel = clCreateKernel(rEnv.mpkProgram, "morphoErodeVer", &status);
    CHECK_OPENCL(status, "clCreateKernel morphoErodeVer");

    status = clSetKernelArg(rEnv.mpkKernel, 0, sizeof(cl_mem), &pixsCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 1, sizeof(cl_mem), &pixdCLBuffer);
    status = clSetKernelArg(rEnv.mpkKernel, 2, sizeof(yp), &yp);
    status = clSetKernelArg(rEnv.mpkKernel, 3, sizeof(wpl), &wpl);
    status = clSetKernelArg(rEnv.mpkKernel, 4, sizeof(h), &h);
    status = clSetKernelArg(rEnv.mpkKernel, 5, sizeof(isAsymmetric), &isAsymmetric);
    status = clSetKernelArg(rEnv.mpkKernel, 6, sizeof(yn), &yn);
    status = clEnqueueNDRangeKernel(rEnv.mpkCmdQueue, rEnv.mpkKernel, 2, nullptr, globalThreads,
                                    localThreads, 0, nullptr, nullptr);
  }

  return status;
}