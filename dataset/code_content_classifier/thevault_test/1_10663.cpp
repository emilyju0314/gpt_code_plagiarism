void OpenclDevice::pixGetLinesCL(Image pixd, Image pixs, Image *pix_vline, Image *pix_hline,
                                 Image *pixClosed, bool getpixClosed, l_int32 close_hsize,
                                 l_int32 close_vsize, l_int32 open_hsize, l_int32 open_vsize,
                                 l_int32 line_hsize, l_int32 line_vsize) {
  l_uint32 wpl, h;
  cl_mem pixtemp;

  wpl = pixGetWpl(pixs);
  h = pixGetHeight(pixs);

  // First step : Close Morph operation: Dilate followed by Erode
  clStatus = pixCloseCL(close_hsize, close_vsize, wpl, h);

  // Copy the Close output to CPU buffer
  if (getpixClosed) {
    *pixClosed =
        mapOutputCLBuffer(rEnv, pixdCLBuffer, *pixClosed, pixs, wpl * h, CL_MAP_READ, true, false);
  }

  // Store the output of close operation in an intermediate buffer
  // this will be later used for pixsubtract
  clStatus = clEnqueueCopyBuffer(rEnv.mpkCmdQueue, pixdCLBuffer, pixdCLIntermediate, 0, 0,
                                 sizeof(int) * wpl * h, 0, nullptr, nullptr);

  // Second step: Open Operation - Erode followed by Dilate
  pixtemp = pixsCLBuffer;
  pixsCLBuffer = pixdCLBuffer;
  pixdCLBuffer = pixtemp;

  clStatus = pixOpenCL(open_hsize, open_vsize, wpl, h);

  // Third step: Subtract : (Close - Open)
  pixtemp = pixsCLBuffer;
  pixsCLBuffer = pixdCLBuffer;
  pixdCLBuffer = pixdCLIntermediate;
  pixdCLIntermediate = pixtemp;

  clStatus = pixSubtractCL_work(wpl, h, pixdCLBuffer, pixsCLBuffer);

  // Store the output of Hollow operation in an intermediate buffer
  // this will be later used
  clStatus = clEnqueueCopyBuffer(rEnv.mpkCmdQueue, pixdCLBuffer, pixdCLIntermediate, 0, 0,
                                 sizeof(int) * wpl * h, 0, nullptr, nullptr);

  pixtemp = pixsCLBuffer;
  pixsCLBuffer = pixdCLBuffer;
  pixdCLBuffer = pixtemp;

  // Fourth step: Get vertical line
  // pixOpenBrick(nullptr, pix_hollow, 1, min_line_length);
  clStatus = pixOpenCL(1, line_vsize, wpl, h);

  // Copy the vertical line output to CPU buffer
  *pix_vline =
      mapOutputCLBuffer(rEnv, pixdCLBuffer, *pix_vline, pixs, wpl * h, CL_MAP_READ, true, false);

  pixtemp = pixsCLBuffer;
  pixsCLBuffer = pixdCLIntermediate;
  pixdCLIntermediate = pixtemp;

  // Fifth step: Get horizontal line
  // pixOpenBrick(nullptr, pix_hollow, min_line_length, 1);
  clStatus = pixOpenCL(line_hsize, 1, wpl, h);

  // Copy the horizontal line output to CPU buffer
  *pix_hline =
      mapOutputCLBuffer(rEnv, pixdCLBuffer, *pix_hline, pixs, wpl * h, CL_MAP_READ, true, true);

  return;
}