int xclIPName2Index(xclDeviceHandle handle, const char *name)
{
  xclcpuemhal2::CpuemShim *drv = xclcpuemhal2::CpuemShim::handleCheck(handle);
  return drv ? drv->xclIPName2Index(name) : -ENODEV;
}