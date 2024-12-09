static void softKernelLoop(char *name, char *path, uint32_t cu_idx)
{
  void *sk_handle;
  kernel_t kernel;
  struct sk_operations ops;
  uint32_t *args_from_host;
  int32_t kernel_return;
  unsigned int boh;
  int ret;

  devHdl = initXRTHandle(0);

  ret = createSoftKernel(&boh, cu_idx);
  if (ret) {
    syslog(LOG_ERR, "Cannot create soft kernel.");
    return;
  }

  /* Open and load the soft kernel. */
  sk_handle = dlopen(path, RTLD_LAZY | RTLD_GLOBAL);
  if (!sk_handle) {
    syslog(LOG_ERR, "Cannot open %s\n", path);
    return;
  }

  kernel = (kernel_t)dlsym(sk_handle, name);
  if (!kernel) {
    syslog(LOG_ERR, "Cannot find kernel %s\n", name);
    return;
  }

  syslog(LOG_INFO, "%s_%d start running\n", name, cu_idx);

  /* Set Kernel Ops */
  ops.getHostBO     = &getHostBO;
  ops.mapBO         = &mapBO;
  ops.freeBO        = &freeBO;
  ops.getBufferFd   = &getBufferFd;
  ops.logMsg        = &logMsg;

  args_from_host = (unsigned *)getKernelArg(boh, cu_idx);
  if (args_from_host == MAP_FAILED) {
      syslog(LOG_ERR, "Failed to map soft kernel args for %s_%d", name, cu_idx);
      freeBO(boh);
      dlclose(sk_handle);
      return;
  }

  while (1) {
    ret = waitNextCmd(cu_idx);

    if (ret) {
      /* We are told to exit the soft kernel loop */
      syslog(LOG_INFO, "Exit soft kernel %s\n", name);
      break;
    }

    /* Reg file indicates the kernel should not be running. */
    if (!(args_from_host[0] & 0x1))
      continue; //AP_START bit is not set; New Cmd is not available

    /* Start run the soft kernel. */
    kernel_return = kernel(&args_from_host[1], &ops);
    args_from_host[1] = (uint32_t)kernel_return;
  }

  dlclose(sk_handle);
  (void) destroySoftKernel(boh, args_from_host);
}