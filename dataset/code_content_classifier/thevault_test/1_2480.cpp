void GPU_Device::printDeviceSummary(int const idevice, std::ostream &out) const {
  out << "Device: " << idevice << "\n   Name               : " << deviceName[idevice]
      << "\n   Compute capability : " << computeCapability[idevice][0] << "."
      << computeCapability[idevice][1]
      << "\n   maxThreadsPerBlock : " << maxThreadsPerBlock(idevice)
      << "\n   maxThreadsDim      : " << maxThreadsDim(0, idevice) << " x "
      << maxThreadsDim(1, idevice) << " x " << maxThreadsDim(2, idevice)
      << "\n   maxGridSize        : " << maxGridSize(0, idevice) << " x " << maxGridSize(1, idevice)
      << " x " << maxGridSize(2, idevice)
      << "\n   sharedMemPerBlock  : " << sharedMemPerBlock(idevice)
      << "\n   totalConstantMemory: " << totalConstantMemory(idevice)
      << "\n   SIMDWidth          : " << SIMDWidth(idevice)
      << "\n   memPitch           : " << memPitch(idevice)
      << "\n   regsPerBlock       : " << regsPerBlock(idevice)
      << "\n   clockRate          : " << clockRate(idevice)
      << "\n   textureAlign       : " << textureAlign(idevice) << "\n"
      << std::endl;
  return;
}