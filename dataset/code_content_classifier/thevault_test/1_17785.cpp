FlutterRendererConfig GetSoftwareRendererConfig() {
  FlutterRendererConfig config = {};
  config.type = kSoftware;
  config.software.struct_size = sizeof(config.software);
  config.software.surface_present_callback = [](void* user_data,
                                                const void* allocation,
                                                size_t row_bytes,
                                                size_t height) {
    auto host = static_cast<FlutterWindowsEngine*>(user_data);
    if (!host->view()) {
      return false;
    }
    return host->view()->PresentSoftwareBitmap(allocation, row_bytes, height);
  };
  return config;
}