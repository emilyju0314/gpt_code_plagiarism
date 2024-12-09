static cl_int pixCloseCL(l_int32 hsize, l_int32 vsize, l_int32 wpl, l_int32 h) {
  cl_int status;
  cl_mem pixtemp;

  // Dilate followed by Erode
  status = pixDilateCL(hsize, vsize, wpl, h);

  pixtemp = pixsCLBuffer;
  pixsCLBuffer = pixdCLBuffer;
  pixdCLBuffer = pixtemp;

  status = pixErodeCL(hsize, vsize, wpl, h);

  return status;
}