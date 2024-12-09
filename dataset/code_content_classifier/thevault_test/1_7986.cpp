void* DeviceIntf::syncTraceBuf(size_t bufHandle, uint64_t offset, uint64_t bytes)
  {
    auto addr = mDevice->map(bufHandle);
    if (!addr)
      return nullptr;
    mDevice->sync(bufHandle, bytes, offset, xdp::Device::direction::DEVICE2HOST);
    return static_cast<char*>(addr) + offset;
  }