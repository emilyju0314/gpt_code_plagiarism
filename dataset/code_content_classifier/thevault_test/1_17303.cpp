bool CanUseGpuDevice(Operation *op) {
  auto device_attr = op->getAttrOfType<StringAttr>("device");
  if (!device_attr || device_attr.getValue().empty()) return true;

  DeviceNameUtils::ParsedName device;
  if (!DeviceNameUtils::ParseFullName(device_attr.getValue().str(), &device))
    return false;

  // We can't use GPU if operation explicitly placed on non-GPU device.
  return !device.has_type || device.type == ::tensorflow::DEVICE_GPU;
}