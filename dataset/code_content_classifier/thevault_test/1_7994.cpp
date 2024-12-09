int
xrtXclbinUUID(xclDeviceHandle dhdl, xuid_t out)
{
  try {
    auto device = xrt_core::get_userpf_device(dhdl);
    auto uuid = device->get_xclbin_uuid();
    uuid_copy(out, uuid.get());
    return 0;
  }
  catch (const xrt_core::error& ex) {
    xrt_core::send_exception_message(ex.what());
    return ex.get();
  }
  catch (const std::exception& ex) {
    xrt_core::send_exception_message(ex.what());
    return -1;
  }
}