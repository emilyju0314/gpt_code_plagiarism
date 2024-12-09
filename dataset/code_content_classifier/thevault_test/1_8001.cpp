static int createSoftKernel(unsigned int *boh, uint32_t cu_idx)
{
  int ret;

  *boh = xclAllocBO(devHdl, SOFT_KERNEL_REG_SIZE, 0, 0);
  if (*boh == 0xFFFFFFFF) {
    syslog(LOG_ERR, "Cannot alloc bo for soft kernel.\n");
    return -1;
  }

  ret = xclSKCreate(devHdl, *boh, cu_idx);

  return ret;
}