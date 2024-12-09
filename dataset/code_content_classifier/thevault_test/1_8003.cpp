static int createSoftKernelFile(uint64_t paddr, size_t size, uint32_t cuidx)
{
  xclDeviceHandle handle;
  unsigned int boHandle;
  FILE *fptr;
  void *buf;
  char path[XRT_MAX_PATH_LENGTH];
  int len, i;

  handle = initXRTHandle(0);
  if (!handle) {
    syslog(LOG_ERR, "Cannot initialize XRT.\n");
    return -1;
  }

  boHandle = xclGetHostBO(handle, paddr, size);
  buf = xclMapBO(handle, boHandle, false);
  if (!buf) {
    syslog(LOG_ERR, "Cannot map xlcbin BO.\n");
    return -1;
  }

  snprintf(path, XRT_MAX_PATH_LENGTH, "%s", SOFT_KERNEL_FILE_PATH);
  len = strlen(path);

  /* If not exist, create the path one by one. */
  for (i = 1; i < len; i++) {
    if (path[i] == '/') {
      path[i] = '\0';
      if (access(path, F_OK) != 0) {
        if (mkdir(path, 0744) != 0) {
          syslog(LOG_ERR, "Cannot create soft kernel file.\n");
          return -1;
        }
      }
      path[i] = '/';
    }
  }

  /* Create soft kernel file */
  getSoftKernelPathName(cuidx, path);

  fptr = fopen(path, "w+b");
  if (fptr == NULL) {
     syslog(LOG_ERR, "Cannot create file: %s\n", path);
     return -1;
  }

  /* copy the soft kernel to file */
  if (fwrite(buf, size, 1, fptr) != 1) {
    syslog(LOG_ERR, "Fail to write to file %s.\n", path);
    fclose(fptr);
    return -1;
  }

  fclose(fptr);
  xclClose(handle);

  return 0;
}