bool CanUseTensorCores(const RuntimeDevices &devices) {
  auto has_tensor_cores = [&](const DeviceNameUtils::ParsedName &device) {
    auto md = devices.GetGpuDeviceMetadata(device);
    return md ? md->cc_major().getInt() >= 7 : false;
  };
  return llvm::all_of(
      llvm::make_filter_range(devices.device_names(), IsGpuDevice),
      has_tensor_cores);
}