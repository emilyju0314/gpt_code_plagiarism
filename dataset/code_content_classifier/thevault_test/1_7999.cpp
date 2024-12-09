static uint16_t
str2index(const std::string& str, bool _inUserDomain)
{
  //throw an error if no devices are present
  uint64_t devices = _inUserDomain ? xrt_core::get_total_devices(true).first : xrt_core::get_total_devices(false).first;
  if(devices == 0) 
    throw std::runtime_error("No devices found");

  uint16_t idx = 0;
  auto device = _inUserDomain ? xrt_core::get_userpf_device(idx) : xrt_core::get_mgmtpf_device(idx);
  auto bdf = xrt_core::device_query<xrt_core::query::pcie_bdf>(device);
  // if the bdf is zero, we are dealing with an edge device
  if(std::get<0>(bdf) == 0 && std::get<1>(bdf) == 0 && std::get<2>(bdf) == 0) {
    return deviceId2index();
  }
  else {
    return bdf2index(str, _inUserDomain);
  }
}